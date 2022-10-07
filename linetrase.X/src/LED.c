#include "LED.h"
static uint16_t tempValue;
void readLed(LED* self)
{
    self->_LED1 = LED1_PORT;
    self->_LED2 = LED2_PORT;
    self->_LED4 = LED4_PORT;
    self->_LED5 = LED5_PORT;
    self->_LED7 = LED7_PORT;
    self->_LED8 = LED8_PORT;
    // self->_LED3A = ADC_GetConversion(LED3A);
    // self->_LED6A = ADC_GetConversion(LED6A);
}
