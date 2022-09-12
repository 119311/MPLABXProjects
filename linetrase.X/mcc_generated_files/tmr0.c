#include "tmr0.h"
#include <xc.h>
volatile uint8_t timer0ReloadVal;
void (*TMR0_InterruptHandler)(void);
void TMR0_Initialize(void)
{
