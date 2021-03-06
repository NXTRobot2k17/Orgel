//*******************************************************************
/*!
\file   cHwPort_MCU.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32L1xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART1_TX_PA_9,
  USART1_RX_PA_10,
  
  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwPort_N portIn ( cHwPort_N::PA ); // define an input port 
cHwPort_N portOut( cHwPort_N::PC ); // define an output port

// using port-class:
BYTE pinIn_a  = 1;
BYTE pinOut_a = 9;

// using pin-class:
cHwPort::Pin  pinIn_b ( portIn,  0 );
cHwPort::Pin  pinOut_b( portOut, 8 );

//*******************************************************************
#include "../../Common/cHwPort.cpp"
//*******************************************************************
