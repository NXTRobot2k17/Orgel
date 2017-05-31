//*******************************************************************
/*!
\file   cISC.cpp
\author Thomas Breuer
\date   18.03.2016
\brief  ISC sample code
*/

//*******************************************************************
#include "lib.h"
#ifndef _MCU_TYPE_VIRTUAL
#include "Module/USB/USBinterfClassVSC.h"
#endif
#include "Module/ISC.h"
#include "config.h"

//*******************************************************************
#ifndef _MCU_TYPE_VIRTUAL
#include "descriptor.cpp" // Include automatic generated
                          // descriptor
//*******************************************************************
cHwUSBdesc_0   desc;
cHwUSB_0       usb( desc );
#endif

//*******************************************************************
class myData
{
  public:
    //---------------------------------------------------------------
    #pragma pack(1)
    class Data
    {
      public:
        Data() {cnt=0;rec=0;random=0;}
        DWORD cnt;
        DWORD rec;
        DWORD random;
    } data;
    #pragma pack()

    //---------------------------------------------------------------
    myData() {recCnt=0;}

    //---------------------------------------------------------------
    virtual void update()
    {
      recCnt++;
    }

    //---------------------------------------------------------------
    DWORD recCnt;
};

//*******************************************************************
cISC_UART             ISCUART( uart, cCRC::FAST );
cISC::Data<myData, 1> outUART( ISCUART  );
cISC::Data<myData, 2> inUART ( ISCUART  );

//*******************************************************************
  //##########################################
  #ifdef _MCU_TYPE_VIRTUAL
    cNetWin           net;
    cNetTCP tcp( net );

  //##########################################
  #else
    cNetIP   ip   ( net, myIP, timer );
    cNetICMP icmp ( ip );
    cNetTCP  tcp  ( ip );
    cNetUDP  udp  ( ip );                      // optional (*)
    cNetDHCP dhcp ( udp, "EmbCpp-Webserver" ); // optional (*)
    // (*): not used, if IP-address is predefined

  #endif


cISC_TCP              ISCTCP ( tcp, broadcastAddr, 100, cCRC::FAST );
cISC::Data<myData, 1> outTCP ( ISCTCP  );
cISC::Data<myData, 2> inTCP  ( ISCTCP  );


#ifndef _MCU_TYPE_VIRTUAL
cISC_USBdevice         ISCUSB( usb, 0, cCRC::FAST );
cISC::Data<myData, 11> outUSB( ISCUSB  );
cISC::Data<myData, 12> inUSB ( ISCUSB  );
#endif

//*******************************************************************
int main(void)
{
#ifndef _MCU_TYPE_VIRTUAL
  usb.start();
#endif

  while( 1 )
  {
    // ISC-UART
    ISCUART.update();

    if( inUART.isNew() )
    {
      outUART.data.cnt++;
      outUART.data.rec    =  inUART.prop.recCnt;
      outUART.data.random = -inUART.data.random;

      outUART.write();
    }

    // ISC-TCP
 //   ISCTCP.update();
 net.update();

    if( inTCP.isNew() )
    {
      outTCP.data.cnt++;
      outTCP.data.rec    =  inTCP.prop.recCnt;
      outTCP.data.random = -inTCP.data.random;

      outTCP.write();
    }

#ifndef _MCU_TYPE_VIRTUAL
    // ISC-USB
    ISCUSB.update();

    if( inUSB.isNew() )
    {
      outUSB.data.cnt++;
      outUSB.data.rec    =  inUSB.prop.recCnt;
      outUSB.data.random = -inUSB.data.random;

      outUSB.write();
    }
#endif
  }
}

//EOF
