#include "mcc_generated_files/mcc.h"
void TMR0_Interrupt(void); // 追加文
int flag = 1;
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(TMR0_Interrupt);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (1) {
        if (flag == 1) { // 割り込み周期で LATB を ON/OFF
            LATB = 0xff;
        } else {
            LATB = 0;
        }
    }
}
void TMR0_Interrupt(void)
{ // 割り込み時の処理
    flag *= -1; // 割り込みの度に flag を変化(1 or -1)
}
