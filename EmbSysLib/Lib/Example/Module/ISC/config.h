//*******************************************************************
/*!
\file   Lib/Example/Module/IPC/config.h
\author Thomas Breuer
\date   19.03.2016
\brief  Configuration file
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem sys;

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_LPC17XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD1_P2_0,
    RXD1_P2_1,

    // USB
    USB_Dm_P0_30,
    USB_Dp_P0_29,
    USB_UP_LED_P1_18, // GoodLink
    VBUS_P1_30,
    USB_CONNECT_P2_9, // SoftConnect

    END_OF_TABLE
  };

  cHwUART_N    uart( cHwUART_N::UART_1,
                     cHwUART::BR_115200,
                     255,
                     255 );

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART1_TX_PA_9,
    USART1_RX_PA_10,

    // USB
    USBDM_PA_11,
    USBDP_PA_12,

    END_OF_TABLE
  };

  cHwUART_N    uart( cHwUART_N::USART_1,
                     cHwUART::BR_115200,
                     255,
                     255 );

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,

    // USB
    OTG_FS_ID_PA_10,
    OTG_FS_DM_PA_11,
    OTG_FS_DP_PA_12,

    END_OF_TABLE
  };

  cHwUART_N    uart    ( cHwUART_N::USART_6,
                         cHwUART::BR_115200,
                         255,
                         255 );

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL
//===================================================================
cHwUART_Stdio         uart( true );
//===================================================================
#else
  #error "config.h: device type not defined"
#endif
//===================================================================

//EOF
