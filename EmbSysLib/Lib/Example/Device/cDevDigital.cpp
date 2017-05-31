//*******************************************************************
/*!
\file   cDevDigital.cpp
\author Thomas Breuer
\date   15.02.2013, 18.03.2016
\brief  Sample code, class cDevDigital
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#include <stdio.h>

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_LPC11UXX
//===================================================================
  cDevDigital ledA( port0,22, cDevDigital::Out, 1 );
  cDevDigital ledB( port0,23, cDevDigital::Out, 1 );
  cDevDigital btnA( port1,15, cDevDigital::In,  1 );
  cDevDigital btnB( port1,19, cDevDigital::In,  1 );
//===================================================================
#elif defined _MCU_TYPE_LPC17XX
//===================================================================
  cDevDigital ledA( port2,  4, cDevDigital::Out, 1 );
  cDevDigital ledB( port2,  5, cDevDigital::Out, 1 );
  cDevDigital btnA( port1, 26, cDevDigital::In,  1 );
  cDevDigital btnB( port1, 24, cDevDigital::In,  1 );
//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================
  cDevDigital ledA( portC,  8, cDevDigital::Out,  0 );
  cDevDigital ledB( portC,  9, cDevDigital::Out,  0 );
  cDevDigital btnA( portC,  0, cDevDigital::InPU, 1 );
  cDevDigital btnB( portA,  0, cDevDigital::In  , 0 );
//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cDevDigital ledA( portD, 12, cDevDigital::Out,  0 );
  cDevDigital ledB( portD, 15, cDevDigital::Out,  0 );
  cDevDigital btnA( portA,  0, cDevDigital::In  , 0 );
  cDevDigital btnB( portA,  1, cDevDigital::In  , 0 );

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL
//===================================================================
  cDevDigital ledA( port, 8, cDevDigital::Out, 0 );
  cDevDigital ledB( port, 9, cDevDigital::Out, 0 );
  cDevDigital btnA( port, 0, cDevDigital::In,  0 );
  cDevDigital btnB( port, 2, cDevDigital::In,  0 );

//===================================================================
#else
  #error "device type not defined"
#endif
//===================================================================

//*******************************************************************
class cReport
{
  public:
    //---------------------------------------------------------------
    cReport( cDevDigital &btnIn )
    : btn(btnIn)
    {
      txtEvent = "no ";
      txtState = "no ";
      cnt      = 0;
    }

    //---------------------------------------------------------------
    char *evaluate( void )
    {
      if( btn.isChanged()   )  { cnt = (cnt+1)%10; }
      if( btn.isClr()       )  { txtState = "clr"; }
      if( btn.isSet()       )  { txtState = "set"; }
      if( btn.isReleased()  )  { txtEvent = "rel"; }
      if( btn.isActivated() )  { txtEvent = "act"; }

      sprintf( txt, "%s,%s,%d", txtEvent, txtState, cnt );
      return( txt );
  }

  private:
    //---------------------------------------------------------------
    const char  *txtEvent;
    const char  *txtState;
    char         txt[32];
    BYTE         cnt;
    cDevDigital &btn;
};

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  cReport A( btnA );
  cReport B( btnB );

  while( 1 )
  {
    //net.update();
    btnA.update();
    btnB.update();

    if( btnA.isActivated() )
    {
      ledA.toggle();
    }

    ledB = btnB;

    //  if( btnB )
    //  {0
    //    ledA = false;
    //  }


    com.printf( "\r%s  %s\r", A.evaluate(), B.evaluate() );
  }
}
