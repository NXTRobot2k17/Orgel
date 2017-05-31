#include "lib.h"

#ifndef ANALOG_H
#define ANALOG_H


class Analog
{
    public:
        Analog(BYTE port, float fact=1, int16_t off=0);
        virtual ~Analog();

        BYTE port;
        float fact;
        uint16_t off;
};

#endif // ANALOG_H
