//*******************************************************************
/*!
\file   Module/ISC_USBhost.h
\author Thomas Breuer
\date   11.12.2014

\brief
*/

//*******************************************************************
#ifndef _ISC_USB_HOST_H
#define _ISC_USB_HOST_H

//*******************************************************************
#include "lib.h"
#include "Module/ISC.h"
#ifdef USB_ON
#include "USB.h"
#endif
#pragma pack(1)
class cISC_DATA
{
  public:
    static const WORD maxLength = 60;

    BYTE id;
    BYTE length;
    WORD crcValue;
    BYTE data[ maxLength ];
};
    #pragma pack()

//*******************************************************************
/*!
\class cISC_USBhost

\brief ...

*/
class cISC_USBhost : public cISC
{
  public:
    //---------------------------------------------------------------
    /*! ...
    */
    cISC_USBhost( cUSB &usb, BYTE interfId, cCRC::MODE crcMode = cCRC::FAST);

    //---------------------------------------------------------------
    /*! ...
    */
    virtual void update( void );

    //---------------------------------------------------------------
    /*! ...
    */
    virtual void writeStream( BYTE id, BYTE *data, BYTE size, WORD crc );

    public:
    //---------------------------------------------------------------
    cUSB  &usb;

}; //cISC_USBhost

#endif
