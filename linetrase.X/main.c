#include "src/lineTracer.h"
void motorInit(void)
{
    setPort(&left, &LATB, IN2, IN1);
    setPort(&right, &LATB, IN4, IN3);
    setDirection(&left, true);
    setDirection(&right, true);
    MODE_LAT = LOW;
    LARGE_LAT = LOW;
}
void run(void)
{
    readLed(&led);
    autoPilot(&led, &leftSpeed, &rightSpeed);
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    // setTargetSpeed(&left, leftSpeed);
    // setTargetSpeed(&right, rightSpeed);
    runMotor(&left);
    runMotor(&right);
    asm("NOP");
}
void main(void)
{
    SYSTEM_Initialize();
    motorInit();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    uint8_t leftSpeed = 4, rightSpeed = 4;
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    while (true) {
        // readLed(&led);
        // autoPilot(&led, &leftSpeed, &rightSpeed);
        // setSpeed(&left, leftSpeed);
        // setSpeed(&right, rightSpeed);
    }
}
