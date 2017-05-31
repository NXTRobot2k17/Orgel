//*******************************************************************
/*!
\file   Lib/Example/main.cpp
\author Thomas Breuer
\date   15.02.2013, 17.03.2016
\brief  Samples
*/

//*******************************************************************
// Uncomment the desired example file.
//*******************************************************************

//-------------------------------------------------------------------
// Hardware - MCU - LPC11Uxx
//-------------------------------------------------------------------
//
//                                                           Test
//
//#include "Hardware/MCU/LPC11Uxx/cHwADC_MCU.cpp"            // ok
//#include "Hardware/MCU/LPC11Uxx/cHwI2Cmaster_MCU.cpp"      // ok
//#include "Hardware/MCU/LPC11Uxx/cHwMemory_EEPROM.cpp"      // ok
//#include "Hardware/MCU/LPC11Uxx/cHwPort_MCU.cpp"           // ok
//#include "Hardware/MCU/LPC11Uxx/cHwSPImaster_MCU.cpp"      // ok
//#include "Hardware/MCU/LPC11Uxx/cHwTimer_MCU.cpp"          // ok
//#include "Hardware/MCU/LPC11Uxx/cHwUART_MCU.cpp"           // ok
//#include "Hardware/MCU/LPC11Uxx/cHwUSB_MCU.cpp"            // ok
//#include "Hardware/MCU/LPC11Uxx/cSystem.cpp"               // ok

//-------------------------------------------------------------------
// Hardware - MCU - LPC17xx
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/LPC17xx/cHwADC_MCU.cpp"            //
//#include "Hardware/MCU/LPC17xx/cHwDAC_MCU.cpp"            //
//#include "Hardware/MCU/LPC17xx/cHwI2Cmaster_MCU.cpp"      //
//#include "Hardware/MCU/LPC17xx/cHwMemory_Flash.cpp"       //
//#include "Hardware/MCU/LPC17xx/cHwMemory_RAM.cpp"         //
//#include "Hardware/MCU/LPC17xx/cHwPort_MCU.cpp"           //
//#include "Hardware/MCU/LPC17xx/cHwRTC_MCU.cpp"            //
//#include "Hardware/MCU/LPC17xx/cHwRTOS_MCU.cpp"           //
//#include "Hardware/MCU/LPC17xx/cHwSPImaster_MCU.cpp"      //
//#include "Hardware/MCU/LPC17xx/cHwTimer_MCU.cpp"          //
//#include "Hardware/MCU/LPC17xx/cHwUART_MCU.cpp"           //
//#include "Hardware/MCU/LPC17xx/cHwUSB_MCU.cpp"            //
//#include "Hardware/MCU/LPC17xx/cSystem_MCU.cpp"           //

//-------------------------------------------------------------------
// Hardware - MCU - STM32L1xx
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/STM32L1xx/cHwADC_MCU.cpp"            //
//#include "Hardware/MCU/STM32L1xx/cHwDAC_MCU.cpp"            //
//#include "Hardware/MCU/STM32L1xx/cHwEncoder_MCU.cpp"        //
//#include "Hardware/MCU/STM32L1xx/cHwI2Cmaster_MCU.cpp"      //
//#include "Hardware/MCU/STM32L1xx/cHwMemory_EEPROM.cpp"      //
//#include "Hardware/MCU/STM32L1xx/cHwMemory_Flash.cpp"       //
//#include "Hardware/MCU/STM32L1xx/cHwMemory_RAM.cpp"         //
//#include "Hardware/MCU/STM32L1xx/cHwPort_MCU.cpp"           //
//#include "Hardware/MCU/STM32L1xx/cHwRTC_MCU.cpp"            //
//#include "Hardware/MCU/STM32L1xx/cHwRTOS_MCU.cpp"           //
//#include "Hardware/MCU/STM32L1xx/cHwSPImaster_MCU.cpp"      //
//#include "Hardware/MCU/STM32L1xx/cHwTimer_MCU.cpp"          //
//#include "Hardware/MCU/STM32L1xx/cHwUART_MCU.cpp"           //
//#include "Hardware/MCU/STM32L1xx/cHwUSB_MCU.cpp"            //
//#include "Hardware/MCU/STM32L1xx/cSystem_MCU.cpp"           //

