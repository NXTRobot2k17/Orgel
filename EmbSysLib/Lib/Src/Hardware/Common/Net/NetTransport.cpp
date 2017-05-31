//-------------------------------------------------------------------
cNetTransport::Socket::Socket( cNetTransport   &transIn,
                                cNetApplication &appIn,
                                cNetAddr<4>      inAddrIn,
                                WORD             portIn,
                                WORD             updateTimeIn )
: app  ( appIn   )

{
  addrPhy    = zeroAddrPhy;
  addr       = zeroAddr;
  myPort     = portIn;
  remoteAddr = inAddrIn;
  remotePort = portIn;
  timeOutTic = 0;
  updateTime = updateTimeIn/10; // Timebase = 10 ms
  updateTic  = updateTime;
  state      = STATE_WAITING;

  transIn.appList.add( (cList::Item*)this );
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
cNetTransport::cNetTransport( /*cNetIP  &ipIn*/ )

//: ip (  ipIn )

{
}

//-------------------------------------------------------------------
void cNetTransport::process( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr ) // )
  {
    ptr->process();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
void cNetTransport::update( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->update();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
void cNetTransport::timeout( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->timeout();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
cNetAddr<4> cNetTransport::Socket::getRemoteIP( void )
{
  return( remoteAddr );
}

