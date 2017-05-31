//*******************************************************************
/*!
\file   cHwI2Cmaster_Virtual.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#define HWADDR 0xF0   // I2C address for I2Cmaster/-slave test

//*******************************************************************
#if defined _MCU_TYPE_VIRTUAL
  cHwClient_DDE  clientI2C( "I2CslaveServer","Info" );
#else
  cHwClient_UART clientI2C( uart, "I2CslaveServer", "Info" );
#endif

//*******************************************************************
cHwI2Cmaster_Virtual  i2c_v(clientI2C);
cHwI2Cmaster::Device  i2c( i2c_v, HWADDR );

//*******************************************************************
#include "../Common/cHwI2Cmaster.cpp"
