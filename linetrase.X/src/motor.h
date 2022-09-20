#pragma once
#include "../mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
#define BASETIME 32
typedef struct motor_t Motor;
struct motor_t {
    bool _direction;
    uint8_t _speed;
    int8_t _tempSpeed;
    int8_t _tempTime;
    bool* _port1;
    bool* _port2;
};
int getSpeed(const Motor* self);
int getDirection(const Motor* self);
void setSpeed(Motor* self, uint8_t value);
void setDirection(Motor* self, bool value);
void setPort(Motor* self, bool port1, bool port2);
void runMotor(Motor* self);
