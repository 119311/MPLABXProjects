#include "autoPilot.h"
typedef enum {
    LINETRACE,
    CRANK,
    CHICANE,
} State;
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    State state = getState(led);
    if (state == LINETRACE) {
        lineTrace(led, leftSpeed, rightSpeed);
    } else if (state == CRANK) {
        crank(led, leftSpeed, rightSpeed);
    } else if (state == CHICANE) {
        chicane(led, leftSpeed, rightSpeed);
    }
}
State getState(LED* led)
{
    if ((led->_LED1 && led->_LED2 && led->_LED7 && led->_LED8))
        return CRANK;
    if (led->_LED7 && led->_LED8)
        return CHICANE;
    return LINETRACE;
}
void lineTrace(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    
}
void crank(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    
}
void chicane(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    
}
