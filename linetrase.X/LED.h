#pragma once
#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
typedef struct led_t LED;
struct led_t {
    bool LED1;
    bool LED2;
    uint16_t LED3;
    bool LED4;
    bool LED5;
    uint16_t LED6;
    bool LED7;
    bool LED8;
};
