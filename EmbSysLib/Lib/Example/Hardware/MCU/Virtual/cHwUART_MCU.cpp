//*******************************************************************
/*!
\file   cHwUART_MCU.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes, MCU: Virtual
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem        sys;

//*******************************************************************
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
cHwADC_Virtual adcIn( addr, 1002);

//cHwUART_Stdio  uart( false /* no echo */ );
cHwUART_MCU  uart( addr, 1004 );


cHwUART_File  term( "RxD.txt",   // input file
                    "TxD.txt" ); // output file

//*******************************************************************
#include "../../Common/cHwUART.cpp"
