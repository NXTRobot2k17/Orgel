//*******************************************************************
/*!
\file   I2Cmaster_Virtual.h
\author Thomas Breuer
\date   18.04.2012
*/

//*******************************************************************
#ifndef _HW_I2C_VIRTUAL_H
#define _HW_I2C_VIRTUAL_H
#define _HW_I2C_VIRTUAL_C

//*******************************************************************
#include "Hardware/Common/I2Cmaster.h"
#include "Hardware/Virtual/Client/Client.h"

//*******************************************************************
/*!
\class cHwI2Cmaster_Virtual

\brief Implementation of the I2C interface in master mode (Server)

\example cHwI2Cmaster.cpp
*/
class cHwI2Cmaster_Virtual : public cHwI2Cmaster
{
  public:
    //---------------------------------------------------------------
    /*! Initialize I2C hardware\n
        \param client Reference to a client
    */
    cHwI2Cmaster_Virtual( cHwClient &client );

  private:
    //---------------------------------------------------------------
    virtual void start( void );

    //---------------------------------------------------------------
    virtual void stop( void );

    //---------------------------------------------------------------
    virtual void sendAddr( BYTE addr );

    //---------------------------------------------------------------
    virtual void writeByte( BYTE byte );

    //---------------------------------------------------------------
    virtual BYTE readByteAck( void );

    //---------------------------------------------------------------
    virtual BYTE readByteNack( void );

  private:
    //----------------------------------------
    cHwClient &client;

}; //cHwI2Cmaster_Virtual

#endif
