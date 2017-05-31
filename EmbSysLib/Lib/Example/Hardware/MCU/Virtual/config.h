//*******************************************************************
/*!
\file   Lib/Example/Hardware/Virtual/Src/config.h
\author Thomas Breuer
\date   31.01.2013
\brief  Configuration file
*/

//*******************************************************************
  cSystem sys;

  //==========================================
  #if defined _MCU_TYPE_ATMEGA

    cHwUART_0       uart        ( cHwUART_0::BR_115200, 10, 10 );
    cHwClient_UART  clientStdio ( uart, "StdioServer", "Info" );
    cHwUART_Virtual stdio       ( clientStdio );

  //==========================================
  #elif defined _MCU_TYPE_LPC17XX

  cPinConfig::MAP cPinConfig::table[]

  = {
      cPinConfig::TXD1_P2_0,
      cPinConfig::RXD1_P2_1,

      cPinConfig::END_OF_TABLE
  };

    cHwUART_N       uart        ( cHwUART_N::UART_1, cHwUART_N::BR_115200, 100, 100 );
    cHwClient_UART  clientStdio ( uart, "StdioServer", "Info" );
    cHwUART_Virtual stdio       ( clientStdio );

  //==========================================
  #elif defined _MCU_TYPE_LPC11UXX

    cPinConfig::MAP cPinConfig::table[] =
    {
      cPinConfig::TXD_P0_19,
      cPinConfig::RXD_P0_18,
      cPinConfig::END_OF_TABLE
    };

    cHwUART_0       uart        ( cHwUART::BR_115200, 100, 100 );
    cHwClient_UART  clientStdio ( uart, "StdioServer", "Info" );
    cHwUART_Virtual stdio       ( clientStdio );

  //==========================================
  #elif defined _MCU_TYPE_STM32L1XX

    cPinConfig::MAP cPinConfig::table[] =
    {
      cPinConfig::USART1_TX_PA_9,
      cPinConfig::USART1_RX_PA_10,
      cPinConfig::END_OF_TABLE
    };

    cHwUART_N       uart        ( cHwUART_N::USART_1, cHwUART::BR_115200, 100, 100 );
    cHwClient_UART  clientStdio ( uart, "StdioServer", "Info" );
    cHwUART_Virtual stdio       ( clientStdio );

  //==========================================
  #elif defined _MCU_TYPE_STM32F4XX

    cPinConfig::MAP cPinConfig::table[] =
    {
      cPinConfig::USART6_RX_PC_7,
      cPinConfig::USART6_TX_PC_6,
      cPinConfig::END_OF_TABLE
    };


    cHwUART_N      uart         ( cHwUART_N::USART_6, cHwUART::BR_115200, 100, 100 );
    cHwClient_IP  clientStdio ( uart, "StdioServer", "Info" );
    cHwUART_Virtual stdio       ( clientStdio );

  //==========================================
  #elif defined _MCU_TYPE_VIRTUAL
//cSystemNet sysNet;
    cHwUART_Stdio uart;

  //==========================================
  #else
    #error "config.h: device type not defined"
  #endif

//********************************************
//EOF
