//*******************************************************************
/*!
\file   cHwPort_Virtual.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
cHwPort_Virtual portIn( addr, 1000);

cHwPort        &portOut = portIn;

// using port-class:
BYTE pinIn_a  =  5;
BYTE pinOut_a =  8;

// using pin-class:
cHwPort::Pin  pinIn_b ( portIn,  10 );
cHwPort::Pin  pinOut_b( portOut, 9 );


//*******************************************************************
#include "../../Common/cHwPort.cpp"
