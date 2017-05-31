#include "PWM.h"


PWM::PWM(cHwTimer &t, uint16_t maxCount, cDevDigital &out):maxValue(maxCount), led(out)
{
    t.add(this);
}

void PWM::enable()
{
    isEnabled=true;
}

void PWM::disable()
{
    isEnabled=false;
}

void PWM::set(WORD value)
{
    if(value>maxValue)
        limit=maxValue;
    else
        limit=value;
   // timer.setPWM(value, port);
}

void PWM::update(void)
{
    if(!isEnabled)
        return;
    counter++;
    if(counter==maxValue)
        counter=0;
    if(counter==limit)
        led.set(false);
    else if(counter==0)
        led.set(true);
}

PWM::~PWM()
{
    //dtor
}
