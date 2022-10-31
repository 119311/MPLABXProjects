#ifndef LED_H
#define LED_H

#include "../mcc_generated_files/mcc.h"
typedef struct led_t LED;
struct led_t {
    bool _LED1;
    bool _LED2;
    bool _LED4;
    bool _LED5;
    bool _LED7;
    bool _LED8;
    uint16_t _LED6A;
    uint16_t _LED3A;
} LED;

void readLed(LED* self);
#endif
