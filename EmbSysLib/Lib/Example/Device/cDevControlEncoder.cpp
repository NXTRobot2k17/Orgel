//*******************************************************************
/*!
\file   cDevEncoder.cpp
\author Thomas Breuer
\date   15.02.2013
\brief  Sample Device Control (encoder)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_LPC17XX
//===================================================================

  cDevControlEncoderJoystick encoder( new cDevDigital( port1, 26, cDevDigital::In, 1 ),
                                      new cDevDigital( port1, 24, cDevDigital::In, 1 ),
                                      new cDevDigital( port1, 20, cDevDigital::In, 1 ),
                                      &timer, 200/*ms*/ );

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX
//===================================================================

  cDevControlEncoderRotaryKnob encoder( new cDevDigital( portA,  1, cDevDigital::In, 1 ),
                                        new cDevDigital( portA,  8, cDevDigital::In, 1 ),
                                        new cDevDigital( portA, 15, cDevDigital::In, 1 ),
                                        &timer );

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================

  cDevControlEncoderRotaryKnob encoder( new cDevDigital( portA, 11, cDevDigital::In, 1 ),
                                        new cDevDigital( portA, 12, cDevDigital::In, 1 ),
                                        new cDevDigital( portA, 13, cDevDigital::In, 1 ),
                                        &timer );

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL
//===================================================================

  cDevControlEncoderJoystick   encoder( new cDevDigital( port, 0, cDevDigital::In, 0 ),
                                        new cDevDigital( port, 2, cDevDigital::In, 0 ),
                                        new cDevDigital( port, 1, cDevDigital::In, 0 ),
                                        &timer );

//===================================================================
#else
  #error "device type not defined"
#endif
//===================================================================

//*******************************************************************
int main( void )
{

  int cnt = 0;
  int btn = 0;




  com.printf( "cDevControlEncoder\r\n" );
  com.printf( __DATE__ "," __TIME__"\r\n" );

  while( 1 )
  {
//    net.update();
    switch( encoder.get() )
    {
      case cDevControlEncoder::LEFT:     cnt -= 1;             break;
      case cDevControlEncoder::RIGHT:    cnt += 1;             break;
      case cDevControlEncoder::CTRL_DWN: cnt  = 0;  btn  = 1;  break;
      case cDevControlEncoder::CTRL_UP:             btn  = 0;  break;
      default:                                          break;
    }
    com.printf( "\rcnt=%3d  btn=%3s\r", cnt, (btn)?"DWN":"UP " );
//    Sleep(10);
  }
}
