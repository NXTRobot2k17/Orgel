//*******************************************************************
/*!
\file   cHwTimer_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: Virtual
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem        sys;

cHwUART_Stdio  uart( false /* no echo */ );

//*******************************************************************
cHwTimer_MCU     timerFast(    1000L/*us*/ );
cHwTimer_MCU     timerSlow( 1000000L/*us*/ );

cHwTimer      &timerPWM = timerFast;

BYTE           timerPWMchannel = 0;

//*******************************************************************
#include "../../Common/cHwTimer.cpp"
