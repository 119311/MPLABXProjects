#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000

#define PIN_INIT 0x01
void main(void)
{
    SYSTEM_Initialize();

    LATB = PIN_INIT;
    while (1)
    {
        LATB <<= 1;
        if (!LATB)
            LATB = PIN_INIT;
        __delay_ms(100);
    }
}
