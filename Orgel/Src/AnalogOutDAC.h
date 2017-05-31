#include "AnalogOut.h"

#ifndef ANALOGOUTDAC_H
#define ANALOGOUTDAC_H


class AnalogOutDAC : public AnalogOut
{
    public:
        AnalogOutDAC(BYTE port, float fact=1, int16_t off=0);
        virtual ~AnalogOutDAC();

        using AnalogOut::operator=;
    public:
        virtual void Set(WORD value);
};

#endif // ANALOGOUTDAC_H
