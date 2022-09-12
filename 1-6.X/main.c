#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#define _XTAL_FREQ 4000000

#define PIN_INIT 0x01
void main(void)
{
    SYSTEM_Initialize();
    LATB = PIN_INIT;
    bool a = false;
    while (1) {
        if (!PORTAbits.RA0)
            a = true;
        if (!PORTAbits.RA4)
            a = false;
        if (a) {
            LATB <<= 1;
            if (!LATB)
                LATB = PIN_INIT;
        }
        __delay_ms(100);
    }
}
