#include "AnalogIn.h"

AnalogIn::AnalogIn(BYTE port, float fact, int16_t off):Analog(port,fact,off)
{
    //ctor
}

AnalogIn::operator WORD()
{
    return Get();
}

AnalogIn::operator float()
{
    return fact*Get()+off;
}

AnalogIn::~AnalogIn()
{
    //dtor
}
