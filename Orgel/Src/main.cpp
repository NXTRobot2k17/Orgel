//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "PWM.h"
#include "AnalogOut.h"
#include "AnalogInADC.h"
#include "AnalogOutDAC.h"
#include "AsciiConverter.h"
#include "AudioOut.h"
#include "AudioStream.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

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

cTaskHandler  taskHandler(&timer);


cTaskHandler::Timer taskTimer( taskHandler );
AudioOut audioOut(taskHandler);
AnalogOutDAC *dacAudio=new AnalogOutDAC(0,1,0);
bool readyToWrite=false;
WORD audioValue;

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
			audioValue=audioOut.getSound();
			dacAudio->Set(audioValue);
    }
};

//*******************************************************************
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
AsciiConverter converter;
BYTE c;
int i;

//*******************************************************************
int main(void)
{
	AnalogInADC volumePoti(2, adc,1,0);
		
  disp.printf(0,0,0,__DATE__ " " __TIME__);
  
	while(1)
  {
    if( uart.get( &c ) ) //&& !readyToWrite)//_kbhit())
    {
				if(c>=0x30 && c<=0x7A)
				{
						i = converter.convert( (char)c ); //_getch());
						uart.set(c);
						if(i!=-100)
							audioOut.setTone(i);
				}
    }
		audioOut.setVolume(volumePoti.Get()/2);
   



    if( taskTimer.timeout(10/*ms*/) )
    {
      disp.printf(3,0,20,"i:   %-6d",i);
			disp.printf(4,0,20,"volume:   %-6d",volumePoti.Get()/2);
			disp.printf(5,0,20,"value:   %-6d",taskHandler.getCycleTime());
    }
  }
}

//EOF
