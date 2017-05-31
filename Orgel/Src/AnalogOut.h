#include "Analog.h"

#ifndef ANALOGOUT_H
#define ANALOGOUT_H


class AnalogOut : public Analog
{
    public:
        AnalogOut(BYTE port, float fact=1, int16_t off=0);
        virtual ~AnalogOut();

        virtual void Set(WORD value)=0;

        virtual operator = (WORD);

        virtual operator = (float);

};

#endif // ANALOGOUT_H
