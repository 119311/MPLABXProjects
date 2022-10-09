#include "src/lineTracer.h"

void motorInit(void)
{
    setPort(&left, &LATB, IN2, IN1);
    setPort(&right, &LATB, IN4, IN3);
    setDirection(&left, true);
    setDirection(&right, true);
    MODE_LAT = LOW;
    LARGE_LAT = LOW;
    return;
}
void run(void)
{
    flag = !flag;
    return;
}
void main(void)
{
    SYSTEM_Initialize(), motorInit();
    setTargetSpeed(&left, leftSpeed);
    setTargetSpeed(&right, rightSpeed);
    TMR0_SetInterruptHandler(run);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (true) {
        readLed(&led);
        autoPilot(&led, &leftSpeed, &rightSpeed);
        setTargetSpeed(&left, leftSpeed);
        setTargetSpeed(&right, rightSpeed);
        if (flag != flagOld) {
            flagOld = flag;
            runMotor(&left);
            runMotor(&right);
        }
    }
    return;
}
