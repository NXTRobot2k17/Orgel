//*******************************************************************
/*!
\file   cHwTimer_MCU.cpp
\author Thomas Breuer
\date   28.03.2013
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
  
  // Timer (PWM)
  cPinConfig::CT16B0_MAT0_P0_8,
  cPinConfig::CT16B0_MAT1_P0_9,
  
  cPinConfig::CT16B1_MAT0_P0_21,
  cPinConfig::CT16B1_MAT1_P0_22,
  
  cPinConfig::CT32B0_MAT0_P1_24,
  cPinConfig::CT32B0_MAT1_P1_25,
  
  cPinConfig::END_OF_TABLE
};

cHwUART_0   stdio( cHwUART::BR_115200, 100, 100 );
  
//*******************************************************************
cHwTimer_N   timerFast( cHwTimer_N::CT16B0,    1000L/*us*/ );
cHwTimer_N   timerSlow( cHwTimer_N::CT32B0, 1000000L/*us*/ );

cHwTimer_N  &timerPWM = timerFast;

BYTE         timerPWMchannel = 1;

//*******************************************************************
#include "../../Common/cHwTimer.cpp"
