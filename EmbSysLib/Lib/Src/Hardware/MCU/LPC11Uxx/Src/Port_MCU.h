//*******************************************************************
/*!
\file   Port_MCU.h
\author Thomas Breuer
\date   27.02.2013
*/

//*******************************************************************
#ifndef _HW_PORT_MCU_H
#define _HW_PORT_MCU_H

//*******************************************************************
#include "Hardware/Common/Port.h"

//*******************************************************************
/*! 
\class cHwPort_N

\brief Implementation of the digital port

\example cHwPort.cpp
*/
class cHwPort_N : public cHwPort
{
  public:
    //---------------------------------------------------------------
    typedef enum
    {
      P0 = 0, //!< Use GPIO 0
      P1,     //!< Use GPIO 1
    } PORT_ID;

  public:
    //---------------------------------------------------------------
    /*! Initialize a port
    */
    cHwPort_N( PORT_ID portId //!< Port identifier (P0,...,P4)
             );

   //---------------------------------------------------------------
    virtual void setMode( MTYPE mask, Mode mode ) {}
#warning "function not implemented"



    //---------------------------------------------------------------
    virtual void setPinMode( BYTE pinId, Mode mode ) {}
#warning "function not implemented"

    //---------------------------------------------------------------
//    virtual void setDir( MTYPE mask )
//    {
//      LPC_GPIO->DIR[portID] |= mask;
//    }

    //---------------------------------------------------------------
//    virtual void clrDir( MTYPE mask )
//    {
//      LPC_GPIO->DIR[portID] &= ~mask;
//    }

    //---------------------------------------------------------------
    virtual void set( MTYPE mask )
    {
      LPC_GPIO->SET[portID] = mask;
    }

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value )
    {
#warning "function not implemented"
    }
    //---------------------------------------------------------------
    virtual void clr( MTYPE mask )
    {
      LPC_GPIO->CLR[portID] = mask;
    }

    //---------------------------------------------------------------
    virtual MTYPE get( void )
    {
      return( LPC_GPIO->PIN[portID] );
    }

  private:
    //---------------------------------------------------------------
    volatile BYTE portID;

}; //cHwPort_N

#endif
