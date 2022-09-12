#include "adc.h"
#include "device_config.h"
#include <xc.h>
#define ACQ_US_DELAY 5
void (*ADC_InterruptHandler)(void);
void ADC_Initialize(void)
{
