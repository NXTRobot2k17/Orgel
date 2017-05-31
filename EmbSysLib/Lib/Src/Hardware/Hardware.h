//*******************************************************************
/*!
\file   Hardware.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Hardware header files
*/

//*******************************************************************
#ifndef _HARDWARE_H
#define _HARDWARE_H

//*******************************************************************
// Hardware/MCU
//*******************************************************************
#include "Hardware/MCU/MCU.h"

//*******************************************************************
// Hardware/Peripheral
//*******************************************************************
#include "Hardware/Peripheral/DAC_MAX521.h"
#include "Hardware/Peripheral/DAC_MAX5308.h"
#include "Hardware/Peripheral/DAC_MCP4441.h"
#include "Hardware/Peripheral/DAC_MCP4922.h"
#include "Hardware/Peripheral/Disp_SPFD5408Bspi.h"
#include "Hardware/Peripheral/Disp_DIP204.h"
#include "Hardware/Peripheral/Disp_DIP204spi.h"
#include "Hardware/Peripheral/Disp_ILI9341spi.h"
#include "Hardware/Peripheral/Disp_Terminal.h"
#include "Hardware/Peripheral/EEPROM_24C256.h"
#include "Hardware/Peripheral/Ethernet_ENC28J60.h"
#include "Hardware/Peripheral/Port_PCF8574.h"
#include "Hardware/Peripheral/Port_Terminal.h"
#include "Hardware/Peripheral/RAM_PCF8583.h"
#include "Hardware/Peripheral/RS485_MAX48x.h"
#include "Hardware/Peripheral/RTC_PCF8583.h"
#include "Hardware/Peripheral/Touch_ADS7846.h"
#include "Hardware/Peripheral/Touch_STMPE811i2c.h"
#include "Hardware/Peripheral/UART_IP.h"

#include "Hardware/Peripheral/Sensor/Mag_LSM303.h"
#include "Hardware/Peripheral/Sensor/Gyro_L3GD20.h"
#include "Hardware/Peripheral/Sensor/Acc_LSM303.h"

//*******************************************************************
// Hardware/Common
//*******************************************************************
#include "Hardware/Common/ADC.h"
#include "Hardware/Common/DAC.h"
#include "Hardware/Common/Display.h"
#include "Hardware/Common/DisplayGraphic.h"
#include "Hardware/Common/DisplayFont.h"
#include "Hardware/Common/Encoder.h"
#ifndef _MCU_TYPE_VIRTUAL
 #include "Hardware/Common/Ethernet.h"
#endif
#include "Hardware/Common/I2Cmaster.h"
#include "Hardware/Common/Memory.h"
#include "Hardware/Common/Net.h"
#include "Hardware/Common/Port.h"
#include "Hardware/Common/RTC.h"
#include "Hardware/Common/SPImaster.h"
#include "Hardware/Common/Timer.h"
#include "Hardware/Common/UART.h"
#include "Hardware/Common/USB.h"
#endif
