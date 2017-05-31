//*******************************************************************
/*!
\file   Lib/Example/Device/config.h
\author Thomas Breuer
\date   31.01.2013
\brief  Configuration file
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem sys;

//===================================================================
#if defined _MCU_TYPE_LPC17XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD1_P2_0,
    RXD1_P2_1,

    // SPI
    SCK0_P0_15,
    MISO0_P0_17,
    MOSI0_P0_18,

    SCK1_P0_7,
    MISO1_P0_8,
    MOSI1_P0_9,

    END_OF_TABLE
  };

  cHwPort_N        port0     ( cHwPort_N::P0 );
  cHwPort_N        port4     ( cHwPort_N::P4 );

  cHwTimer_N           timer        ( cHwTimer_N::TIM_0, 1000 );
  cHwUART_N            uart         ( cHwUART_N::UART_1,
                                      cHwUART::BR_9600,
                                      100,
                                      100 );

  cHwSPImaster_1   spi1      ( cHwSPImaster::CR_8000kHz, cHwSPImaster::CPOL_H_CPHA_H );

  cHwSPImaster::Device spiDevDisplay( spi1,
                                      port0,
                                      6 );

  cHwPort::Pin     pinBackLight ( port4, 28 );

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART1_TX_PA_9,
    USART1_RX_PA_10,

    // SPI
    SPI2_MOSI_PB_15,
    SPI2_MISO_PB_14,
    SPI2_SCK_PB_13,

    END_OF_TABLE
  };

  cHwPort_N            portA        ( cHwPort_N::PA );
  cHwPort_N            portB        ( cHwPort_N::PB );
  cHwPort_N            portC        ( cHwPort_N::PC );
  cHwTimer_N           timer        ( cHwTimer_N::TIM_2, 1000 );
  cHwUART_N            uart         ( cHwUART_N::USART_1,
                                      cHwUART::BR_9600,
                                      100,
                                      100 );
  cHwSPImaster_N       spi2         ( cHwSPImaster_N::SPI_2,
                                      cHwSPImaster::CR_1000kHz,
                                      cHwSPImaster::CPOL_H_CPHA_H );
  cHwSPImaster::Device spiDevDisplay( spi2,
                                      portB,
                                      12 );

  cHwPort::Pin     pinBackLight ( portC, 8 );

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================

  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,

    // SPI
    SPI2_MOSI_PC_3,
    SPI2_MISO_PC_2,
    SPI2_SCK_PB_10,

    END_OF_TABLE
  };

  cHwPort_N            portA        ( cHwPort_N::PA );
  cHwPort_N            portB        ( cHwPort_N::PB );
  cHwPort_N            portC        ( cHwPort_N::PC );
  cHwPort_N            portD        ( cHwPort_N::PD );
  cHwTimer_N           timer        ( cHwTimer_N::TIM_4, 1000 );
  cHwUART_N            uart         ( cHwUART_N::USART_6,
                                      cHwUART::BR_9600,
                                      100,
                                      100 );
  cHwSPImaster_N       spi2         ( cHwSPImaster_N::SPI_2,
                                      cHwSPImaster::CR_1000kHz,
                                      cHwSPImaster::CPOL_H_CPHA_H );
  cHwSPImaster::Device spiDevDisplay( spi2,
                                      portB,
                                      14 );

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL
//===================================================================
cNetWin           net;
#ifdef TCP
cNetTCP tcp ( net );
#else
cNetUDP udp ( net );
#endif

#ifdef SERVER
cNetAddr<4> addr = broadcastAddr;
#else
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
#endif

 cNetAddr<4> server = {127,0,0,1};
  cHwUART_MCU uart( server, 1004 );
//cHwUART_Stdio uart;
//===================================================================
#else
  #error "config.h: device type not defined"
#endif
//===================================================================

cDevTextIO_UART com ( uart, 100, 100 );

//EOF
