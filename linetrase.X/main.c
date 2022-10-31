#include "src/lineTracer.h"

void motorInit(void)
{
    setPort(&right, &LATB, IN2, IN1);
    setPort(&left, &LATB, IN4, IN3);
    setDirection(&left, true);
    setDirection(&right, true);
    MODE_LAT = LOW;
    LARGE_LAT = LOW;
}
uint8_t leftSpeed = 1, rightSpeed = 1;
void run(void)
{
    INTCONbits.TMR0IE = 0;
    readLed(&led);
    autoPilot(&led, &leftSpeed, &rightSpeed);
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    runMotor(&left);
    runMotor(&right);
    INTCONbits.TMR0IE = 1;
}

void main(void)
{
    SYSTEM_Initialize();
    motorInit();
    TMR0_SetInterruptHandler(run);
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (true)
        asm("nop");
}
