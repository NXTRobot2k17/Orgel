//*******************************************************************
/*!
\file   cDownload.cpp
\author Thomas Breuer
\date   24.05.2016
\brief  Download sample code
*/

//*******************************************************************
#include "lib.h"
#ifndef _MCU_TYPE_VIRTUAL
#include "Module/USB/USBinterfClassVSC.h"
#endif
#include "Module/ISC.h"
#include "Module/Download.h"
#include "config.h"

//*******************************************************************
class myDownloadInterface : public cDownload::Interface
{
  public:
    //---------------------------------------------------------------
    myDownloadInterface( cDownload &download, cHwMemory &mem )
    : cDownload::Interface(download, mem)
    {
    }

    //---------------------------------------------------------------
    virtual bool onStart()
    {
      com.printf("started\r\n");
      return( true );
    }

    //---------------------------------------------------------------
    virtual void onReady()
    {
      com.printf("ready (size=%lu)\r\n", getSize());
    }

    //---------------------------------------------------------------
    virtual void dump( void )
    {
      com.printf("\r\n-----------------\r\n" );
      for( DWORD i=0;i<getSize();i++ )
      {
        com.printf("%c",mem.read(i));
      }
      com.printf("\r\n-----------------\r\n" );
    }
};

//*******************************************************************
cDownload           download  ( isc );
myDownloadInterface interface0( download, mem0 );
//myDownloadInterface interface1( download, mem1 );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

#ifndef _MCU_TYPE_VIRTUAL
//  usb.start();
#endif
  while( 1 )
  {
    //////////////////////////
//    isc.update();
  ////////////////////////////
  net.update();

    if( interface0.isNew() )
    {
       interface0.dump();
    }

//    if( interface1.isNew() )
//    {
//      interface1.dump();
//    }
  }
}

//EOF
