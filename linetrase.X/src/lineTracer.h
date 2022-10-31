#ifndef LINETRACER_H
#define LINETRACER_H

#include "../mcc_generated_files/mcc.h"
#include "LED.h"
#include "autoPilot.h"
#include "motor.h"
#include "pic16f1778.h"
#include <stdbool.h>
#include <stdint.h>

#define IN1 1 << 0
#define IN2 1 << 1
#define IN3 1 << 2
#define IN4 1 << 3

Motor left, right;
LED led;
uint8_t leftSpeed = 1, rightSpeed = 1;
bool flag = false, oldFlag = false, motorSelect = false;

#endif
