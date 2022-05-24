#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000
#define PIN_INIT 0x00

void main(void)
{
  SYSTEM_Initialize();
  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();
  LATB = PIN_INIT;
  while (1)
  {
    if (!PORTAbits.RA0)
      LATB = 0xff;
    if (PORTAbits.RA0)
      LATB = 0x00;
    __delay_ms(10);
  }
}
