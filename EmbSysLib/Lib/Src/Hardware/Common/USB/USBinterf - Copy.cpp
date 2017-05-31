//*******************************************************************
/*!
\file   USBinterf.cpp
\author Thomas Breuer
\date   01.06.2012
*/

//*******************************************************************
// 
// cHwUSBinterf
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSBinterf::cHwUSBinterf( cHwUSB &usbIn, 
                            BYTE    configId, 
                            BYTE    interfId )

:usb(usbIn)

{
  BYTE inId = 0;
  BYTE outId = 0;
  BYTE inSize = 0;
  BYTE outSize = 0;
	
	cUSBdesc::registerInterface(configId, interfId,this);

  if( interfId < cUSBdesc::getConfigNumInterfaces(configId) )
  {
    for(BYTE k=0;k<cUSBdesc::getInterfaceNumEndpoints(configId,interfId);k++)
    {
      BYTE n = cUSBdesc::getEndpointAddress(configId,interfId,k);
      BYTE s = cUSBdesc::getEndpointMaxPacketSize(configId, interfId, k);
      if( n & 0x80 ) // IN
      {
        inId   = n;
        inSize = s;
      }
      else
      {
        outId   = n;
        outSize = s;
      }
    }
  }

  if( inId == 0 )
	{
//    epIN = &usb.epCtrl;
//		epIN->interf = this;
	}
	else
	{
//  usb.epCtrl.interf[n++] = this;
//////  epIN = new cHwUSBendpoint(usb, this, inId, inSize);
//////  usb.registerEP( inId,epIN);
  cHwUSBendpoint *ep = new cHwUSBendpoint(usb, this, inId, inSize);
  usb.registerEP( inId,ep);
	}

  if( outId == 0 )
      // this works well in LPC17xx, but not in ATmega.
      // todo: check outId == 0 and bugfix in "OutInterface()"
  {
//////    epOUT = &usb.epCtrl;
//////		epOUT->interf = this;
  }
  else
  {
//////    epOUT = /*epIN; */ new cHwUSBendpoint(usb, this, outId, outSize);
//////    usb.registerEP(outId,epOUT);
    cHwUSBendpoint *ep = /*epIN; */ new cHwUSBendpoint(usb, this, outId, outSize);
    usb.registerEP(outId,ep);
  }

}
  
//-------------------------------------------------------------------
//void cHwUSBinterf::in( void )
//{
//  if( epDataIN.isEmpty() )
//  {
//		transmit( epDataIN );
//  }
//  epIN->writeData( epDataIN );
//}

////-------------------------------------------------------------------
//void cHwUSBinterf::out( void )
//{

//  static BYTE buf[256];

//  if( epDataOUT.isEmpty()) // new data
//  {
//    epDataOUT = cDataPointer( buf, getReportOUTsize() );
//  }
//  
//  epOUT->readData( epDataOUT );

//  if( epDataOUT.isEmpty())
//  {
//    cDataPointer tmp( buf, getReportOUTsize() );
//    receive( tmp );
//  }
//  epOUT->writeAcknowledge();   // send Acknowledge 
//}


//EOF
