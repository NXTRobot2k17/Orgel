//*******************************************************************
/*!
\file   cHwRS485_MAX48x.cpp
\author Thomas Breuer
\date   14.10.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

#ifndef _MCU_TYPE_VIRTUAL

  //*******************************************************************

  cHwRS485_MAX48x<cHwUART_std>  term( pinRS485 );

  //*******************************************************************
  #include "../Common/cHwUART.cpp"

#else
  #include "void.cpp"
#endif
