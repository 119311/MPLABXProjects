#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include "lineTracer.h"
#define Kp 0.05

typedef enum {
    LINETRACE,
    CRANK,
    CHICANE,
} State;

void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);
// State getState(LED* led);
// void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);
// void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);
// void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed);

#endif
