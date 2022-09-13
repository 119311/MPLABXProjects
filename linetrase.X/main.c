#include "LED.h"
#include "mcc_generated_files/mcc.h"
#include "motor.h"
Motor left, right;
LED led;

void run(void) {
    runMotor(&left);
    runMotor(&right);

}

void main(void) {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    setPort(&left, IN2_PORT, IN1_PORT);
    setPort(&right, IN3_PORT, IN4_PORT);
    setSpeed(&left, 20);
    setSpeed(&right, 20);
    setDirection(&left, forward);
    setDirection(&right, forward);
    while (true) {
    }
}
