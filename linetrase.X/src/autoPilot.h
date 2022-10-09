#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include "LED.h"
#include "lineTracer.h"
#include <stdbool.h>
#include <stdint.h>

#define Kp 0.05
#define Ki 0.0
#define Kd 0.0
#define dt 0.01

void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);
void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);

#endif
