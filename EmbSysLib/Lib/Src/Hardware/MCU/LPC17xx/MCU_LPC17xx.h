//*******************************************************************
/*!
\file   LPC17xx.h
\author Thomas Breuer
\date   11.03.2011

\brief Include controller specific header files

All controller specific header files are included here.
*/

//*******************************************************************
#ifndef _HW_LPC17XX_H
#define _HW_LPC17XX_H

//*******************************************************************
#include <inttypes.h>
#include "Sys/LPC17xx.H"
#include <stdlib.h>

//******************************************************************
//
// Summary of clock configuration in system_LPC17xx.cpp"
//
// These constants doesn't affect the PLCK settings.
// If other clock settings are used, all constants and their use in
// "Hardware/Src" have to be checked.
//
#define system_PCLK          (100000000)
#define system_PCLK_SYSTIC   (system_PCLK)
#define system_PCLK_TIM      (system_PCLK/4)
#define system_PCLK_I2C      (system_PCLK/4)
#define system_PCLK_SPI      (system_PCLK/4)
#define system_PCLK_UART     (system_PCLK/4)
#define system_PCLK_ADC      (system_PCLK/4)

//*******************************************************************
typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef uint32_t   MTYPE;

//*******************************************************************
inline void* operator new[]    ( unsigned int  x ) { return malloc(x); }
inline void* operator new      ( unsigned int  x ) { return malloc(x); }
inline void  operator delete[] ( void         *x ) { if(x) free(x);    }
inline void  operator delete   ( void         *x ) { if(x) free(x);    }

//*******************************************************************
#define PROGMEM // nothing to do
#define GET_BYTE_PROGMEM(varName)       (varName)
#define GET_BYTE_PROGMEM_PTR(ptrName)   (*(ptrName))

//*******************************************************************
#include "Sys/PinConfig.h"
#include "Sys/RTOS_MCU.h"

//*******************************************************************
#include "Src/ADC_MCU.h"
#include "Src/DAC_MCU.h"
#include "Src/EThernet_MCU.h"
#include "Src/I2Cmaster_MCU.h"
#include "Src/Memory_Flash.h"
#include "Src/Memory_RAM.h"
#include "Src/Port_MCU.h"
#include "Src/RTC_MCU.h"
#include "Src/SPImaster_MCU.h"
#include "Src/Timer_MCU.h"
#include "Src/UART_MCU.h"
#include "Src/USB_MCU.h"

#endif //_HW_LPC17XX_H
