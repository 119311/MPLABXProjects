#include "tmr2.h"
#include <xc.h>
void (*TMR2_InterruptHandler)(void);
void TMR2_Initialize(void)
{
