#include "AnalogOut.h"

AnalogOut::AnalogOut(BYTE port, float fact, int16_t off):Analog(port, fact, off)
{
    //ctor
}

void AnalogOut::operator =(WORD value)
{
    Set(value);
}

void AnalogOut::operator =(float value)
{
    Set((WORD)value);
}

AnalogOut::~AnalogOut()
{
    //dtor
}
