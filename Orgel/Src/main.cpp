//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "PWM.h"
#include "AnalogOut.h" 
#include "AnalogInADC.h"
#include "AnalogOutDAC.h"

//*******************************************************************
#if defined _MCU_TYPE_LPC17XX
  #include "configLPC17xx.h"
#elif defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//*******************************************************************
class cTask_Example : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
    cTask_Example(cTaskHandler &taskHandler)
    : Task(taskHandler)
    {
    }

  private:
    //---------------------------------------------------------------
    virtual void update(void)
    {
    }
};

//*******************************************************************
cTaskHandler  taskHandler(&timer);

cTask_Example task_Example(taskHandler);

//*******************************************************************
class cRtosTask_Example : public cRTOS::Task
{
  public:
    //---------------------------------------------------------------
    cRtosTask_Example(cRTOS &rtosIn )

    : cRTOS::Task( rtosIn, 500/* stack size*/ )

    {
      sec = 0;
      Start();
    }

    //---------------------------------------------------------------
    virtual ~cRtosTask_Example()
    {
    }

    //---------------------------------------------------------------
    virtual void update( )
    {
      while( 1 )
      {
        Pause( 10 );
        if( timer.timeout() )
        {
          sec+=0.1;
        }
      }
    }

    //---------------------------------------------------------------
    virtual void OnStop(void)
    {
    }

    //---------------------------------------------------------------
    virtual void OnStart(void)
    {
      timer.start( 100 );
    }

    //---------------------------------------------------------------
    float   sec;

    cRTOS::Timer timer;
};


//*******************************************************************
cRTOS_RR<3> rtos( 1000/*time per task [ms]*/ );

cRtosTask_Example  rtos_task_Example( rtos );

//*******************************************************************
WORD x = 0;
WORD y = 0;

//*******************************************************************
int main(void)
{
  cTaskHandler::Timer taskTimer( taskHandler );

  disp.printf(0,0,0,__DATE__ " " __TIME__);

  AnalogInADC adcControl(2, adc,1,0);
  AnalogOutDAC dacControl(0,1,0);
  timerPWM.enablePWM(3);
    PWM pwm(timer, 1000, led);
    pwm.set(250);
    pwm.enable();
  while(1)
  {
    switch( enc.get() )
    {
        case cDevControlEncoder::LEFT:     x-=1000; break;
        case cDevControlEncoder::RIGHT:    x+=1000; break;
        case cDevControlEncoder::CTRL_DWN: x =   0; break;
        default:                                    break;
    }

    dacControl = x;
    timerPWM.setPWM(x,3);

    y  = (WORD)adcControl;

    if( taskTimer.timeout(10/*ms*/) )
    {
      disp.printf(1,0,20,"time:%.1f",rtos_task_Example.sec);
      disp.printf(2,0,20,"x:   %-6d",x);
      disp.printf(3,0,20,"y:   %-6d",y);
    }
  }
}

//EOF
