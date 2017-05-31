//*******************************************************************
// 
// cNetIP
//
//*******************************************************************
//-------------------------------------------------------------------
cNetIP::cNetIP( cHwEthernet &ethIn,
                const cNetAddr<4> &addrIn,
                cHwTimer &timer )

: eth         ( ethIn  ), 
  addr        ( addrIn ),
  arp         ( ethIn, addr ),
  timeOutTimer( timer  ),
  msg         ( *(cNetIP_Msg*)eth.buf )

{
  tcp  = NULL;
  udp  = NULL;
  icmp = NULL;
  eth.setIP( this );
}

//-------------------------------------------------------------------
void cNetIP::process( void )
{
  if( msg.ip.version_IHL == VERSION_IHL )
  {
    if(    msg.ip.destAddr == addr 
        || msg.ip.protocol == PROTOCOL_UDP )
    {
      switch( msg.ip.protocol )
      {
        case cNetIP::PROTOCOL_TCP:  if(  tcp ) {  tcp->process(); } break;
        case cNetIP::PROTOCOL_UDP:  if(  udp ) {  udp->process(); } break;
        case cNetIP::PROTOCOL_ICMP: if( icmp ) { icmp->process(); } break;
      }
    }
  }
}

//-------------------------------------------------------------------
void cNetIP::update( void )
{
  if(  tcp ) {  tcp->update(); }
  if(  udp ) {  udp->update(); }
  if( icmp ) { icmp->update(); }

  if( timeOutTimer.flag )
  {
    timeOutTimer.flag = false;

    if(  tcp )  {  tcp->timeout(); }
    if(  udp )  {  udp->timeout(); }
    if( icmp )  { icmp->timeout(); }
  }
}

//-------------------------------------------------------------------
void cNetIP::create( const cNetAddr<6> destAddrPhy,
                     const cNetAddr<4> destAddr,
                     const WORD        payloadLen,
                     const WORD        protocol )
{
  WORD len = 0;

  eth.create( destAddrPhy, cHwEthernet::TYPE_IP );

  switch( protocol )
  {
   case PROTOCOL_UDP:  len = sizeof( cNetUDP_Header  ); break;
   case PROTOCOL_ICMP: len = sizeof( cNetICMP_Header ); break;
   case PROTOCOL_TCP:  len = sizeof( cNetTCP_Header  ); break;
  }
  
  msg.ip.version_IHL    = VERSION_IHL;
  msg.ip.TypeOfService  = 0;
  msg.ip.packetLength   = sizeof( cNetIP_Header ) 
                           + len
                           + payloadLen;
  msg.ip.identification = 123;
  msg.ip.TTL            = 64;
  msg.ip.protocol       = protocol;
  msg.ip.sourceAddr     = addr;
  msg.ip.destAddr       = destAddr;

  msg.ip.setFlags         ( 0x40 ); // don't fragment
  msg.ip.setFragmentOffset( 0x00 );

  msg.ip.headerChecksum = 0; 
  msg.ip.headerChecksum = Checksum( (BYTE*)&msg.ip, 
                                     sizeof( cNetIP_Header ), 
                                     0 );
}

//-------------------------------------------------------------------
inline void cNetIP::setTCP( cNetTCP *tcpIn )
{
  tcp = tcpIn;
  arp.setTCP( tcpIn );
}

//-------------------------------------------------------------------
inline void cNetIP::setUDP( cNetUDP *udpIn )
{
  udp = udpIn;
  arp.setUDP( udpIn );
}

//-------------------------------------------------------------------
inline void cNetIP::setICMP( cNetICMP *icmpIn )
{
  icmp = icmpIn;
}


//EOF
