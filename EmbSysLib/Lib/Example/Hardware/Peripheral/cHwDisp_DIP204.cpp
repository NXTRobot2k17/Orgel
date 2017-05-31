//*******************************************************************
/*!
\file   cHwDisp_DIP204.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
\todo   getNumberOfLines verwenden
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

#ifndef _MCU_TYPE_VIRTUAL

  //*******************************************************************
  cHwDisp_DIP204 disp( portDIP );

  //*******************************************************************
  #include "../Common/cHwDisplay.cpp"

#else
  #include "void.cpp"
#endif

