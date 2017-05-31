//*******************************************************************
/*!
\file   Hardware.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief Summary of Hardware related code
*/

//*******************************************************************
// Hardware/Common
//*******************************************************************
#include "Hardware/Common/ADC.cpp"
#include "Hardware/Common/DAC.cpp"
#include "Hardware/Common/Display.cpp"
#include "Hardware/Common/DisplayGraphic.cpp"
#include "Hardware/Common/DisplayFont.cpp"
#include "Hardware/Common/Encoder.cpp"
#ifndef _MCU_TYPE_VIRTUAL
 #include "Hardware/Common/Ethernet.cpp"
#endif
#include "Hardware/Common/I2Cmaster.cpp"
#include "Hardware/Common/I2Cslave.cpp"
#include "Hardware/Common/Memory.cpp"
#include "Hardware/Common/Net.cpp"
#include "Hardware/Common/Port.cpp"
#include "Hardware/Common/RTC.cpp"
#include "Hardware/Common/SPImaster.cpp"
#include "Hardware/Common/SPIslave.cpp"
#include "Hardware/Common/Timer.cpp"
#include "Hardware/Common/Touch.cpp"
#include "Hardware/Common/UART.cpp"
#include "Hardware/Common/USB.cpp"

//*******************************************************************
// Hardware/MCU
//*******************************************************************
#include "Hardware/MCU/MCU.cpp"

//*******************************************************************
// Hardware/Peripheral
//*******************************************************************

#include "Hardware/Peripheral/Disp_DIP204.cpp"
#include "Hardware/Peripheral/Disp_DIP204spi.cpp"
#include "Hardware/Peripheral/Disp_ILI9341spi.cpp"
#include "Hardware/Peripheral/Disp_SPFD5408Bspi.cpp"
#include "Hardware/Peripheral/Disp_Terminal.cpp"
#include "Hardware/Peripheral/DAC_MAX5308.cpp"
#include "Hardware/Peripheral/DAC_MAX521.cpp"
#include "Hardware/Peripheral/DAC_MCP4441.cpp"
#include "Hardware/Peripheral/DAC_MCP4922.cpp"
#include "Hardware/Peripheral/EEPROM_24C256.cpp"
#ifndef _MCU_TYPE_VIRTUAL
  #include "Hardware/Peripheral/Ethernet_ENC28J60.cpp"
#endif
#include "Hardware/Peripheral/Port_PCF8574.cpp"
#include "Hardware/Peripheral/Port_Terminal.cpp"
#include "Hardware/Peripheral/RAM_PCF8583.cpp"
#include "Hardware/Peripheral/RS485_MAX48x.cpp"
#include "Hardware/Peripheral/RTC_PCF8583.cpp"
#include "Hardware/Peripheral/Touch_ADS7846.cpp"
#include "Hardware/Peripheral/Touch_STMPE811i2c.cpp"
#include "Hardware/Peripheral/UART_IP.cpp"

//*******************************************************************
// HARDWARE/PERIPHERAL/SENSOR
//*******************************************************************
#include "Hardware/Peripheral/Sensor/Mag_LSM303.cpp"
#include "Hardware/Peripheral/Sensor/Acc_LSM303.cpp"
#include "Hardware/Peripheral/Sensor/Gyro_L3GD20.cpp"

// EOF
