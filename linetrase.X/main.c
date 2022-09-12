#include "mcc_generated_files/mcc.h"
#include "motor.h"
void get_led()
{
    return;
}
TMR0_INT(void)
{
    get_led();
}
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_SetInterruptHandler(TMR0_INT);
    Motor left;
    while (true) {
        left.speed = 20;
    }
}
