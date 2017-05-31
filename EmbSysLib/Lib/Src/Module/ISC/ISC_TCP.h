//*******************************************************************
/*!
\file   Module/ISC_TCP.h
\author Thomas Breuer
\date   04.11.2016
*/

//*******************************************************************
#ifndef _ISC_TCP_H
#define _ISC_TCP_H

//*******************************************************************
#include "Module/ISC.h"

//*******************************************************************
/*!
\class cISC_TCP

\brief ISC transport class with TCP

\remark The length of the payload is limited to 64 bytes

\example cISC.cpp
*/
class cISC_TCP : public cISC, public cNetApplication
{
  //*******************************************************************
  #pragma pack(1)
  class cISC_TCP_DATA
  {
    public:
      static const WORD maxLength = 60;

      BYTE id;
      BYTE length;
      WORD crcValue;
      BYTE data[ maxLength ];
  };
  #pragma pack()

  public:
    //---------------------------------------------------------------
    /*! Instantiate an ISC transport object with TCP

        \param
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cISC_TCP( cNetTCP &tcp,
               cNetAddr<4> addr,
               WORD port,
               cCRC::MODE  crcMode = cCRC::SMALL );

    //---------------------------------------------------------------
    /*! Update the ISC transport object

        Checks, if new data are arrived. In that case ISC copies the
        data to identified data object, sets the new data flag and
        calls the related \b update() method.
    */
//    virtual void update( void );

  private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc );

  private:
    //---------------------------------------------------------------
//    cHwUART &uart;
    //---------------------------------------------------------------
    virtual void process( void );

    virtual void update( void );

    virtual void timeout( void ) {}

 //   virtual void addPage( cHTTP_Page *page );

  private:
    //---------------------------------------------------------------
    cNetTCP::Socket socket;

    static const WORD maxLength = 64;

    BYTE     data[maxLength];

    bool     error;
    WORD     errorCnt;
    WORD     crcValue;
    BYTE     idx;
    BYTE     ready;
    BYTE     length;
    BYTE     id;
    BYTE     state;

}; //cISC_TCP

#endif
