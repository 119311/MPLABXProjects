
#include "mcc_generated_files/mcc.h"
uint8_t Duty1 = 0;

void main(void)
{

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
//        if (!PORTAbits.RA0)
            Duty1 += 0x20;
//        else
//        {
//            if (!PORTAbits.RA4)
//                Duty1 -= 0x10;
//        }
        PWM3_LoadDutyValue(Duty1);
        __delay_ms(100);
    }
}
