//*******************************************************************
/*!
\file   cHwMemory_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: Virtual
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwUART_Stdio   stdio( false /* no echo */ );

//*******************************************************************
cHwMemory_MCU mem( "mem.bin", 10 );

//*******************************************************************
#include "../../Common/cHwMemory.cpp"
