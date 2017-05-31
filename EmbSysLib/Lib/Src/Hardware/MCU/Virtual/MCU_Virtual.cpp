//*******************************************************************
/*!
\file   MCU_Virtual.cpp
\author Thomas Breuer
\date   15.04.2014

\brief Include controller specific source code

All controller specific source files are included here.
*/

//*******************************************************************
#include "Sys/System.cpp"
#include "Sys/RTOS_MCU.cpp"

#include "Src/Memory_MCU.cpp"
#include "Src/Net_MCU.cpp"
#include "Src/RTC_MCU.cpp"
#include "Src/Timer_MCU.cpp"
#include "Src/UART_MCU.cpp"

#include "Src/ADC_Virtual.cpp"
#include "Src/DAC_Virtual.cpp"
#include "Src/DispChar_Virtual.cpp"
#include "Src/Disp_Virtual.cpp"
//#include "Hardware/Virtual/I2Cmaster_Virtual.cpp"
#include "Src/Port_Virtual.cpp"
//#include "Hardware/Virtual/UART_Virtual.cpp"
#include "Src/Touch_Virtual.cpp"

//*******************************************************************
// HARDWARE/VIRTUAL/CLIENT
//*******************************************************************
//#include "Hardware/Virtual/Client/Client.cpp"
#if defined _MCU_TYPE_VIRTUAL
 // #include "Hardware/Virtual/Client/Client_DDE.cpp"
 // #include "Hardware/Virtual/Client/Client_IP.cpp"
#endif
//#include "Hardware/Virtual/Client/Client_UART.cpp"

//EOF
