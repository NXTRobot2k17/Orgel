//*******************************************************************
/*!
\file   cDevPointer.cpp
\author Thomas Breuer
\date   15.02.2013
\brief  Sample Device Control (pointer)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cDevDisplayGraphic disp   ( dispGraphic );
cDevPointer        pointer( touch );

//*******************************************************************
#include "hardware/MCU/ATmega/WORKAROUND_AVR_BUG.h"
//*******************************************************************

//*******************************************************************
int main( void )
{
  disp.drawText( 0,0, 0, "cDevPointer" );
  disp.drawText( 0,20, 0, __DATE__ "," __TIME__ );

  while( 1 )
  {
    sys.run();

    cDevPointer::cData point = pointer.get();

    if( point.flags & cDevPointer::cData::PRESSED )
    {
      disp.drawRectangle( point.posX,
                          point.posY,
                          2, 2, cHwDisplayGraphic::White );
    }
    disp.drawText( 0, 180, 20, "pos  :%4d,%4d", point.posX, point.posY );
    disp.drawText( 0, 200, 20, "delta:%4d",     point.delta );
    disp.drawText( 0, 220, 20, "event:0x%02x",  point.flags );
  }
}
