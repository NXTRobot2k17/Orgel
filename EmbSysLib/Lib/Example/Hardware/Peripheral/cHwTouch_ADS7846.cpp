//*******************************************************************
/*!
\file   cHwTouch_ADS7846.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#ifndef _MCU_TYPE_VIRTUAL

  //*******************************************************************
  cHwTouch_ADS7846 touch( spiTouch, spiTouch_CS, 320, 240 );

  //*******************************************************************
  #include "../Common/cHwTouch.cpp"

#else
  #include "void.cpp"
#endif
