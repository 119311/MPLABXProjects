#include "LED.h"
#include "mcc_generated_files/mcc.h"
#include "motor.h"
#include "pic16f1778.h"

#define PORT1A IN2_LAT
#define PORT1B IN1_LAT
#define PORT2A IN3_LAT
#define PORT2B IN4_LAT

Motor left, right;
LED led;

void run(void)
{
    runMotor(&left);
    runMotor(&right);
}

void main(void)
{
    SYSTEM_Initialize();
    setPort(&left, IN2_PORT, IN1_PORT);
    setPort(&right, IN3_PORT, IN4_PORT);
    setSpeed(&left, 20);
    setSpeed(&right, 20);
    setDirection(&left, true);
    setDirection(&right, true);
    MODE_LAT = LOW;
    LARGE_LAT = LOW;
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (true) {
        readLed(&led);
        asm("NOP");
    
    
    }
}
