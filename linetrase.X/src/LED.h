#ifndef LED_H
#define LED_H

#include "../mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool _LED1;
    bool _LED2;
    bool _LED4;
    bool _LED5;
    bool _LED7;
    bool _LED8;
    adc_result_t _LED3A;
    adc_result_t _LED6A;
} LED;

void readLed(LED* self);

#endif
