#include "autoPilot.h"
//static bool hasCranked = false, hasChicaned = false;
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    // State state = getState(led);
    // switch (state) {
    // case LINETRACE:
    // lineTrace(led, leftSpeed, rightSpeed);
    // break;
    // case CRANK:
    // hasCranked = true;
    // crank(led, leftSpeed, rightSpeed);
    // break;
    // case CHICANE:
    // hasChicaned = true;
    // chicane(led, leftSpeed, rightSpeed);
    // }
    // }
    // State getState(LED* led)
    // {
    // if (led->_LED1 && led->_LED2 && led->_LED7 && led->_LED8)
    // return CRANK;
    // if (led->_LED1 && led->_LED2)
    // return CHICANE;
    // return LINETRACE;
    // }
    // void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
    // {
    // pid
    // static double integral = 0.0;
    // static double derivative = 0.0;
    // static double lastError = 0.0;
    int8_t error = led->_LED3A - led->_LED6A;
    // integral += error * dt;
    // derivative = (error - lastError) / dt;
    // double pid = Kp * error + Ki * integral + Kd * derivative;
    double pid = Kp * error;

    // lastError = error;
    *leftSpeed = (uint8_t)(*leftSpeed + pid);
    *rightSpeed = (uint8_t)(*rightSpeed - pid);
    return;
}
// void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
// }
// void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed) //{
// }
