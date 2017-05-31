//*******************************************************************
/*!
\file   cHwDisplayGraphic.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
cHwDisplayFont fontTable[] =
  {
    fontFont_8x12,
    fontFont_10x20,
    fontFont_16x24
  };

WORD colorTable[] =
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

char txt[21];
BYTE cnt = 0;

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwDisplayGraphic," );
  uart.set( __DATE__ ","__TIME__"\r\n\n" );

  disp.setBackColor( cHwDisplayGraphic::Blue  );
  disp.setTextColor( cHwDisplayGraphic::White );

  disp.clear();

  for( BYTE i=0; i<16; i++ )
  {
    disp.setPaintColor( colorTable[i] );
    disp.putRectangle ( 20*i, 0, 20, 20 ); //240 );
  }

  disp.setPaintColor( cHwDisplayGraphic::Grey );
  disp.putRectangle ( 40, 30, 240, 180 );

  disp.setPaintColor( cHwDisplayGraphic::Navy );
  for(WORD x=0; x<320; x++ )
  {
    disp.putPixel( x,     3*x/4 ); // Diagonale oben,links  --> unten,rechts
    disp.putPixel( x, 240-3*x/4 ); // Diagonale unten,links --> oben,rechts
  }

  #ifdef BITMAP_EXIST
    disp.putBitmap( (320-32)/2, (240-32)/2, 32, 32, (const WORD*)bitmap );
  #endif

  while( 1 )
  {
//    sys.run();

    // set different fonts and zoom factors
    switch( cnt )
    {
      case   0: disp.setFont( fontTable[0], 1 ); break;
      case  40: disp.setZoom(               2 ); break;
      case  80: disp.setFont( fontTable[1], 1 ); break;
      case 120: disp.setZoom(               2 ); break;
      case 160: disp.setFont( fontTable[2], 1 ); break;
      case 200: disp.setZoom(               2 ); break;
    }

    sprintf(txt,"cnt=%3d",cnt++);

    disp.gotoPixelPos( 40, 30 );
    for( BYTE i=0; txt[i]!=0; i++ )
    {
      disp.putChar(txt[i]);
    }

    if( cnt == 0 )
      disp.clear();
  }
}
