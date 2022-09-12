#include "LED.h"
void get_LED(LED* self)
{
    self->LED1 = LED1_PORT;
    self->LED2 = LED2_PORT;
    self->LED4 = LED4_PORT;
    self->LED5 = LED5_PORT;
    self->LED7 = LED7_PORT;
    self->LED8 = LED8_PORT;
    ADC_GetConversion(LED3);
    uint16_t LED3;
    uint16_t LED6;
    return;
}
