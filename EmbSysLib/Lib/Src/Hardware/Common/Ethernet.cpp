//#include <avr/io.h>
//#include "lib.h"

//#include "net.h"
//#include "lowlevel.h"
//#include "NetARP.h"
//#include "NetIP.h"
//#include "ethernet.h"

//*****************************************************************************
//*****************************************************************************
cHwEthernet::cHwEthernet( const cNetAddr<6> &addrPhyIn )

: addrPhy( addrPhyIn )
{
  plen    = 0;
  arp = NULL;
  ip  = NULL;
}

//*****************************************************************************
void cHwEthernet::update( void )
{
  if( PacketReceive( ) )
  {
    switch( getType() )
    {
      case cHwEthernet::TYPE_ARP: if( arp )  arp->process(); break;
      case cHwEthernet::TYPE_IP:  if(  ip )   ip->process(); break;
    }
  }
  
  if( ip )
  {    
    ip->update();
  }
}


//*****************************************************************************
void cHwEthernet::setARP( cNetARP *arpIn )
{
  arp = arpIn;
}

//*****************************************************************************
void cHwEthernet::setIP( cNetIP *ipIn )
{
  ip = ipIn;
}

//*****************************************************************************
const cNetAddr<4> &cHwEthernet::getIP( void )
{
  if( ip )
    return( ip->getAddr() );
  else
    return( zeroAddr );
}

