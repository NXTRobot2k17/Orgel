//*******************************************************************
/*!
\file   cHwTouch_STMPE811i2c.cpp
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
  cHwTouch_STMPE811i2c touch( i2c, 0, 320, 240);
  
  //*******************************************************************
  #include "../Common/cHwTouch.cpp"

#else
  #include "void.cpp"
#endif
