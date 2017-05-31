//*******************************************************************
/*!
\file   cHwPort_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: LPC11Uxx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  TXD_P0_19,
  RXD_P0_18,

  END_OF_TABLE
};


cHwUART_0   uart( cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwPort_N   portIn ( cHwPort_N::P1 ); // define an input port 
cHwPort_N   portOut( cHwPort_N::P0 ); // define an output port

// using port-class:
BYTE pinIn_a  = 15;
BYTE pinOut_a = 22;

// using pin-class:
cHwPort::Pin  pinIn_b ( portIn,  18 );
cHwPort::Pin  pinOut_b( portOut, 23 );

//*******************************************************************
#include "../../Common/cHwPort.cpp"
