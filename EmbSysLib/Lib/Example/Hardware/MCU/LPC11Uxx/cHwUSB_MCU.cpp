//*******************************************************************
/*!
\file   cHwUSB_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: STM32L1xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem    sys;

  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD_P0_19,
    RXD_P0_18,

    // USB
    //cPinConfig::USB_Dm_P0_30,
    //cPinConfig::USB_Dp_P0_29,
    //cPinConfig::USB_UP_LED_P1_18, // GoodLink
    USB_VBUS_P0_3,
    USB_CONNECT_P0_6,  // SoftConnect

    END_OF_TABLE
  };



  char str[40];

cHwUART_0  uart( cHwUART::BR_115200, 100, 100 );


//*******************************************************************
#include "../../Common/cHwUSB.cpp"
