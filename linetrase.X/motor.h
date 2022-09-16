#pragma once
#include "mcc_generated_files/mcc.h"
#include <stdbool.h>
#include <stdint.h>

#define forward true
#define reverse !true
#define BASETIME 32
typedef struct motor_t Motor;
struct motor_t {
    bool direction;
    uint8_t speed;
    uint8_t tempSpeed;
    uint8_t tempTime = BASETIME;
    PORTBbits_t* port1;
    PORTBbits_t* port2;
};
int getSpeed(const Motor* self);
int getDirection(const Motor* self);
void setSpeed(Motor* self, uint8_t value);
void setDirection(Motor* self, bool value);
void setPort(Motor* self, PORTBbits_t* port1, PORTBbits_t* port2);
void runMotor(Motor* self);
