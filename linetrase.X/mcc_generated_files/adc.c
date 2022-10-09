#include "adc.h"
#include "device_config.h"
#include <xc.h>

#define ACQ_US_DELAY (5)

void (*ADC_InterruptHandler)(void);
void ADC_Initialize(void)
{
    // set the ADC to the options selected in the User Interface
    // ADFM right; ADNREF VSS; ADPREF VDD; ADCS FOSC/32;
    ADCON1 = 0xA0;
    // TRIGSEL no_auto_trigger;
    ADCON2 = 0x00;
    // ADRES 0;
    ADRESL = 0x00;
    // ADRES 0;
    ADRESH = 0x00;
    // GO stop; ADON enabled; CHS AN4;
    ADCON0 = 0x11;
    // Enabling ADC interrupt.
    PIE1bits.ADIE = 1;
    // Set Default Interrupt Handler
    ADC_SetInterruptHandler(ADC_DefaultInterruptHandler);
    return;
}
void ADC_SelectChannel(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;
    // Turn on the ADC module
    ADCON0bits.ADON = 1;
    return;
}
void ADC_StartConversion(void)
{
    // Start the conversion
    ADCON0bits.GO = 1;
    return;
}
bool ADC_IsConversionDone(void)
{
    // Start the conversion
    return ((bool)(!ADCON0bits.GO));
}
adc_result_t ADC_GetConversionResult(void)
{
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}
adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;
    // Turn on the ADC module
    ADCON0bits.ADON = 1;
    // Acquisition time delay
    __delay_us(ACQ_US_DELAY);
    // Start the conversion
    ADCON0bits.GO = 1;
    // Wait for the conversion to finish
    while (ADCON0bits.GO) {
    }
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}
void ADC_TemperatureAcquisitionDelay(void)
{
    __delay_us(200);
    return;
}
void ADC_ISR(void)
{
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
    if (ADC_InterruptHandler) {
        ADC_InterruptHandler();
    }
    return;
}
void ADC_SetInterruptHandler(void (*InterruptHandler)(void))
{
    ADC_InterruptHandler = InterruptHandler;
    return;
}
void ADC_DefaultInterruptHandler(void)
{
    return;
}
