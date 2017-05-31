//*******************************************************************
/*!
\file   cHwI2Cmaster_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: LPC11Uxx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cPinConfig::MAP cPinConfig::table[] = 
{
  // UART
  cPinConfig::TXD_P0_19,
  cPinConfig::RXD_P0_18,
  
  // I2C
  cPinConfig::SCL_P0_4,
  cPinConfig::SDA_P0_5,
  
  cPinConfig::END_OF_TABLE
};

cHwUART_0       stdio( cHwUART::BR_115200, 100, 100 );
  
//*******************************************************************
#define HWADDR 0xB0   // I2C address for I2Cmaster/-slave test

cHwI2Cmaster_0       i2c_0( cHwI2Cmaster::CR_100kHz );

cHwI2Cmaster::Device i2c  ( i2c_0, HWADDR );

//*******************************************************************
#include "../../Common/cHwI2Cmaster.cpp"
