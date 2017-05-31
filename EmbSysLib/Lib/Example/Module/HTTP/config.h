//*******************************************************************
/*!
\file   Lib/Example/Module/HTTP/Src/config.h
\author Thomas Breuer
\date   15.05.2014
\brief  Configuration file
*/

//*******************************************************************
cSystem sys;

//==========================================
#if defined _MCU_TYPE_LPC17XX
//==========================================

  cHwPinConfig::MAP cHwPinConfig::table[] =
  {
    // UART
    TXD1_P2_0,
    RXD1_P2_1,

    // ADC
    AD0_2_P0_25,

    END_OF_TABLE
  };


  static const cNetAddr<6> myMAC = {0x16,0x20,0x68,0x01,0x02,0x28};
  static const cNetAddr<4> myIP  = //{192,168,1,120};
                                   zeroAddr;

  cHwTimer_N       timer( cHwTimer_N::TIM_0, 20000 );
  cHwUART_N        uart ( cHwUART_N::UART_1, cHwUART::BR_38400, 100, 100 );

  cHwEthernet_EMAC net  ( myMAC );

  cHwADC_0               adc     ( &timer );
  cDevAnalogInADC     in  ( adc,      2,      3.0, 0.0 );

#include "content.h"
  cHwMemory_Flash   contentMem( (BYTE*)content, 0xFFFF );

//==========================================
#elif defined _MCU_TYPE_STM32F4XX
//==========================================
cHwPinConfig::MAP cHwPinConfig::table[] = 
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,
    
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
  
  cHwPort_N port( cHwPort_N::PE );
  cHwPort::Pin reset( port, 2 );

  static const cNetAddr<6> myMAC = {0x16,0x20,0x68,0x01,0x02,0x28};
  static const cNetAddr<4> myIP  = //{192,168,1,120};
                                   zeroAddr;

  cHwTimer_N       timer( cHwTimer_N::TIM_2, 20000 );
  cHwUART_N              uart    ( cHwUART_N::USART_6, cHwUART::BR_38400, 20, 20 );

  cHwEthernet_MCU net  ( reset, myMAC );

#include "content.h"
  class cHwMemory_Prog : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
    */
    cHwMemory_Prog( BYTE *startAddress, DWORD sizeIn )
  : cHwMemory( sizeIn, 0 )
  {
    ptr = startAddress;
  }

  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data )
    {
    }

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr )
    {
      return( ptr[addr] );
    }

  public:
    //---------------------------------------------------------------
    virtual void clear( DWORD offset = 0 )
    {
    }

    //---------------------------------------------------------------
    virtual void lock( void ) {}
    virtual void unlock( void ) {}

  private:
    //---------------------------------------------------------------
    BYTE  *ptr;
  
}; //cHwMemory_Prog
  cHwMemory_Prog   contentMem( (BYTE*)content, 0xFFFF );


//==========================================
#elif defined _MCU_TYPE_VIRTUAL
//==========================================
//  cHwUART_Serial  uart( "\\\\.\\COM10" );
  cHwUART_Stdio     uart;
  cNetWin           net;
  cHwMemory_MCU     contentMem(".\\Module\\HTTP\\content.bin", 1000000L);
//==========================================
#else
  #error "config.h: device type not defined"
#endif
//==========================================

cDevTextIO_UART    com( uart, 20, 20, "#\r\n", "" );

//EOF
