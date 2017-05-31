//*******************************************************************
/*!
\file   cHwRAM_MCU.cpp
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
  
  cPinConfig::END_OF_TABLE
};

cHwUART_0   stdio( cHwUART::BR_115200, 100, 100 );
  
//*******************************************************************
cHwMemory_EEPROM  mem;

//*******************************************************************
#include "../../Common/cHwMemory.cpp"
