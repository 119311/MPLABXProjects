#ifndef LINETRACER_H
#define LINETRACER_H

#include "../mcc_generated_files/mcc.h"
#include "LED.h"
#include "autoPilot.h"
#include "motor.h"

#define IN1 1 << 0
#define IN2 1 << 1
#define IN3 1 << 2
#define IN4 1 << 3

Motor left, right;
LED led;
uint8_t leftSpeed = 16, rightSpeed = 16;
bool flag = false, flagOld = false;
#endif
