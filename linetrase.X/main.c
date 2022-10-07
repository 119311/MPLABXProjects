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
    autoPilot(&led, &leftSpeed, &rightSpeed);
    runMotor(&left);
    runMotor(&right);
    asm("NOP");
}
void main(void)
{
    SYSTEM_Initialize();
    motorInit();
    setTargetSpeed(&left, leftSpeed);
    setTargetSpeed(&right, rightSpeed);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (true) {
        readLed(&led);
        setTargetSpeed(&left, leftSpeed);
        setTargetSpeed(&right, rightSpeed);
        //        autoPilot(&led, &leftSpeed, &rightSpeed);
        // setSpeed(&left, leftSpeed);
        // setSpeed(&right, rightSpeed);
    }
}
