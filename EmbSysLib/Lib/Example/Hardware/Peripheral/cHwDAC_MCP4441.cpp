//*******************************************************************
/*!
\file   cHwDAC_MAX4441.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

#ifndef _MCU_TYPE_VIRTUAL

  //*****************************************************************
  cHwDAC_MCP4441 dac( i2c, 0 );

  //*****************************************************************
  #include "../Common/cHwDAC.cpp"

#else
  #include "void.cpp"
#endif

