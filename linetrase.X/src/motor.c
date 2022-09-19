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
void setPort(Motor* self, bool port1, bool port2)
{
    self->port1 = &port1, self->port2 = &port2;
}
void runMotor(Motor* self)
{
    if (self->tempTime-- > 0) {
        if (self->tempSpeed-- > 0) {
            *(self->port1) = self->direction;
            *(self->port2) = !self->direction;
        } else {
            *(self->port1) = LOW;
            *(self->port2) = LOW;
        }
        } else {
        self->tempSpeed = ((self->speed) > BASETIME) ? BASETIME : self->speed;
        self->tempTime = BASETIME;
    }
}
