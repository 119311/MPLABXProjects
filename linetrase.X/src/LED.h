#ifndef LED_H
#define LED_H
#include "../mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
typedef struct led_t LED;
struct led_t {
    bool _LED1;
    bool _LED2;
    bool _LED4;
    bool _LED5;
    bool _LED7;
    bool _LED8;
    uint8_t _LED6A;
    uint8_t _LED3A;
};
void readLed(LED* self);
#endif
