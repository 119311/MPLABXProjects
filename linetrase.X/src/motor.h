#pragma once
#include "../mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>
#define BASETIME 32
typedef struct motor_t Motor;
struct motor_t {
    uint8_t _speed;
    int8_t _tempSpeed;
    int8_t _tempTime;
    uint8_t _addr1;
    uint8_t _addr2;
    bool _direction;
    volatile uint8_t* _port;
};
int getSpeed(const Motor* self);
int getDirection(const Motor* self);
void setSpeed(Motor* self, uint8_t value);
void setDirection(Motor* self, bool value);
void setPort(Motor* self, volatile uint8_t* port, uint8_t addr1, uint8_t addr2);
void runMotor(Motor* self);
