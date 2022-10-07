#include "autoPilot.h"
// typedef enum {
//     LINETRACE,
//     CRANK,
//     CHICANE,
// } State;
// static bool hasCranked = false, hasChicaned = false;
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    // State state = getState(led);
    // switch (state) {
    // case LINETRACE:
    lineTrace(led, leftSpeed, rightSpeed);
    //     break;
    // case CRANK:
    //     hasCranked = true;
    //     crank(led, leftSpeed, rightSpeed);
    //     break;
    // case CHICANE:
    //     hasChicaned = true;
    //     chicane(led, leftSpeed, rightSpeed);
    // }
    asm("NOP");
    return;
}
// State getState(LED* led)
// {
//     if (led->_LED1 && led->_LED2 && led->_LED7 && led->_LED8)
//         return CRANK;
//     if (led->_LED1 && led->_LED2)
//         return CHICANE;
//     return LINETRACE;
// }
void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    // static double integral = 0.0;
    // static double derivative = 0.0;
    // static double lastError = 0.0;
    // double error = (double)(led->_LED3A - led->_LED6A);
    // // integral += error * dt;
    // // derivative = (error - lastError) / dt;
    // double pid = Kp * error;
    // // double pid = Kp * error + Ki * integral + Kd * derivative;
    // // lastError = error;
    // *leftSpeed = (uint8_t)(*leftSpeed + 1 + pid);
    // *rightSpeed = (uint8_t)(*rightSpeed + 1 - pid);
    if (led->_LED2)
        *leftSpeed += 6, *rightSpeed -= 2;
    else if (led->_LED7)
        *leftSpeed -= 2, *rightSpeed += 6;
    else
        *leftSpeed += 6, *rightSpeed += 6;
    asm("NOP");

    return;
}
// void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
// }
// void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
// }
