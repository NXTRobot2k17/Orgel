//*******************************************************************
/*!
\file   cHwI2Cmaster_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: LPC17xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem         sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  TXD1_P2_0,
  RXD1_P2_1,

  // I2C
  SDA1_P0_0,
  SCL1_P0_1,

  SDA2_P0_10,
  SCL2_P0_11,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
#define HWADDR 0xB0   // I2C address for I2Cmaster/-slave test

cHwI2Cmaster_N       i2c_N( cHwI2Cmaster_N::I2C_1, 
                            cHwI2Cmaster::CR_100kHz );

cHwI2Cmaster::Device i2c  ( i2c_N, HWADDR  );
  
//*******************************************************************
#include "../../Common/cHwI2Cmaster.cpp"
//*******************************************************************
