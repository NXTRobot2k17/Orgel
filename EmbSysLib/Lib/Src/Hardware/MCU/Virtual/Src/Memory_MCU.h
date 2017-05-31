//*******************************************************************
/*!
\file   Memory_MCU.h
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
#ifndef _HW_MEMORY_MCU_H
#define _HW_MEMORY_MCU_H

//*******************************************************************
#include "Hardware/Common/Memory.h"

//*******************************************************************
/*!
\class cHwMemory_MCU

\brief Implementation of ...

\example cHwMemory.cpp
*/
class cHwMemory_MCU : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize ...
    */
    cHwMemory_MCU( char *filename, DWORD size = 0 );

  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

    //---------------------------------------------------------------
    virtual void lock( ) {}
    virtual void unlock() {}

  private:
    //---------------------------------------------------------------
    DWORD *ptr;
    int    fh;

}; //cHwMemory_MCU

#endif
