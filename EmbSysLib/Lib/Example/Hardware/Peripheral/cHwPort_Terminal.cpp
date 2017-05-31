//*******************************************************************
/*!
\file   cHwPort_Terminal.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
\todo   Ueberarbeiten!
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cHwPort_Terminal portIn( stdio,
                         cHwPort_Terminal::BLANK /*, &timer*/ );

cHwPort         &portOut = portIn;

BYTE pinIn_a  = 2;
BYTE pinIn_b  = 3;
BYTE pinOut_a = 0;
BYTE pinOut_b = 1;

#define PORT_TERMINAL

//*******************************************************************
#include "../Common/cHwPort.cpp"
