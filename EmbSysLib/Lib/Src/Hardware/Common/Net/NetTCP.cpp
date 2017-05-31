//extern cDevComUART    com;

//*******************************************************************
//
// cNetTCP
//
//*******************************************************************
//-------------------------------------------------------------------
cNetTCP::cNetTCP( cNetIP   &ipIn )

: cNetTransport( ),
  ip( ipIn )

{
  ip.arp.setTCP( this );
  ip.setTCP( this );
}

//-------------------------------------------------------------------
void cNetTCP::create( Socket &con, WORD payloadLen )
{
   cNetTCP_Msg &msg = *(cNetTCP_Msg*)ip.eth.buf;

   msg.tcp.sourcePort        = con.myPort;
   msg.tcp.destPort          = con.remotePort;
   msg.tcp.sequenceNumber    = con.seqNum;
   msg.tcp.acknowledgeNumber = con.ackNum;
   msg.tcp.setFlags( con.flags );
   msg.tcp.windowSize        = 1000;
   msg.tcp.urgentPointer     = 0;

   if (con.mss > 0 )
   {
      // the only option we set is MSS to 1408:
      // 1408 in hex is 0x580
     //< \todo An echte Größe anpassen !!!
      ip.eth.buf[ sizeof( cNetTCP_Msg)    ] = 2;
      ip.eth.buf[ sizeof( cNetTCP_Msg) + 1] = 4;
      ip.eth.buf[ sizeof( cNetTCP_Msg) + 2] = 0x05;
      ip.eth.buf[ sizeof( cNetTCP_Msg) + 3] = 0x80;
      payloadLen += 4;

      msg.tcp.setDataOffset( 24 );
   }
   else
   {
      msg.tcp.setDataOffset( 20 );
   }

   ip.create( con.addrPhy,
              con.addr,
              payloadLen,
              cNetIP::PROTOCOL_TCP );

   // Calculate checksum:
   WORD  len = sizeof( cNetTCP_Header) + payloadLen;

   msg.tcp.checksum = 0;
   msg.tcp.checksum = Checksum( (BYTE*)&msg.ip.sourceAddr,
                                 len + 8,
                                 (DWORD)len + cNetIP::PROTOCOL_TCP );

   ip.eth.PacketSend(  ip.eth.buf,
                       sizeof( cNetTCP_Msg) + payloadLen );
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
cNetTCP::Socket::Socket( cNetTCP         &tcpIn,
                         cNetApplication &appIn,
                         cNetAddr<4>      inAddrIn,
                         WORD             portIn,
                         WORD             updateTime )

: cNetTransport::Socket( (cNetTransport &)tcpIn,
                         appIn,
                         inAddrIn,
                         portIn,
                         updateTime ),
  tcp( tcpIn )

{
  initialSeqNum = 10000; //0x1000; // my initial tcp sequence number
}

//-------------------------------------------------------------------
void cNetTCP::Socket::open( cNetAddr<4> addrIn,
                            WORD        portIn )
{
  remotePort  = portIn;
  flags = cNetTCP::FLAG_SYN;

  seqNum = initialSeqNum;
  initialSeqNum += 10000; // step the inititial seq num by something we will not use during this tcp session:

  ackNum = 0;

  dataLen = 0;

  mss = true;

  if( addr == addrIn && !(addrPhy == zeroAddrPhy))
  {
    state = STATE_OPEN_WAIT_SERVER;
    clear();
    tcp.create( *this, tcp.ip.eth.plen );
    setTimeout( 3 );
  }
  else if( !(addr == broadcastAddr) )
  {
    state = STATE_OPEN_WAIT_ARP;
    addr = addrIn;
    clear();
    tcp.ip.arp.request( addr );
    setTimeout( 6 );
  }
}

//-------------------------------------------------------------------
void cNetTCP::Socket::close( void )
{
  if( state != STATE_FINISHING )
  {
    state  = STATE_FINISHING;

    flags  = cNetTCP::FLAG_FIN | cNetTCP::FLAG_ACK;

    tcp.create( *this, tcp.ip.eth.plen );
    seqNum += tcp.ip.eth.plen; //tcp.send_local( *this );
    setTimeout( 3 );

    clear();
  }
}

//-------------------------------------------------------------------
BYTE cNetTCP::Socket::isConnected( void )
{
  return(    state == STATE_CONNECTED
          || state == STATE_CONNECTED_WAIT_ACK );
}

//-------------------------------------------------------------------
BYTE cNetTCP::Socket::isReady( void )
{
  return(    !(tcp.ip.addr == zeroAddr)
          &&   state == STATE_WAITING );
}

//-------------------------------------------------------------------
void cNetTCP::Socket::clear( void )
{
  tcp.ip.eth.plen = 0;
}

//-------------------------------------------------------------------
void cNetTCP::Socket::fillBuffer( const char c )
{
  WORD pos = sizeof( cNetTCP_Msg ) + tcp.ip.eth.plen;

  if( pos < BUFFER_SIZE )
  {
    tcp.ip.eth.buf[pos] = c;
    tcp.ip.eth.plen++;
  }

  if( pos + 1 >= BUFFER_SIZE )
  {
    send();
  }
}

//-------------------------------------------------------------------
void cNetTCP::Socket::send( void )
{
  tcp.create( *this, tcp.ip.eth.plen );
  seqNum += tcp.ip.eth.plen;

  setTimeout( 3 );
  ackNumExpected = seqNum;
  state = STATE_CONNECTED_WAIT_ACK;
  clear( );
}

//-------------------------------------------------------------------
BYTE cNetTCP::Socket::get( char *c )
{
  if( tcp.inPos < tcp.inBufLen )
  {
    *c = tcp.buf[tcp.inPos++];
    return( true );
  }
  return( false );
}

//-------------------------------------------------------------------
BYTE *cNetTCP::Socket::getDataPtr( void )
{
  return( (BYTE*)&tcp.ip.eth.buf[ sizeof(cNetTCP_Msg) ] );
}

//-------------------------------------------------------------------
void cNetTCP::Socket::setDataLength( WORD len )
{
  tcp.ip.eth.plen = len;
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
BYTE cNetTCP::Socket::process( void )
{
  cNetTCP_Msg &msg = *(cNetTCP_Msg*)tcp.ip.eth.buf;

  WORD  flagsMsg   = msg.tcp.getFlags();
  DWORD ackNumMsg  = msg.tcp.acknowledgeNumber;
  DWORD seqNumMsg  = msg.tcp.sequenceNumber;

  WORD dataLen =   msg.ip.packetLength
                 - sizeof(cNetIP_Header)
                 - msg.tcp.getDataOffset();

  BYTE *dataPtr = NULL;

  if( dataLen > 0 )
  {
    WORD idx = sizeof( cNetIP_Msg ) + msg.tcp.getDataOffset();
    if( idx > 0 )
    {
      dataPtr = &tcp.ip.eth.buf[ idx ];
    }
  }

  //  clear(); /// ??? plen is used later !
  tcp.ip.eth.plen = 0;

  if( !(myPort == msg.tcp.destPort) )
  {
    return( false );
  }

  if( flagsMsg & cNetTCP::FLAG_RST )
  {
    state = STATE_WAITING;
    mss   = false;
    return( true );
  }

  switch( state )
  {
    case STATE_WAITING:
      if( flagsMsg & cNetTCP::FLAG_SYN )
      {
        state   = Socket::STATE_PENDING;
        addr    = msg.ip.sourceAddr;
        remotePort    = msg.tcp.sourcePort;
        addrPhy = msg.eth.sourceAddr;
        flags   = cNetTCP::FLAG_SYN | cNetTCP::FLAG_ACK;
        mss     = true;

        initialSeqNum += 10000; // step the inititial seq num by something we will not use during this tcp session:

        seqNum = initialSeqNum;
        ackNum = seqNumMsg + 1;

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 3 );
        return( true) ;
      }
      break;

    case STATE_PENDING:
      if( flagsMsg & cNetTCP::FLAG_ACK )
      {
        state = STATE_CONNECTED;
        mss   = false;
      }
      seqNum = seqNum + 1;
      ackNum = seqNumMsg  + 1;
      break;

    case STATE_OPEN_WAIT_SERVER:
      if( flagsMsg & cNetTCP::FLAG_ACK )
      {
        state  = STATE_CONNECTED;
        mss    = false;
        flags  = cNetTCP::FLAG_ACK;
        seqNum = seqNum + 1;
        ackNum = seqNumMsg  + 1;

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 0 );
        return( true );
      }
      break;

    case STATE_CONNECTED:
      if( flagsMsg & cNetTCP::FLAG_FIN )
      {
        state  = Socket::STATE_FINISHING;
        flags  = cNetTCP::FLAG_FIN | cNetTCP::FLAG_ACK;
        seqNum = ackNumMsg;
        ackNum = seqNumMsg + dataLen;
        tcp.ip.eth.plen = 0;      // ???

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 3 );
        return( true );
      }
      else
      {
        state  = Socket::STATE_CONNECTED_WAIT_ACK;

        flags = cNetTCP::FLAG_ACK;
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
//      com.printf("\r\n1 a:%u s:%u d:%u\r\n", ackNumMsg, seqNumMsg,  dataLen );
      break;

    case STATE_CONNECTED_WAIT_ACK:
      if(   ( flagsMsg & cNetTCP::FLAG_ACK )
           && ackNumMsg == ackNumExpected  )
      {
        state = STATE_CONNECTED;
        flags = cNetTCP::FLAG_NONE;
  //      com.printf("\r\n21" );
      }
else
{
//        com.printf("\r\n22" );
}
  if( dataLen > 0 )
      {
        flags = cNetTCP::FLAG_ACK;
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
//      com.printf("\r\n2 a:%u s:%u d:%u\r\n", ackNumMsg, seqNumMsg,  dataLen );
      break;

    case STATE_FINISHING:
      if( flagsMsg & cNetTCP::FLAG_FIN )
      {
        state  = STATE_WAITING;
        flags  = cNetTCP::FLAG_ACK;
        seqNum = ackNumMsg + 1;
        ackNum = seqNumMsg + dataLen + 1;

        tcp.create( *this, tcp.ip.eth.plen );
        setTimeout( 3 );
        return( true );
      }
      seqNum = ackNumMsg;
      ackNum = seqNumMsg + dataLen;
      break;
  } // switch

  if( dataLen > 0 )
  {
    seqNum = ackNumMsg;
    ackNum = seqNumMsg + dataLen;

    tcp.buf = dataPtr;
    tcp.inPos = 0;
    tcp.inBufLen = dataLen;

    app.process();
  }

  return( true );
}

//-------------------------------------------------------------------
void cNetTCP::Socket::update( void )
{
  if(      state   == STATE_OPEN_WAIT_ARP
      && !(addrPhy == zeroAddrPhy) )
  {
    clear( );
    tcp.create( *this, tcp.ip.eth.plen );
    setTimeout( 3 );
    state = STATE_OPEN_WAIT_SERVER;
  }
}

//-------------------------------------------------------------------
void cNetTCP::Socket::timeout( void )
{
  if( timeOutTic && !(--timeOutTic) )
  {
    app.timeout();

    switch( state )
    {
      case STATE_PENDING:
      case STATE_OPEN_WAIT_SERVER:
      case STATE_OPEN_WAIT_ARP:
      case STATE_CONNECTED_WAIT_ACK:
      case STATE_FINISHING:

        state = STATE_WAITING;
        break;
    }
  }

  if( updateTic && !(--updateTic) )
  {
    updateTic = updateTime;
    app.update();
  }
}

//-------------------------------------------------------------------
void cNetTCP::handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy )
{
  Socket *ptr = (Socket *)appList.getFirst();
  while( ptr )
  {
    if(    ptr->addr == addr
        && (   ptr->state == Socket::STATE_WAITING
            || ptr->state == Socket::STATE_OPEN_WAIT_ARP ) )
    {
      ptr->addrPhy = addrPhy;
    }
    ptr = (Socket *)ptr->getNext();
  }
}

//EOF
