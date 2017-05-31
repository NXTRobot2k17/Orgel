//*******************************************************************
/*!
\file   cHwDisp_Virtual.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
//  #include "../Common/bitmap.cpp"
//  #define BITMAP_EXIST

  #include "hardware/Common/Font/Font_8x12.h"
  #include "hardware/Common/Font/Font_10x20.h"
  #include "hardware/Common/Font/Font_16x24.h"

//*******************************************************************
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
cHwDisp_Virtual disp( addr, 1001,
                      fontFont_8x12, // actual font
                      3 );           // actual zoom factor

//*******************************************************************
#include "../../Common/cHwDisplayGraphic.cpp"
