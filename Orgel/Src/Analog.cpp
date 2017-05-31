#include "Analog.h"

Analog::Analog(BYTE port, float fact, int16_t off)
{
    Analog::port=port;
    Analog::fact=fact;
    Analog::off=off;
}

Analog::~Analog()
{
    //dtor
}
