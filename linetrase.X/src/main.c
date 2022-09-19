#include "LED.h"
#include "mcc_generated_files/mcc.h"
#include "motor.h"
#include "pic16f1778.h"

Motor left, right;
LED led;

void run(void)
{
    runMotor(&left);
    runMotor(&right);
}
void motorInit(void)
{
    setPort(&left, IN2_PORT, IN1_PORT);
    setPort(&right, IN3_PORT, IN4_PORT);
    setDirection(&left, true);
    setDirection(&right, true);
    MODE_LAT = LOW;
    LARGE_LAT = LOW;
}
void main(void)
{
    SYSTEM_Initialize();
    motorInit();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    uint8_t leftSpeed = 20, rightSpeed = 20;
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    while (true) {
        readLed(&led);
        autoPilot(&led, &left, &right);
        asm("NOP");
    }
}
