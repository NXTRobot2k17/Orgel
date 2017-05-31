//*******************************************************************
/*!
\file   Net.cpp
\author Thomas Breuer
\date   10.03.2014
*/

//-------------------------------------------------------------------
#include "Net/NetStd.cpp"
#include "Net/NetTransport.cpp"

#ifndef _MCU_TYPE_VIRTUAL
  #include "Net/NetARP.cpp"
  #include "Net/NetDHCP.cpp"
  #include "Net/NetICMP.cpp"
  #include "Net/NetIP.cpp"
  #include "Net/NetTCP.cpp"
  #include "Net/NetUDP.cpp"
#endif

// EOF
