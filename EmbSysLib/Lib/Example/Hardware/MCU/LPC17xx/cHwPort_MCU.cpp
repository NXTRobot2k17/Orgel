//*******************************************************************
/*!
\file   cHwPort_MCU.cpp
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
  
  END_OF_TABLE
};

cHwUART_N   uart( cHwUART_N::UART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwPort_N   portIn ( cHwPort_N::P1 ); // define an input port 
cHwPort_N   portOut( cHwPort_N::P2 ); // define an output port

// using port-class:
BYTE pinIn_a  = 23;
BYTE pinOut_a =  2;

// using pin-class:
cHwPort::Pin  pinIn_b ( portIn,  24 );
cHwPort::Pin  pinOut_b( portOut,  3 );

//*******************************************************************
#include "../../Common/cHwPort.cpp"
//*******************************************************************
