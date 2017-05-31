//*******************************************************************
/*!
\file   Net.h
\author Thomas Breuer
\date   10.03.2014

\brief

\example .cpp
*/


//*******************************************************************
#ifndef _HW_NET_H
#define _HW_NET_H
#define _HW_NET_C

//-------------------------------------------------------------------
#include "Net/NetStd.h"
#include "Net/NetApp.h"
#include "Net/NetTransport.h"

#ifndef _MCU_TYPE_VIRTUAL

  #include "Net/NetARP.h"
  #include "Net/NetDHCP.h"
  #include "Net/NetICMP.h"
  #include "Net/NetTCP.h"
  #include "Net/NetUDP.h"
#endif
//-------------------------------------------------------------------
#endif //_HW_NET_H
