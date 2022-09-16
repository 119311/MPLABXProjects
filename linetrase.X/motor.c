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
    if (!self->tempTime) {
        if (!self->speed) {
            if (self->direction) {
                self->port1 = HIGH;
                self->port2 = LOW;
            } else {
                self->port1 = LOW;
                self->port2 = HIGH;
            }
            self->speed--;
        }
        self->tempTime--;
    } else {
        self->tempSpeed = ((self->speed) > BASETIME) ? BASETIME : (self->speed);
        self->tempTime = BASETIME;
    }
}
