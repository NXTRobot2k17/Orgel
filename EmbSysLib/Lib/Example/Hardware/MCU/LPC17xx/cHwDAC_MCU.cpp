//*******************************************************************
/*!
\file   cHwDAC_MCU.cpp
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

  // DAC
  AOUT_P0_26,
  
  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwDAC_0    dac;

//*******************************************************************
#include "../../Common/cHwDAC.cpp"
//*******************************************************************
