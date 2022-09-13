#include "LED.h"
static uint16_t tempValue;
void readLed(LED* self)
{
    self->LED1 = LED1_PORT;
    self->LED2 = LED2_PORT;
    self->LED4 = LED4_PORT;
    self->LED5 = LED5_PORT;
    self->LED7 = LED7_PORT;
    self->LED8 = LED8_PORT;
    self->LED3A = ADC_GetConversion(LED3A);
    self->LED6A = ADC_GetConversion(LED6A);
}
