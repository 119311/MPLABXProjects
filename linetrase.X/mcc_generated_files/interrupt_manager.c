#include "interrupt_manager.h"
#include "mcc.h"

void __interrupt() INTERRUPT_InterruptManager(void)
{
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTERRUPT_GlobalInterruptDisable();
        INTCONbits.TMR0IE = 0;
        TMR0_ISR();
    } else if (INTCONbits.PEIE && PIE1bits.ADIE && PIR1bits.ADIF)
        ADC_ISR();
}
