//*******************************************************************
/*!
\file   cHwUART_IP.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
\todo
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#ifdef TCP
  #ifdef SERVER
    cHwUART_IPserver<cNetTCP> term( tcp, 23 );
  #else
   g cHwUART_IPclient<cNetTCP> term( udp, addr, 23 );
  #endif
#else
  #ifdef SERVER
   g cHwUART_IPserver<cNetUDP> term( tcp, 23 );
  #else
  g  cHwUART_IPclient<cNetUDP> term( udp, addr, 23 );
  #endif
#endif


//*******************************************************************
//*******************************************************************
#include <stdio.h>

//*******************************************************************
BYTE value = 0;
BYTE cnt   = 0;
char str[40];

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwUART,"__DATE__ ","__TIME__"\r\n\n" );
  uart.set( "UART: \r\n" );

  while( 1 )
  {
//    sys.run();
net.update();

    if( uart.get( &value ) )
    {
      term.set( value );

      sprintf(str, ":0x%02x ", value );
      uart.set( str );

      if( (cnt++) >= 7 )
      {
        cnt = 0;
        uart.set("\r\n");
      }
    }

    if( term.get( &value ) )
    {
      uart.set( value );
      if( value == '\r' )
        uart.set('\n');
    }
  }
}

