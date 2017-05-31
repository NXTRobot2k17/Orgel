//*******************************************************************
/*!
\file   cHwTouch_Virtual.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
//*******************************************************************
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
cHwTouch_Virtual touch( addr, 1001, 320, 240 );

//*******************************************************************
#include "../../Common/cHwTouch.cpp"
