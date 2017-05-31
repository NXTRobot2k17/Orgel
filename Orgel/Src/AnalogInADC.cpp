#include "AnalogInADC.h"

AnalogInADC::AnalogInADC(BYTE port,cHwADC &refADC, float fact, int16_t off):AnalogIn(port,fact,off), adc(refADC)
{
    adc.enable(port);
}

WORD AnalogInADC::Get()
{
    WORD value=adc.get(port);
    value=(value-off)/fact;
    return value;
}

AnalogInADC::~AnalogInADC()
{
    //dtor
}
