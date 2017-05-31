//*******************************************************************
/*!
\file   Port_MCU.cpp
\author Thomas Breuer
\date   27.02.2013
*/

//*******************************************************************
// 
// cHwPort_N
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_N::cHwPort_N( PORT_ID portId ) 

: cHwPort() 

{
  switch( portId )
  {
    default:
    case 0: portID = 0; break;
    case 1: portID = 1; break;
  }
}


// EOF
