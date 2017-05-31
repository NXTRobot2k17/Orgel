#include "Analog.h"

#ifndef ANALOGIN_H
#define ANALOGIN_H


class AnalogIn : public Analog
{
    public:
        AnalogIn(BYTE port, float fact=1, int16_t off=0);
        virtual ~AnalogIn();

        virtual WORD Get()=0;

        virtual operator WORD();

        virtual operator float();

};

#endif // ANALOGIN_H
