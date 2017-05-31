//*******************************************************************
/*!
\file   cHwSPImaster.cpp
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

  // SPI
  cPinConfig::MISO0_P0_8,
  cPinConfig::MOSI0_P0_9,
  cPinConfig::SCK0_P0_6,
  
  cPinConfig::MISO1_P0_22,
  cPinConfig::MOSI1_P0_21,
  cPinConfig::SCK1_P1_15,

  cPinConfig::END_OF_TABLE
};

cHwUART_0   stdio( cHwUART::BR_115200, 100, 100 );
  
//*******************************************************************
cHwSPImaster_N       spi_N( cHwSPImaster_N::SPI1, 
                            cHwSPImaster::CR_250kHz,
                            cHwSPImaster::CPOL_H_CPHA_H );

cHwPort_N            port0( cHwPort_N::P0 );

cHwPort::Pin         spiCS( port0, 17 );

cHwSPImaster::Device spi  ( spi_N, spiCS );

//*******************************************************************
#include "../../Common/cHwSPImaster.cpp"
