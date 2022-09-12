#include "mcc.h"
void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
    TMR0_Initialize();
    ADC_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
    PWM4_Initialize();
    PWM3_Initialize();
    TMR2_Initialize();
}
void OSCILLATOR_Initialize(void)
{
