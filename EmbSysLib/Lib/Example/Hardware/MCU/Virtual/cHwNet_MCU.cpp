//*******************************************************************
/*!
\file   cHwNet_MCU.cpp
\author Thomas Breuer
\date   20.10.2016
\brief  Sample of using hardware related classes, MCU: Virtual
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
#define TCP
#define SERVER

//*******************************************************************
cSystem        sys;

cHwUART_Stdio  uart( false /* no echo */ );

cNetWin           net;
#ifdef TCP
cNetTCP tcp ( net );
#else
cNetUDP tcp ( net );
#endif

#ifdef SERVER
cNetAddr<4> addr = broadcastAddr;
#else
cNetAddr<4> addr = {127,0,0,1};   // replace IP if requested
#endif

//*******************************************************************
#include "../../Common/cHwNet.cpp"
