//*******************************************************************
/*!
\file   cHwDisp_ILI9341spi.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#include "hardware/Common/Font/Font_8x12.h"
#include "hardware/Common/Font/Font_10x20.h"
#include "hardware/Common/Font/Font_16x24.h"

#ifndef _MCU_TYPE_VIRTUAL

  //*******************************************************************
  cHwDisp_ILI9341spi disp( spiDisplay,
                           pinCS,
                           pinBackLight ,
                           fontFont_8x12, // font
                           3 );           // actual zoom factor

  //*******************************************************************
  #include "../Common/cHwDisplayGraphic.cpp"

#else
  #include "void.cpp"
#endif
