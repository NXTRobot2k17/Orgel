//*******************************************************************
/*!
\file   cHwMemory_EEPROM.cpp
\author Thomas Breuer
\date   08.09.2016
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

  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwMemory_Flash mem( (BYTE *)0x08010000, 0x400);

//*******************************************************************
#include "../../Common/cHwMemory.cpp"
//*******************************************************************
