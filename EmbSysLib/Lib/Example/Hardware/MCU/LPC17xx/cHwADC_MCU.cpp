//*******************************************************************
/*!
\file   cHwADC_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: LPC17xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  TXD1_P2_0,
  RXD1_P2_1,
  
  // ADC
  AD0_0_P0_23,
  AD0_1_P0_24,
  AD0_2_P0_25,
  AD0_3_P0_26,
  AD0_4_P1_30,
  AD0_5_P1_31,
  AD0_6_P0_3,
  AD0_7_P0_2,

  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwADC_0    adc;

//*******************************************************************
#include "../../Common/cHwADC.cpp"
//*******************************************************************
