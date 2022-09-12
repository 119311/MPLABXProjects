#include "mcc_generated_files/mcc.h"

unsigned int Duty1, Duty2;
void main(void)
{
    SYSTEM_Initialize();

    while (1) {
        if (S1_GetValue() == 0) {
            Duty1++;
            PWM3_LoadDutyValue(Duty1);
        }
        if (S2_GetValue() == 0) {
            Duty2++;
            PWM3_LoadDutyValue(Duty2);
        }
        __delay_ms(10);
    }
}
