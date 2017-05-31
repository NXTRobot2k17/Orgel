//*******************************************************************
/*!
\file   cHwDispChar_Virtual.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
cHwDispChar_Virtual disp( addr, 1001 );

//*******************************************************************
#include "../../Common/cHwDisplay.cpp"
