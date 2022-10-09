#include "autoPilot.h"

// typedef enum {
//     LINETRACE,
//     CRANK,
//     CHICANE,
// } State;
// State getState(LED* led)
// {
//     if (led->_LED1 && led->_LED2 && led->_LED7 && led->_LED8)
//         return CRANK;
//     if (led->_LED1 && led->_LED2)
//         return CHICANE;
//     return LINETRACE;
// }
// void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
//     static bool isCrank = true;
//     **leftSpeed = 4;
//     **rightSpeed = 20;
//     return;
// }
// void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
//     static bool isChicane = true;
//     *leftSpeed = 20;
//     *rightSpeed = 15;
//     return;
// }
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    // State state = getState(led);
    // if (state == LINETRACE)
    lineTrace(led, leftSpeed, rightSpeed);
    // else if (state == CRANK)
    //     crank(led, leftSpeed, rightSpeed);
    // else if (state == CHICANE)
    //     chicane(led, leftSpeed, rightSpeed);
    return;
}
void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    //     static double integral = 0.0;
    //     static double derivative = 0.0;
    //     static double lastError = 0.0;
    //     integral += error * dt;
    //     derivative = (error - lastError) / dt;
    //     double pid = Kp * error + Ki * integral + Kd * derivative;
    //     lastError = error;
    int8_t error = (int8_t)led->_LED3A - (int8_t)led->_LED6A;
    double pid = Kp * error;
    *leftSpeed = (uint8_t)(*leftSpeed + 1 + pid);
    *rightSpeed = (uint8_t)(*rightSpeed + 1 - pid);
    asm("NOP");
    return;
}
