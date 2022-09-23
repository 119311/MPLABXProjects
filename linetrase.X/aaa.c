#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define dt 0.1
#define Kp 0.3
#define Ki 0.0
#define Kd 0.0
void lineTrace(uint8_t* leftSpeed, uint8_t* rightSpeed, const uint8_t* leftLed, const uint8_t* rightLed);
int main(void)
{
    uint8_t leftSpeed = 4, rightSpeed = 4;
    uint8_t leftLed = 120, rightLed = 110;
    while (true) {
        lineTrace(&leftSpeed, &rightSpeed, &leftLed, &rightLed);
    }
    return 0;
}

void lineTrace(uint8_t* leftSpeed, uint8_t* rightSpeed, const uint8_t* leftLed, const uint8_t* rightLed)
{
    // pid
    static float integral = 0.0, derivative = 0.0, lastError = 0.0;
    float error = (float)(*leftLed - *rightLed);
    integral += error * dt;
    derivative = (error - lastError) / dt;
    float pid = Kp * error + Ki * integral + Kd * derivative;
    lastError = error;
    *leftSpeed = (uint8_t)(*leftSpeed + pid);
    *rightSpeed = (uint8_t)(*rightSpeed - pid);
    printf("leftSpeed:%d,rightSpeed:%d,leftLed:%d,rightLed:%d,error:%f,integral:%f,derivative:%f,pid:%f,lastError:%f\n", *leftSpeed, *rightSpeed, *leftLed, *rightLed, error, integral, derivative, pid, lastError);
    return;
}
