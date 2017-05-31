//*******************************************************************
/*!
\file   cHwTimer_MCU.cpp
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

  // Timer (PWM)
  PWM1_1_P2_0,
  PWM1_2_P2_1,
  PWM1_3_P2_2,
  PWM1_4_P2_3,
  PWM1_5_P2_4,
  PWM1_6_P2_5,

  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwTimer_N  timerSlow ( cHwTimer_N::TIM_2,    1000L/*us*/ );
cHwTimer_N  timerFast ( cHwTimer_N::TIM_3, 1000000L/*us*/ );

cHwTimer_N  timerPWM  ( cHwTimer_N::TIM_PWM,  1000L/*us*/ );

BYTE        timerPWMchannel = 3;

//*******************************************************************
#include "../../Common/cHwTimer.cpp"
//*******************************************************************
