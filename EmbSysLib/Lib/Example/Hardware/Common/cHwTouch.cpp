//*******************************************************************
/*!
\file   cHwTouch.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
char str[40];

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwTouch,");
  uart.set( __DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {

    touch.update();

    BYTE t = touch.isTouched();
    int  x = touch.getPosX();
    int  y = touch.getPosY();

    sprintf( str, "x=%5d y=%5d t=%c\r" , x, y, t?'X':'-' );
    uart.set( str );
  }
}
