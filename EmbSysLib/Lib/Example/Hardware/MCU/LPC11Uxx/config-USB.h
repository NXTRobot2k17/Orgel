//
// Lib/Example/Hardware/MCU/LPC17xx/Src/config.h
// ---------------------------------------------
//

//*******************************************************************
#ifdef _HEADER_ONLY

  #include "Hardware/Common/ADC.h"
  #include "Hardware/Common/DAC.h"
  #include "Hardware/Common/I2Cmaster.h"
  #include "Hardware/Common/Memory.h"
  #include "Hardware/Common/Port.h"
  #include "Hardware/Common/RTC.h"
  #include "Hardware/Common/SPImaster.h"
  #include "Hardware/Common/Timer.h"
  #include "Hardware/Common/UART.h"

  #include "Hardware/Common/USB.h"
  #include "Hardware/Common/USB/USBinterfClassHID.h"

  //<! \todo Vorlaeufige Loesung:
  #define HID_IN_SIZE   16
  #define HID_OUT_SIZE  16


  
//*******************************************************************
#else

  cSystem sys;

  //<! \todo Vorlaeufige Loesung:
  cHwUSB_0  usb;
  #include "descriptor.cpp"

  cHwUART_1 uart(cHwUART_1::BR_38400,100,100);
  
  char str[40];



#endif
