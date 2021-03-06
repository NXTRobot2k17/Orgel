//*******************************************************************
/*!
\file   MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Controller specific defines and compiler settings
*/

//*******************************************************************
#ifndef _MCU_H
#define _MCU_H

//*******************************************************************
//-------------------------------------------------------------------
// ARM Cortex-M4
//-------------------------------------------------------------------
//===================================================================
#if defined STM32F405xx
  #define _MCU_DEV_STM32F405
  #define _MCU_TYPE_STM32F4XX

//===================================================================
#elif defined STM32F407xx
  #define _MCU_DEV_STM32F407
  #define _MCU_TYPE_STM32F4XX

//===================================================================
#elif defined STM32F415xx
  #define _MCU_DEV_STM32F415
  #define _MCU_TYPE_STM32F4XX

//-------------------------------------------------------------------
// ARM Cortex-M3
//-------------------------------------------------------------------
//===================================================================
#elif defined STM32L1XX_MDP
  #define _MCU_DEV_STM32L100
  #define _MCU_TYPE_STM32L1XX

//===================================================================
#elif defined LPC1758
  #define _MCU_DEV_LPC1758
  #define _MCU_TYPE_LPC17XX

//-------------------------------------------------------------------
// ARM Cortex-M0
//-------------------------------------------------------------------
//===================================================================
#elif defined  (__ARM_LPC11U35__)
  #define _MCU_DEV_LPC11U35
  #define _MCU_TYPE_LPC11UXX

//-------------------------------------------------------------------
// Other
//-------------------------------------------------------------------
//===================================================================
#elif defined MCU_VIRTUAL
  #define _MCU_DEV_VIRTUAL
  #define _MCU_TYPE_VIRTUAL

//===================================================================
#else
  #error "device type not defined"
#endif
//===================================================================

//===================================================================
#define WINAPI // for future use ...
//===================================================================

//*******************************************************************
#include "Hardware/MCU/System.h"
#include "Std/Std.h"

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_STM32F4XX

  #include "Hardware/MCU/STM32F4xx/MCU_STM32F4xx.h"

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX

  #include "Hardware/MCU/STM32L1xx/MCU_STM32L1xx.h"

//===================================================================
#elif defined _MCU_TYPE_LPC17XX

  #include "Hardware/MCU/LPC17xx/MCU_LPC17xx.h"

//===================================================================
#elif defined _MCU_TYPE_LPC11UXX

  #include "Hardware/MCU/LPC11Uxx/MCU_LPC11Uxx.h"

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL

  #include "Hardware/MCU/Virtual/MCU_Virtual.h"

//===================================================================
#else
  #error "MCU.h: device type not defined"
#endif
//===================================================================

#endif // _MCU_H
