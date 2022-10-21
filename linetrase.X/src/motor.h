#ifndef MOTOR_H
#define MOTOR_H

#include "../mcc_generated_files/mcc.h"

#define BASETIME 16

typedef struct {
    uint8_t _speed;
    int8_t _tempSpeed;
    uint8_t _targetSpeed;
    int8_t _tempTime;
    uint8_t _addr1;
    uint8_t _addr2;
    int16_t _tempCount;
    bool _direction;
    volatile uint8_t* _port;
} Motor;

uint8_t getSpeed(const Motor* self);
bool getDirection(const Motor* self);
void setSpeed(Motor* self, uint8_t value);
void setDirection(Motor* self, bool value);
void setPort(Motor* self, volatile uint8_t* port, uint8_t addr1, uint8_t addr2);
void runMotor(Motor* self);
void setTargetSpeed(Motor* self, uint8_t value);

#endif
