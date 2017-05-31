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
#include "hardware/Common/Font/Font_8x12.h"
#include "hardware/Common/Font/Font_10x20.h"
#include "hardware/Common/Font/Font_16x24.h"

//*******************************************************************
cSystem sys;

//===================================================================
#if defined _MCU_TYPE_LPC11UXX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD_P0_19,
    RXD_P0_18,

    // ADC
    AD0_P0_11,
    AD1_P0_12,
    AD2_P0_13,
    AD3_P0_14,
    AD5_P0_16,
    AD6_P0_22,
    AD7_P0_23,

    // Timer
    CT16B0_MAT0_P0_8,
    CT16B0_MAT1_P0_9,

    // I2C
    SCL_P0_4,
    SDA_P0_5,

    // SPI
    MISO0_P0_8,
    MOSI0_P0_9,
    SCK0_P0_6,

    MISO1_P0_22,
    MOSI1_P0_21,
    SCK1_P1_15,

    END_OF_TABLE
  };


  cHwUART_0    uart    ( cHwUART::BR_9600,
                         100,
                         100 );


  cHwTimer_N             timer   ( cHwTimer_N::CT16B0, 1000 );
  cHwTimer_N             timerPWM( cHwTimer_N::CT16B1,  100 );
  cHwUART_0              term    ( cHwUART::BR_38400, 20, 20 );
  cHwPort_N              port0   ( cHwPort_N::P0 );
  cHwPort_N              port1   ( cHwPort_N::P1 );
  cHwADC_0               adc     ( &timer );
  cHwI2Cmaster_0         i2c     ( cHwI2Cmaster::CR_400kHz );
  cHwSPImaster_N         spiDisp ( cHwSPImaster_N::SPI0,
                                   cHwSPImaster::CR_500kHz,
                                   cHwSPImaster::CPOL_H_CPHA_H );
  cHwPort::Pin           spiDisplay_BL( port0, 23 );
  cHwPort::Pin           spiDisplay_CS( port0, 16 );
  cHwPort::Pin           spiTouch_CS( port0, 7 );

  cHwDisp_Terminal       dispChar   ( term );

//===================================================================
#elif defined _MCU_TYPE_LPC17XX
//===================================================================
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

    // DAC
    AOUT_P0_26,

    // Timer
    PWM1_1_P2_0,
    PWM1_2_P2_1,
    PWM1_3_P2_2,
    PWM1_4_P2_3,
    PWM1_5_P2_4,
    PWM1_6_P2_5,

    // SPI
    SCK1_P0_7,
    MISO1_P0_8,
    MOSI1_P0_9,

    END_OF_TABLE
  };

  cHwPort_N    port0   ( cHwPort_N::P0 );
  cHwPort_N    port1   ( cHwPort_N::P1 );
  cHwPort_N    port2   ( cHwPort_N::P2 );
  cHwPort_N    port4   ( cHwPort_N::P4 );
  cHwTimer_N   timer   ( cHwTimer_N::TIM_1,   1000 );
  cHwTimer_N   timerPWM( cHwTimer_N::TIM_PWM, 4095 );
  cHwADC_0     adc     ( &timer );
  cHwDAC_0     dac;
  cHwUART_N    uart    ( cHwUART_N::UART_1,
                         cHwUART::BR_9600,
                         100,
                         100 );

  cHwSPImaster_1       spi1        ( cHwSPImaster::CR_8000kHz, cHwSPImaster::CPOL_H_CPHA_H );
  cHwSPImaster::Device spiDisplay  ( spi1, port0, 6 );
  cHwPort::Pin         pinBackLight( port4, 28 );
  cHwDisp_SPFD5408Bspi disp        ( spiDisplay,
                                     pinBackLight ,
                                     fontFont_8x12, // font
                                     2 );           // actual zoom factor

  static const cNetAddr<6> myMAC = {0x16,0x20,0x68,0x01,0x02,0x28};
  static const cNetAddr<4> myIP  = //{192,168,1,120};
                                   zeroAddr;



  cHwEthernet_EMAC net  ( myMAC );
   cNetIP   ip   ( net, myIP, timer );
    cNetICMP icmp ( ip );
    cNetTCP  tcp  ( ip );
    cNetUDP  udp  ( ip );

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART1_TX_PA_9,
    USART1_RX_PA_10,

    // ADC
    ADC12_IN2_PA_2,

    // DAC
    DAC_OUT1_PA_4,

    // Timer
    TIM3_CH3_PC_8,

    // SPI
    SPI2_MOSI_PB_15,
    SPI2_MISO_PB_14,
    SPI2_SCK_PB_13,

    END_OF_TABLE
  };

  cHwPort_N    portA   ( cHwPort_N::PA );
  cHwPort_N    portB   ( cHwPort_N::PB );
  cHwPort_N    portC   ( cHwPort_N::PC );
  cHwTimer_N   timer   ( cHwTimer_N::TIM_2, 1000 );
  cHwTimer_N   timerPWM( cHwTimer_N::TIM_3, 4095 );
  cHwADC_0     adc     ( &timer );
  cHwDAC_0     dac;
  cHwUART_N    uart    ( cHwUART_N::USART_1,
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

  cHwDisp_DIP204spi disp( spiDevDisplay );

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================

  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,

    // ADC
    ADC123_IN2_PA_2,

    // DAC
    DAC2_OUT_PA_5,

    // Timer
    TIM4_CH1_PD_12,

    END_OF_TABLE
  };

  cHwPort_N    portA   ( cHwPort_N::PA );
  cHwPort_N    portD   ( cHwPort_N::PD );
  cHwTimer_N   timer   ( cHwTimer_N::TIM_4, 1000 );
  cHwTimer_N  &timerPWM = timer;
  cHwADC_0     adc     ( &timer );
  cHwDAC_0     dac;
  cHwUART_N    uart    ( cHwUART_N::USART_6,
                         cHwUART::BR_9600,
                         100,
                         100 );

//=============================
#elif defined _MCU_TYPE_VIRTUAL
//=============================
  cNetWin           net;
  cNetUDP udp ( net );
  cNetTCP tcp ( net );

  cHwTimer_MCU   timer( 10000/*us*/ );
  cHwTimer      &timerPWM = timer;

  cNetAddr<4> server = {127,0,0,1};
  cHwUART_MCU uart( server, 1004 );
  //cHwUART_Stdio uart;

  //cHwPort_Terminal port( uart,
  //                       cHwPort_Terminal::BLANK , &timer );
  cHwPort_Virtual port( server,1000);

  cHwADC_Virtual adc( server, 1002, &timer);
  cHwDAC_Virtual dac( server, 1002);
  cHwDispChar_Virtual disp( server, 1001 );
  cHwDisp_Virtual     dispg( server, 1001,fontFont_8x12 );

//===================================================================
#else
  #error "config.h: device type not defined"
#endif
//===================================================================

cDevTextIO_UART com ( uart, 100, 100 );

//EOF
