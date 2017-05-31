//*******************************************************************
/*!
\file   cHwUSB_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: LPC17xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem    sys;

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
    USB_CONNECT_P2_9,  // SoftConnect
    
    END_OF_TABLE
  };


 
  char str[40];

cHwUART_N  uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
#include "../../Common/cHwUSB.cpp"
//*******************************************************************