//-------------------------------------------------------------------
// Hardware - MCU - STM32F4xx
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/STM32F4xx/cHwADC_MCU.cpp"            //
//#include "Hardware/MCU/STM32F4xx/cHwDAC_MCU.cpp"            //
//#include "Hardware/MCU/STM32F4xx/cHwEncoder_MCU.cpp"        //
//#include "Hardware/MCU/STM32F4xx/cHwI2Cmaster_MCU.cpp"      //
//#include "Hardware/MCU/STM32F4xx/cHwMemory_RAM.cpp"         //
//#include "Hardware/MCU/STM32F4xx/cHwMemory_Flash.cpp"       //
//#include "Hardware/MCU/STM32F4xx/cHwPort_MCU.cpp"           //
//#include "Hardware/MCU/STM32F4xx/cHwRTC_MCU.cpp"            //
//#include "Hardware/MCU/STM32F4xx/cHwRTOS_MCU.cpp"           //
//#include "Hardware/MCU/STM32F4xx/cHwSPImaster_MCU.cpp"      //
//#include "Hardware/MCU/STM32F4xx/cHwTimer_MCU.cpp"          //
//#include "Hardware/MCU/STM32F4xx/cHwUART_MCU.cpp"           //
//#include "Hardware/MCU/STM32F4xx/cHwUSB_MCU.cpp"            //
//#include "Hardware/MCU/STM32F4xx/cSystem_MCU.cpp"           //

//-------------------------------------------------------------------
// Hardware - MCU - Virtual
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/Virtual/cHwNet_MCU.cpp"              //
//#include "Hardware/MCU/Virtual/cHwADC_Virtual.cpp"              //
//#include "Hardware/MCU/Virtual/cHwDAC_Virtual.cpp"              //
//#include "Hardware/MCU/Virtual/cHwPort_Virtual.cpp"             //
//#include "Hardware/MCU/Virtual/cHwDispChar_Virtual.cpp"         //
//#include "Hardware/MCU/Virtual/cHwDisp_Virtual.cpp"             //
//#include "Hardware/MCU/Virtual/cHwTouch_Virtual.cpp"             //
//#include "Hardware/MCU/Virtual/cHwUART_MCU.cpp"                 //

//-------------------------------------------------------------------
// Hardware - Peripheral
//-------------------------------------------------------------------
// Cross mapping of supported peripheral hardware and sample code
//
// legend:
//
//    yes    target supports the peripheral device
//    no     no support
//    no*    not yet, but maybe in future
//    nt     not tested
//    (y)    yes, but not tested or properly configured
//
//                                                   Target:  +STM32L1
//                                                            |   +STM32F4
//                                                            |   |   +LPC1758
//                                                            |   |   |
//#include "Hardware/Peripheral/cHwDisp_DIP204spi.cpp"    // --- --- ---
//#include "Hardware/Peripheral/cHwDisp_SPFD5408Bspi.cpp" // --- --- ---
//#include "Hardware/Peripheral/cHwDisp_Terminal.cpp" // --- --- ---
//#include "Hardware/Peripheral/cHwUART_IP.cpp"           // --- --- ---

//-------------------------------------------------------------------
//
//                                          Target:  +STM32L1
//                                                   |   +STM32F4
//                                                   |   |   +LPC1758
//                                                   |   |   |
// Device                                            |   |   |
// ------                                            |   |   |
//#include "Device/cDevAnalog.cpp"               // --- --- ---
//#include "Device/cDevDigital.cpp"              // --- --- ---
//#include "Device/cDevDisplayChar.cpp"          // --- --- ---
//#include "Device/cDevDisplayGraphic.cpp"       // --- --- ---
//#include "Device/cDevControlEncoder.cpp"       // --- --- ---
//#include "Device/cDevMemoryFlash.cpp"          // no* --- ---
//
#include "Device/cDevTextIO.cpp"               // --- --- ---
//                                                   |   |
// Module                                            |   |
// ------                                            |   |
//#include "Module/ISC/cISC.cpp"                 // --- --- ---
//#include "Module/RTOS/cRTOS.cpp"               // --- --- ---
//#include "Module/USB/cUSBinterfClassVSC.cpp"   // --- --- ---
//#include "Module/Download/cDownload.cpp"       // --- --- ---
//#include "Module/HTTP/cHTTP.cpp"               // no* --- ---
//#include "Module/LUA/cLUA.cpp"                   // no* --- ---

//                                                   |   |
// Std                                               |   |
// ---                                               |   |
//#include "Std/cCRC.cpp"                        // --- --- ---
//#include "Std/cFifo.cpp"                       // --- --- ---
//#include "Std/cList.cpp"                       // --- --- ---
//#include "Std/cSharedMem.cpp"                  // --- --- ---
//#include "Std/cTimer.cpp"                      // --- --- ---
//                                                   |   |
// Task                                              |   |
// ----                                              |   |
//#include "Task/cTaskHandler.cpp"               // --- --- ---

//EOF
