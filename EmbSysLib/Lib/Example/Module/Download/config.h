//*******************************************************************
/*!
\file   Lib/Example/Module/RTOS/config.h
\author Thomas Breuer
\date   19.03.2016
\brief  Configuration file
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
#include "hardware/Common/Font/Font_8x12.h"

//*******************************************************************
cSystem sys;

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_LPC17XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD1_P2_0,
    RXD1_P2_1,

    // USB
    USB_Dm_P0_30,
    USB_Dp_P0_29,
    USB_UP_LED_P1_18, // GoodLink
    VBUS_P1_30,
    USB_CONNECT_P2_9, // SoftConnect

    // SPI
    SCK1_P0_7,
    MISO1_P0_8,
    MOSI1_P0_9,

    END_OF_TABLE
  };

  cHwUART_N    uart( cHwUART_N::UART_1,
                     cHwUART::BR_9600,
                     100,
                     100 );

  cHwPort_N    port0   ( cHwPort_N::P0 );
  cHwPort_N    port4   ( cHwPort_N::P4 );

  cHwSPImaster_1       spi1        ( cHwSPImaster::CR_8000kHz, cHwSPImaster::CPOL_H_CPHA_H );
  cHwSPImaster::Device spiDisplay  ( spi1, port0, 6 );
  cHwPort::Pin         pinBackLight( port4, 28 );
  cHwDisp_SPFD5408Bspi disp        ( spiDisplay,
                                     pinBackLight ,
                                     fontFont_8x12, // font
                                     2 );           // actual zoom factor

  cDevDisplayChar      lcd  ( disp );

  //*******************************************************************
  cIPC_UART        ipcUART( uart, cCRC::FAST );

  #include "descriptor_VSC.cpp" // Include automatic generated
                                  // descriptor
  cHwUSBdesc_0     desc;
  cHwUSB_0         usb( desc );
  cIPC_USBdevice   ipcUSB( usb, 0/*interfId*/  );

  cHwMemory_Flash  mem0( (BYTE*)0x00070000, (DWORD)0x400 );
  //cHwMemory_EEPROM mem1( 0x0000, 0x400 );
  //cHwEEPROM_24C256 mem1( i2c,0 );
  cHwMemory_RAM mem1;

  cIPC &ipc = ipcUSB;

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // I2C
    I2C2_SCL_PB_10,
    I2C2_SDA_PB_11,

    // UART
    USART1_TX_PA_9,
    USART1_RX_PA_10,

    USART3_TX_PC_10,
    USART3_RX_PC_11,

    // USB
    USBDM_PA_11,
    USBDP_PA_12,

    // SPI
    SPI2_MOSI_PB_15,
    SPI2_MISO_PB_14,
    SPI2_SCK_PB_13,

    END_OF_TABLE
  };

  cHwUART_N    uart( cHwUART_N::USART_1,
                     cHwUART::BR_9600,
                     100,
                     100 );

  cHwUART_N    uart3( cHwUART_N::USART_3,
                     cHwUART::BR_9600,
                     100,
                     100 );

  cHwI2Cmaster_N   i2c( cHwI2Cmaster_N::I2C_2,
                        cHwI2Cmaster::CR_400kHz  );

  cHwPort_N    portB   ( cHwPort_N::PB );
  cHwPort_N    portA   ( cHwPort_N::PA );
  cDevDigital  btn( portA,  0, cDevDigital::InPD, 0 );

  cHwSPImaster_N    spi2( cHwSPImaster_N::SPI_2,
                          cHwSPImaster::CR_2000kHz,
                          cHwSPImaster::CPOL_H_CPHA_H );

  cHwSPImaster::Device spi  ( spi2, portB, 12 );
  cHwDisp_DIP204spi    disp ( spi );
  cDevDisplayChar      lcd  ( disp );

  //*******************************************************************
  cIPC_UART        ipcUART( uart3, cCRC::FAST );

  #include "descriptor_VSC.cpp" // Include automatic generated
                                  // descriptor
  cHwUSBdesc_0     desc;
  cHwUSB_0         usb( desc );
  cIPC_USBdevice   ipcUSB( usb, 0/*interfId*/  );

  cHwMemory_Flash  mem0( (DWORD*)0x08020000, (DWORD)0x400 );
  //cHwMemory_EEPROM mem1( 0x0000, 0x400 );
  //cHwEEPROM_24C256 mem1( i2c,0 );
  cHwMemory_RAM mem1;

  cIPC &ipc = ipcUSB;

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,

    // USB
    OTG_FS_ID_PA_10,
    OTG_FS_DM_PA_11,
    OTG_FS_DP_PA_12,
    
    // ETH
    ETH_MDIO_PA_2,
    ETH_MII_RX_CLK_PA_1,
    ETH_MII_RX_DV_PA_7,
    ETH_MII_RX_ER_PB_10,
    ETH_MII_TX_EN_PB_11,
    ETH_MII_TXD0_PB_12,
    ETH_MII_TXD1_PB_13,
    ETH_MDC_PC_1,
    ETH_MII_RXD0_PC_4,
    ETH_MII_RXD1_PC_5,

    END_OF_TABLE
  };

  cHwUART_N    uart( cHwUART_N::USART_6,
                     cHwUART::BR_9600,
                     100,
                     100 );
  
  cHwMemory_RAM mem0;

  static const cNetAddr<6> myMAC = {0x16,0x20,0x68,0x01,0x02,0x28};
  static const cNetAddr<4> myIP  = //{192,168,1,120};
                                   {169,254,72,40};
                                   //zeroAddr;
  
  cHwTimer_N       timer( cHwTimer_N::TIM_2, 20000 );
  cHwPort_N port( cHwPort_N::PE );
  cHwPort::Pin reset( port, 2 );
  cHwEthernet_MCU net  ( reset, myMAC );
  cNetIP   ip   ( net, myIP, timer );
  cNetICMP icmp ( ip );
  cNetTCP  tcp  ( ip );
  cNetUDP  udp  ( ip );                      // optional (*)
  cNetDHCP dhcp ( udp, "EmbCpp-Webserver" ); // optional (*)
    // (*): not used, if IP-address is predefined

  cISC_TCP    iscTCP( tcp, broadcastAddr, 100, cCRC::FAST );
  
  cISC &isc = iscTCP;
  

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL
//===================================================================
cHwUART_Stdio         uart( true );

cNetWin           net;
cNetTCP tcp( net );
cISC_TCP    iscTCP( tcp, broadcastAddr, 100, cCRC::FAST );
cISC &isc = iscTCP;

//*******************************************************************
cHwMemory_MCU mem0( "mem0.txt", 100000 );
cHwMemory_MCU mem1( "mem1.txt", 100000 );

//===================================================================
#else
  #error "config.h: device type not defined"
#endif
//===================================================================

cDevTextIO_UART com ( uart, 100, 100 );

//EOF
