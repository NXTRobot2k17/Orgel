//*******************************************************************
/*!
\file   cHwPort_PCF8574.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

#ifndef _MCU_TYPE_VIRTUAL

  //*****************************************************************
  cHwPort_PCF8574 portIn( i2c, 1);
  cHwPort        &portOut = portIn;

  BYTE pinIn_a  = 2;
  BYTE pinIn_b  = 3;
  BYTE pinOut_a = 0;
  BYTE pinOut_b = 1;
  
  //*****************************************************************
  #include "../Common/cHwPort.cpp"

#else
  #include "void.cpp"
#endif
