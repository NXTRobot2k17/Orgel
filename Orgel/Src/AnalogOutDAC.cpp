#include "AnalogOutDAC.h"

extern cHwDAC_Virtual dac;

AnalogOutDAC::AnalogOutDAC(BYTE port, float fact, int16_t off):AnalogOut(port, fact, off)
{
    dac.enable(port);
}

void AnalogOutDAC::Set(WORD value)
{
    value=value*fact+off;
    dac.set(value, port);
}

AnalogOutDAC::~AnalogOutDAC()
{
    //dtor
}
