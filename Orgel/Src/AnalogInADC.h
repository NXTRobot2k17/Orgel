#include "AnalogIn.h"

#ifndef ANALOGINADC_H
#define ANALOGINADC_H


class AnalogInADC : public AnalogIn
{
    public:
        AnalogInADC(BYTE port,cHwADC &refADC, float fact=1, int16_t off=0);
        virtual ~AnalogInADC();

    private:
        cHwADC &adc;

    public:
        virtual WORD Get();
};

#endif // ANALOGINADC_H
