#include "tmr0.h"
#include "pin_manager.h"
#include <xc.h>

volatile uint8_t timer0ReloadVal;

void (*TMR0_InterruptHandler)(void);

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
    // PSA assigned; PS 1:4; TMRSE Increment_hi_lo; mask the nWPUEN and INTEDG bits
    OPTION_REG = (uint8_t)((OPTION_REG & 0xC0) | (0x51 & 0x3F));
    // TMR0 252;
    TMR0 = 0xFC;
    // Load the TMR value to reload variable
    timer0ReloadVal = 252;
    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;
    // Enabling TMR0 interrupt
    INTCONbits.TMR0IE = 1;
    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
    return;
}
uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;
    readVal = TMR0;
    return readVal;
}
void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 register
    TMR0 = timerVal;
    return;
}
void TMR0_Reload(void)
{
    // Write to the Timer0 register
    TMR0 = timer0ReloadVal;
    return;
}
void TMR0_ISR(void)
{
    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;
    TMR0 = timer0ReloadVal;
    // ticker function call;
    // ticker is 1 -> Callback function gets called every time this ISR executes
    TMR0_CallBack();
    // add your TMR0 interrupt custom code
    return;
}
void TMR0_CallBack(void)
{
    if (TMR0_InterruptHandler) {
        TMR0_InterruptHandler();
    }
    return;
}
void TMR0_SetInterruptHandler(void (*InterruptHandler)(void))
{
    TMR0_InterruptHandler = InterruptHandler;
    return;
}
void TMR0_DefaultInterruptHandler(void)
{
    return;
}
