#include "mcc.h"

void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
    ADC_Initialize();
    TMR0_Initialize();
    return;
}
void OSCILLATOR_Initialize(void)
{
    OSCCON = 0x7A;
    OSCSTAT = 0x80;
    OSCTUNE = 0x00;
    BORCON = 0x00;
    return;
}
void WDT_Initialize(void)
{
    WDTCON = 0x16;
    return;
}
