#ifndef ADC_H
#define ADC_H

#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

typedef uint16_t adc_result_t;

typedef struct
{
    adc_result_t adcResult1;
    adc_result_t adcResult2;
} adc_sync_double_result_t;

typedef enum {
    LED6A = 0x2,
    LED3A = 0x4,
    channel_Switched_AN1 = 0x21,
    channel_Switched_AN10 = 0x2A,
    channel_Switched_AN18 = 0x32,
    channel_DAC7_Output = 0x37,
    channel_DAC5_Output = 0x39,
    channel_DAC4_Output = 0x3A,
    channel_DAC3_Output = 0x3B,
    channel_DAC2_Output = 0x3C,
    channel_Temp = 0x3D,
    channel_DAC1_Output = 0x3E,
    channel_FVRBuffer1 = 0x3F
} adc_channel_t;

void ADC_Initialize(void);
void ADC_SelectChannel(adc_channel_t channel);
void ADC_StartConversion(void);
bool ADC_IsConversionDone(void);
adc_result_t ADC_GetConversionResult(void);
adc_result_t ADC_GetConversion(adc_channel_t channel);
void ADC_TemperatureAcquisitionDelay(void);
void ADC_ISR(void);
void ADC_SetInterruptHandler(void (*InterruptHandler)(void));
extern void (*ADC_InterruptHandler)(void);
void ADC_DefaultInterruptHandler(void);

#endif
