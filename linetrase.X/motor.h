#pragma once
#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
typedef struct motor_t Motor;
struct motor_t {
    bool direction;
    uint8_t speed;
    int (*_get_speed)(Motor*);
    int (*_get_direction)(Motor*);
};
int get_speed(const Motor* self);
int get_direction(const Motor* self);
void set_speed(Motor* self, uint8_t value);
void set_direction(Motor* self, bool value);
