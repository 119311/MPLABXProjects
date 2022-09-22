#include "autoPilot.h"
typedef enum {
    LINETRACE,
    CRANK,
    CHICANE,
} State;
static bool hasCranked = false, hasChicaned = false;
void autoPilot(LED* led, uint8_t* leftSpeed, uint8_t* rightSpeed)
{
    State state = getState(led);
    switch (state) {
    case LINETRACE:
        lineTrace(led, leftSpeed, rightSpeed);
        break;
    case CRANK:
        hasCranked = true;
        crank(led, leftSpeed, rightSpeed);
        break;
    case CHICANE:
        hasChicaned = true;
        chicane(led, leftSpeed, rightSpeed);
    }
}
State getState(LED* led)
{
    if (led->_LED1 && led->_LED2 && led->_LED7 && led->_LED8)
        return CRANK;
    if (led->_LED1 && led->_LED2)
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
