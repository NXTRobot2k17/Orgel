//
// USB Descriptor File
//


//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
class cHwUSBdesc_0 : public cHwUSBdesc
{
  public:
    //---------------------------------------------------------------
    virtual const BYTE *getDescriptor( WORD id )
    {
      switch( id )
      {
        case 0x0000: return( &descriptor[0] );  // device 
        case 0x0011: return( &descriptor[18] );  // config 
        case 0x0012: return( &descriptor[27] );  // interf 
        case 0x0014: return( &descriptor[36] );  // endpoint 
        case 0x1014: return( &descriptor[43] );  // endpoint 
        case 0x0006: return( &string[0] );  // string 
        case 0x1006: return( &string[12] );  // string 
        case 0x2006: return( &string[32] );  // string 
        case 0x3006: return( &string[46] );  // string 
        case 0x4006: return( &string[56] );  // string 
      }
      return( 0 );
    }

    //---------------------------------------------------------------
    virtual void registerInterface(BYTE confId, BYTE interfId,cHwUSBinterf *interface)
    {
      switch( getId(INTERF,confId,interfId,0) ) 
      {
        case 0x0012: interfaces[0] = interface; break;
      }
    }

    //---------------------------------------------------------------
    virtual cHwUSBinterf *getInterface(BYTE confId, BYTE interfId)
    {
      switch( getId(INTERF,confId,interfId,0) ) 
      {
        case 0x0012: return( interfaces[0] );
      }
      return( 0 );
    }

    //---------------------------------------------------------------
    virtual void registerEndpoint( BYTE epId, cHwUSBendpoint *ep )
    {
      switch( epId ) 
      {
        case 0x81: epList[0] = ep; break;
        case 0x01: epList[1] = ep; break;
      }
    }

    //---------------------------------------------------------------
    virtual cHwUSBendpoint *getEndpoint( BYTE epId )
    {
      switch( epId ) 
      {
        case 0x81: return( epList[0] );
        case 0x01: return( epList[1] );
      }
      return( 0 );
    }

  private:
    //---------------------------------------------------------------
    static const BYTE       descriptor[];
    static const BYTE       string[];
    static const BYTE       report[];
    static cHwUSBinterf    *interfaces[];
    static cHwUSBendpoint  *epList[];
};


//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
const BYTE cHwUSBdesc_0::descriptor[] = 
{
    // DEVICE
    //-------
    18,	// bLength
    1,	// bDescriptorType
    (0x0200)&0xFF,(0x0200)>>8,	// bcdUSB
    0x00,	// bDeviceClass
    0x00,	// bDeviceSubClass
    0x00,	// bDeviceProtocol
    (64),	// bMaxPacketSize0
    (0x0023)&0xFF,(0x0023)>>8,	// idVendor
    (0x1000)&0xFF,(0x1000)>>8,	// idProduct
    (0x0100)&0xFF,(0x0100)>>8,	// bcdDevice
    0,	// iManufacturer
    1,	// iProduct
    2,	// iSerialNumber
    1,	// bNumConfigurations

    // CONFIGURATION
    //--------------
    9,	// bLength
    2,	// bDescriptorType
    0x20,	// wTotalLength
    0x00,	               
    1,	// bNumInterfaces
    1,	// bConfigurationValue
    3,	// iConfiguration
    0x80,	// bmAttributes
    50,	// bMaxPower

    // INTERFACE
    //----------
    9,	// bLength
    4,	// bDescriptorType
    0,	// bInterfaceNumber
    0,	// bAlternateSetting
    2,	// bNumEndpoints
    (VENDOR_SPECIFIC_CLASS),	// bInterfaceClass
    (0),	// bInterfaceSubClass
    (0),	// bInterfaceProtocol
    4,	// iInterface

    // ENDPOINT
    //---------
    7,	// bLength
    5,	// bDescriptorType
    0x81,	// bEndpointAddress
    (INTERRUPT_ENDPOINT),	// bmAttributes
    (10)&0xFF,(10)>>8,	// wMaxPacketSize
    (1),	// bInterval

    // ENDPOINT
    //---------
    7,	// bLength
    5,	// bDescriptorType
    0x01,	// bEndpointAddress
    (INTERRUPT_ENDPOINT),	// bmAttributes
    (32)&0xFF,(32)>>8,	// wMaxPacketSize
    (1),	// bInterval

    0    // Dummy
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
const BYTE cHwUSBdesc_0::string[] = 
{
    // STRING
    12,	// bLength
    3,	// bDescriptorType
    0x48,0x00,	// H
    0x2D,0x00,	// -
    0x42,0x00,	// B
    0x52,0x00,	// R
    0x53,0x00,	// S

    // STRING
    20,	// bLength
    3,	// bDescriptorType
    0x45,0x00,	// E
    0x6D,0x00,	// m
    0x62,0x00,	// b
    0x43,0x00,	// C
    0x70,0x00,	// p
    0x70,0x00,	// p
    0x4C,0x00,	// L
    0x69,0x00,	// i
    0x62,0x00,	// b

    // STRING
    14,	// bLength
    3,	// bDescriptorType
    0x53,0x00,	// S
    0x4E,0x00,	// N
    0x30,0x00,	// 0
    0x30,0x00,	// 0
    0x30,0x00,	// 0
    0x31,0x00,	// 1

    // STRING
    10,	// bLength
    3,	// bDescriptorType
    0x44,0x00,	// D
    0x45,0x00,	// E
    0x4D,0x00,	// M
    0x4F,0x00,	// O

    // STRING
    18,	// bLength
    3,	// bDescriptorType
    0x44,0x00,	// D
    0x65,0x00,	// e
    0x76,0x00,	// v
    0x69,0x00,	// i
    0x63,0x00,	// c
    0x65,0x00,	// e
    0x20,0x00,	//  
    0x30,0x00,	// 0

    0    // Dummy
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
const BYTE cHwUSBdesc_0::report[] = 
{
    0    // Dummy
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
cHwUSBinterf *cHwUSBdesc_0::interfaces[] = 
{
    NULL,
    NULL
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
cHwUSBendpoint *cHwUSBdesc_0::epList[] = 
{
    NULL,
    NULL,
    NULL
};

//EOF
