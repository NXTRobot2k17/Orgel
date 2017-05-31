//*******************************************************************
/*!
\file   cHwADC_MCU.cpp
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
  
  // ADC
  cPinConfig::AD0_P0_11,
  cPinConfig::AD1_P0_12,
  cPinConfig::AD2_P0_13,
  cPinConfig::AD3_P0_14,
  cPinConfig::AD5_P0_16,
  cPinConfig::AD6_P0_22,
  cPinConfig::AD7_P0_23,
    
  cPinConfig::END_OF_TABLE
};

cHwUART_0   stdio( cHwUART::BR_115200, 100, 100 );
  
//*******************************************************************
cHwADC_0    adc;

//*******************************************************************
#include "../../Common/cHwADC.cpp"
