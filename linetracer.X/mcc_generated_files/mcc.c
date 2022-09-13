#include "mcc.h"
void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
}
void OSCILLATOR_Initialize(void)
{
