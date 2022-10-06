#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define dt 0.1
#define Kp 0.3
#define Ki 0.0
#define Kd 0.0
typedef struct motor_t Motor;

struct motor_t {
    uint8_t _speed;
    uint8_t _targetSpeed;
    int8_t _tempSpeed;
    int8_t _tempTime;
    uint8_t _addr1;
    uint8_t _addr2;
    int16_t _tempCount;
    bool _direction;
    volatile uint8_t* _port;
};
void runMotor(Motor* self);
int main(void)
{
    Motor left = { 10, 2, 3, 1, 1, 2, 0, 0, 0 };
    uint8_t i = 10;
    while (i--)
        runMotor(&left);
    return 0;
}
void runMotor(Motor* self)
{
    if (1) {
        // if (self->_tempSpeed-- > 0)
        //     temp += self->_direction ? self->_addr1 : 0, temp += self->_direction ? 0 : self->_addr2;
        // else if (!((self->_tempCount++) % 1500))
        self->_targetSpeed > self->_speed ? self->_speed++ : (self->_targetSpeed < self->_speed ? self->_speed-- : 0);
    } // self->_tempSpeed = 4;
    printf("tempSpeed: %d,tempTime: %d,tempCount: %d,speed: %d,targetSpeed: %d,direction: %d,addr1: %d,addr2: %d \n", self->_tempSpeed, self->_tempTime, self->_tempCount, self->_speed, self->_targetSpeed, self->_direction, self->_addr1, self->_addr2);
    return;
}
