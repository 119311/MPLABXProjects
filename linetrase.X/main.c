#include "mcc_generated_files/mcc.h"
#include "pic16f1778.h"
#include "src/LED.h"
#include "src/motor.h"

#define IN1 1 << 0
#define IN2 1 << 1
#define IN3 1 << 2
#define IN4 1 << 3

Motor left, right;

LED led;

void run(void)
{
    runMotor(&left);
    runMotor(&right);
    asm("NOP");
}
void motorInit(void)
{
    setPort(&left, &LATB, IN2, IN1);
    setPort(&right, &LATB, IN4, IN3);
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
    uint8_t leftSpeed = 5, rightSpeed = 10;
    setSpeed(&left, leftSpeed);
    setSpeed(&right, rightSpeed);
    while (true) {
        readLed(&led);
        //        run();
        //        autoPilot(&led, &left, &right);
        asm("NOP");
    }
}
