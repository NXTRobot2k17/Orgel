#include "lib.h"

#ifndef PWM_H
#define PWM_H


class PWM : public cList::Item
{
    public:
        PWM(cHwTimer &t, uint16_t maxCount, cDevDigital &out);
        virtual ~PWM();

        void enable();
        void disable();
        void set(WORD value);


    private:
        virtual void update(void);

        //cHwTimer timer;
        WORD limit;
        bool isEnabled;
        bool isChecked;
        uint16_t maxValue;
        uint16_t counter;
        cDevDigital led;
};

#endif // PWM_H
