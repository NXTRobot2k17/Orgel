//*******************************************************************
/*!
\file   cHwUART.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016

\brief  Sample of using hardware related class 'cHwNet'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
class Application : public cNetApplication
{
  public:
    //---------------------------------------------------------------
    Application( void )
    #ifdef TCP
    : socket( tcp, *this, addr, 23 )
    #else
    : socket( udp, *this, addr, 23 )
    #endif
    {
      socket.openDefault();
      //socket.setTimeout(10);
    }

  private:
    //---------------------------------------------------------------
    virtual void process( void )
    {
      char c;
      while( socket.get( &c ) )
      {
        uart.set( c );
        //socket.setTimeout(2);
      }
    }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      BYTE c;
      if( socket.isConnected() && uart.get(&c) )
      {
         socket.clear( );
         do
         {
           uart.set(c); // local echo
           socket.fill( c );
         } while( uart.get(&c));
         socket.send();
      }
    }

    //---------------------------------------------------------------
     virtual void timeout( void )
     {
       if( socket.isConnected())
       {
         socket.close();
       }
     }

  private:
    //---------------------------------------------------------------
    #ifdef TCP
    cNetTCP::Socket socket;
    #else
    cNetUDP::Socket socket;
    #endif

};

//*******************************************************************
Application app;

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwNet,"__DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {
    net.update();
  }
}
