#pragma once
#include "../mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
typedef struct led_t LED;
struct led_t {
    bool _LED1;
    bool _LED2;
    uint8_t _LED3A;
    bool _LED4;
    bool _LED5;
    uint8_t _LED6A;
    bool _LED7;
    bool _LED8;
};
void readLed(LED* self);
