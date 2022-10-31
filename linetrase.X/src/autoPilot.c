#include "autoPilot.h"
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    // pid
    // static double integral = 0.0;
    // static double derivative = 0.0;
    // static double lastError = 0.0;
    // double error = led->_LED3A - led->_LED6A;
    // integral += error * dt;
    // derivative = (error - lastError) / dt;
    double pid = Kp * error;
    // double pid = Kp * error + Ki * integral + Kd * derivative;
    // lastError = error;
    // *leftSpeed = (uint8_t)(*leftSpeed + pid);
    // *rightSpeed = (uint8_t)(*rightSpeed - pid);
    *leftSpeed = (uint8_t)(*leftSpeed + 1);
    *rightSpeed = (uint8_t)(*rightSpeed + 1);
    return;
}
// void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
// }
// void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
// {
// }
//
