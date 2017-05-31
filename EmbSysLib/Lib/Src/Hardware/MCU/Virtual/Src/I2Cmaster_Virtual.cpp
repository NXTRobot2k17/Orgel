//*******************************************************************
/*!
\file   I2Cmaster_Virtual.cpp
\author Thomas Breuer
\date   18.04.2012
*/

//*******************************************************************
//
// cHwI2Cmaster_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwI2Cmaster_Virtual::cHwI2Cmaster_Virtual( cHwClient &clientIn )

: cHwI2Cmaster( false ), // Don't diasble interrupts, otherwise UART
                        //  would not work!
  client(clientIn)

{
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Virtual::start( void )
{
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Virtual::stop( void )
{
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Virtual::sendAddr( BYTE addr )
{
  client.poke( "Addr", addr );
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Virtual::writeByte( BYTE byte )
{
  client.poke( "Data", byte );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster_Virtual::readByteAck( void ) // read with acknowledge
{
  return ( readByteNack() );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster_Virtual::readByteNack( void ) // read with no acknowledge
{
  WORD byte;
  client.request( "Data", &byte );
  return ( byte );
}

//EOF
