//*******************************************************************
/*!
\file   cHwSPImaster.cpp
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

  SCK0_P0_15,
  MISO0_P0_17,
  MOSI0_P0_18,

  SCK1_P0_7,
  MISO1_P0_8,
  MOSI1_P0_9,

  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwPort_N             port2( cHwPort_N::P2 );

cHwSPImaster_0        spi_0( cHwSPImaster::CR_250kHz, 
                             cHwSPImaster::CPOL_H_CPHA_H );
cHwSPImaster::Device  spi  ( spi_0, port2, 6 );

//*******************************************************************
#include "../../Common/cHwSPImaster.cpp"
//*******************************************************************
