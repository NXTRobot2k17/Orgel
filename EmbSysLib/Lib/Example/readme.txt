Example and test conditions
===========================

LPC17xx
=========
IDE:         µVision 4.74

Test board:  MCB-1700 Keil

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
             | Joystick    | P1.26| GPIO
             | Joystick    | P1.24| GPIO
             | Joystick    | P1.20| GPIO
             | LED         | P2.2 | GPIO,PWM
             | LED         | P2.3 | GPIO
             | USB         | P0.30| USB-DM
             | USB         | P0.29| USB-DP
             | Com-Port    | P2.1 | UART1-RX
             | Com-Port    | P2.0 | UART1-TX
 ------------|-------------|------|------------
             | Analog In   | P0.25| ADC-CH2
             | Analog Out  | P0.26| DAC
 ------------|-------------|------|------------
             | LCD         | P0.9 | SPI2-MOSI
             | LCD         | P0.8 | SPI2-MISO
             | LCD         | P0.7 | SPI2-SCK
             | LCD         | P0.6 | GPIO (SS)
             | LCD (light) | P4.28| GPIO


STM32L1xx
=========
IDE:         µVision 4.74

Test board:  32L100C-DISCOVERY (STMicroelectronics)

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
             | USER-button | PA0  | GPIO
             | LED blue    | PC8  | GPIO
             | LED green   | PC9  | GPIO
             | USB         | PA11 | USB-DM
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------
 Com-Port    |             | PA9  | UART1-RX
 Com-Port    |             | PA10 | UART1-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA4  | DAC-CH1
 Push button |             | PC0  | GPIO
 ------------|-------------|------|------------
 LCD         |             | PB15 | SPI2-MOSI
 LCD         |             | PB14 | SPI2-MISO
 LCD         |             | PB13 | SPI2-SCK
 LCD         |             | PB12 | GPIO (SS)


STM32F4xx
=========
IDE:         µVision 4.74

Test board:  STM32F4-DISCOVERY (STMicroelectronics)

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
             | LED blue    | PD15 | GPIO
             | LED green   | PD12 | GPIO
             | USER-button | PA0  | GPIO
             | USB         | PA12 | USB-DP
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------
 Com-Port    |             | PC7  | USART6-RX
 Com-Port    |             | PC6  | USART6-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA5  | DAC-CH2
 Push button |             | PA1  | GPIO
 ------------|-------------|------|------------
 LCD         |             | PC3  | SPI2-MOSI
 LCD         |             | PC2  | SPI2-MISO
 LCD         |             | PB10 | SPI2-SCK
 LCD         |             | PB14 | GPIO (SS)
