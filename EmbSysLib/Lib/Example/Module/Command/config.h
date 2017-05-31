//*******************************************************************
/*!
\file   Lib/Example/Module/Command/Src/config.h
\author Thomas Breuer
\date   31.01.2013
\brief  Configuration file
*/

//*******************************************************************
cSystem sys;

//==========================
#if defined _MCU_TYPE_ATMEGA
//==========================
  cHwUART_0             uart( cHwUART_0::BR_38400, 10, 10 );
  cHwMemory_EEPROM      memHardware;

//=============================
#elif defined _MCU_TYPE_LPC17XX
//=============================

  cPinConfig::MAP cPinConfig::table[] = 
  {
    cPinConfig::TXD1_P2_0,
    cPinConfig::RXD1_P2_1,
    cPinConfig::END_OF_TABLE
  };

  cHwUART_N             uart( cHwUART_N::UART_1, cHwUART_N::BR_38400, 10, 10 );
  cHwMemory_RAM         memHardware;

//==============================
#elif defined _MCU_TYPE_LPC11UXX
//==============================

  cPinConfig::MAP cPinConfig::table[] = 
  {
    cPinConfig::TXD_P0_19,
    cPinConfig::RXD_P0_18,
    cPinConfig::END_OF_TABLE
  };

  cHwUART_0             uart( cHwUART::BR_38400, 10, 10 );
  cHwMemory_EEPROM      memHardware;
  
//==============================
#elif defined _MCU_TYPE_STM32L1XX
//==============================

  cPinConfig::MAP cPinConfig::table[] = 
  {
    cPinConfig::USART1_TX_PA_9,
    cPinConfig::USART1_RX_PA_10,
    
    cPinConfig::USART3_TX_PC_10,
    cPinConfig::USART3_RX_PC_11,

    cPinConfig::END_OF_TABLE
  };

  cHwUART_N             uart( cHwUART_N::USART_1, cHwUART::BR_38400, 10, 10 );
  cHwMemory_EEPROM      memHardware;

//==============================
#elif defined _MCU_TYPE_STM32F4XX
//==============================

  cPinConfig::MAP cPinConfig::table[] = 
  {
    cPinConfig::USART6_RX_PC_7,
    cPinConfig::USART6_TX_PC_6,
    cPinConfig::END_OF_TABLE
  };

  cHwUART_N             uart( cHwUART_N::USART_6, cHwUART::BR_38400, 10, 10 );
  //cHwMemory_RAM      memHardware;
  cHwMemory_Flash       memHardware( cHwMemory_Flash::SECTOR_4);

//=============================
#elif defined _MCU_TYPE_VIRTUAL
//=============================
//  cHwUART_Stdio         uart( true );
  cHwUART_Serial         uart( "\\\\.\\COM10" );

  cHwClient_DDE         clientPCF8583( "PCF8583_Server", "Info" );
  cHwI2Cmaster_Virtual  i2c          ( clientPCF8583 );
  cHwRAM_PCF8583        memHardware  ( i2c, 0 );

//==========================================
#else
  #error "config.h: device type not defined"
#endif
//==========================================

//EOF
