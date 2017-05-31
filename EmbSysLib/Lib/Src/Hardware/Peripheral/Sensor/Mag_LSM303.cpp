//*******************************************************************
/*!
\file   Mag_LSM303.cpp
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
// 
// cHwSensMag_LSM303
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSensMag_LSM303::cHwSensMag_LSM303( cHwI2Cmaster &i2cIn )

: i2c( i2cIn, hwAddr )

{
  // Control Register A (CRA_REG_M)
  i2c.write(  (BYTE)0x00,  (1<<7)  // Temperature Sensor enable: ON 
                                 |(6<<2));// Data output rate:          75Hz

  // Control Register B (CRB_REG_M)
  i2c.write(  (BYTE)0x01, (0<<5)); // Gain setting: 1.3 Gauss

  // Mode Register
  i2c.write(  (BYTE)0x02, (0<<0)); // Operating mode: continuous conversion

}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::readWord( BYTE addr )
{
  WORD data;
  
  data  = ((WORD)i2c.read(  (BYTE)(addr  ) )) << 8;
  data |=        i2c.read(  (BYTE)(addr+1) );
  
  return( data );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getX( void )
{
  return( readWord( 0x03 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getY( void )
{
  return( readWord( 0x07 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getZ( void )
{
  return( readWord( 0x05 ) );
}

// EOF
