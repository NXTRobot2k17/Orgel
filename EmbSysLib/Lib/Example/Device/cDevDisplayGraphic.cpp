//*******************************************************************
/*!
\file   cDevDisplayGraphic.cpp
\author Thomas Breuer
\date   15.02.2013
\brief  Sample Device Display (graphic)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#include "math.h"

//*******************************************************************
#include "bitmap.c"

//*******************************************************************
cDevDisplayGraphic lcd( dispg );

//*******************************************************************
unsigned short colorList[] =
{
  cHwDisplayGraphic::Black,
  cHwDisplayGraphic::Navy,
  cHwDisplayGraphic::DarkGreen,
  cHwDisplayGraphic::DarkCyan,
  cHwDisplayGraphic::Maroon,
  cHwDisplayGraphic::Purple,
  cHwDisplayGraphic::Olive,
  cHwDisplayGraphic::Grey,
  cHwDisplayGraphic::DarkGrey,
  cHwDisplayGraphic::Blue,
  cHwDisplayGraphic::Green,
  cHwDisplayGraphic::Cyan,
  cHwDisplayGraphic::Red,
  cHwDisplayGraphic::Magenta,
  cHwDisplayGraphic::Yellow,
  cHwDisplayGraphic::White
};

//*******************************************************************
int main( void )
{
  WORD cnt = 0;

  while( 1 )
  {
    if( cnt%(320-12) == 0 )
    {
      lcd.setTextColor(cHwDisplayGraphic::White);
      lcd.setBackColor(cHwDisplayGraphic::Navy);

      lcd.clear(); // clear with actuall back color

      lcd.drawLine(  0,   0, 319, 239, 1, cHwDisplayGraphic::Black  );
      lcd.drawLine(  0, 239, 319,   0, 2, cHwDisplayGraphic::Yellow );
      lcd.drawLine(160,   0, 160, 239, 3, cHwDisplayGraphic::Green  );
      lcd.drawLine(  0, 120, 319, 120, 4, cHwDisplayGraphic::White  );

      lcd.setFont ( fontFont_8x12, 2 );
      lcd.drawText( 10, 10, 10, "cDevDisplayGraphic" );
      lcd.setZoom ( 1 );
      lcd.drawText( 10, 40, 10, __DATE__ "," __TIME__ );

      cnt = 0;
    }

    lcd.drawBitmap   ( cnt , 120-6 + 20*sin(2.0*PI*4*cnt/320), 12, 12, (const WORD*)bitmap );
    lcd.drawPixel    ( cnt , 150   + 20*sin(2.0*PI*4*cnt/320), cHwDisplayGraphic::Red );

    if( (cnt%20) == 0)
    {
      BYTE color = (cnt/20)%16;

      lcd.setFont( fontFont_10x20 );

      lcd.drawRectangle(  50, 210, 20, 20, colorList[color] );
      lcd.drawCircle   (  90, 220, 10,     colorList[color] );
      lcd.drawText     ( 110, 210,  3, "%d", color );
    }

    cnt++;
  }

}
