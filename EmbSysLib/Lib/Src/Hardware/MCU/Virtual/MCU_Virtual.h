//*******************************************************************
/*!
\file   MCU_Virtual.h
\author Thomas Breuer
\date   15.04.2014

\brief Include controller specific header files

All controller specific header files are included here.
*/

//*******************************************************************
#ifndef _HW_MCU_VIRTUAL_H
#define _HW_MCU_VIRTUAL_H

//*******************************************************************
#include <inttypes.h>
#include <stdlib.h>

//*******************************************************************
typedef uint8_t              BYTE;
typedef uint16_t             WORD;
typedef long unsigned int   DWORD;
typedef uint32_t            MTYPE;

//*******************************************************************
#define PROGMEM // nothing to do
#define GET_BYTE_PROGMEM(varName)       (varName)
#define GET_BYTE_PROGMEM_PTR(ptrName)   (*(ptrName))


#define __packed
//*******************************************************************
#include "Sys/RTOS_MCU.h"

#include "Src/Memory_MCU.h"
#include "Src/Net_MCU.h"
#include "Src/RTC_MCU.h"
#include "Src/Timer_MCU.h"
#include "Src/UART_MCU.h"

//*******************************************************************
#include "Src/ADC_Virtual.h"
#include "Src/DAC_Virtual.h"
#include "Src/Disp_Virtual.h"
#include "Src/DispChar_Virtual.h"
//#include "Hardware/Virtual/I2Cmaster_Virtual.h"
#include "Src/Port_Virtual.h"
#include "Src/Touch_Virtual.h"
//#include "Hardware/Virtual/UART_Virtual.h"

//#include "Hardware/Virtual/Client/Client_UART.h"

#if defined _MCU_TYPE_VIRTUAL
  ///#include "Hardware/Virtual/Client/Client_DDE.h"
  //#include "Hardware/Virtual/Client/Client_IP.h"
#endif


#endif //_HW_MCU_VIRTUAL_H
