#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define dt 0.1
#define Kp 0.3
#define Ki 0.0
#define Kd 0.0

#define BASETIME 32

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
void setTargetSpeed(Motor* self, uint8_t value)
{
    self->_targetSpeed = value;
}
uint8_t getSpeed(const Motor* self)
{
    return self->_speed;
}
uint8_t getTargetSpeed(const Motor* self)
{
    return self->_targetSpeed;
}
bool getDirection(const Motor* self)
{
    return self->_direction;
}
void setSpeed(Motor* self, uint8_t value)
{
    uint8_t nowValue = getSpeed(self);
    int8_t difference = value - nowValue;
    if (difference >> 8)
        nowValue -= (((1 + difference) >> 8) ? 4 : -difference);
    else if (difference)
        nowValue += (nowValue - 4) >> 8 ? 1 : ((difference - 1) >> 8 ? difference : 4);
    nowValue = nowValue ? nowValue : 1;
    self->_speed = nowValue;
}
}
int main(void)
{
    Motor motor = { 0, 0, 12, 0, 1, 2, 1, true, NULL };
    for (int i = 0; i < 100; i++) {
        runMotor(&motor);
    }
    return 0;
}
