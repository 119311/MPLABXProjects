#include "motor.h"

int getSpeed(const Motor* self)
{
    return self->speed;
}

int getDirection(const Motor* self)
{
    return self->direction;
}

void setSpeed(Motor* self, uint8_t value)
{
    self->speed = value;
}

void setDirection(Motor* self, bool value)
{
    self->direction = value;
}

void setPort(Motor* self, PORTBbits_t* port1, PORTBbits_t* port2)
{
    self->port1 = port1;
    self->port2 = port2;
}

void runMotor(Motor* self)
{
    uint8_t tempSpeed = ((self->speed) > BASETIME) ? BASETIME : (self->speed);
    uint8_t tempTime = BASETIME;
    bool temp = false;
    tempTime--;
}
