#include "motor.h"
int getSpeed(const Motor* self)
{
    return self->_speed;
}
int getDirection(const Motor* self)
{
    return self->_direction;
}
void setSpeed(Motor* self, uint8_t value)
{
    self->_speed = value;
}
void setDirection(Motor* self, bool value)
{
    self->_direction = value;
}
void setPort(Motor* self, bool port1, bool port2)
{
    self->_port1 = &port1, self->_port2 = &port2;
}
void runMotor(Motor* self)
{
    if (self->_tempTime-- > 0) {
        if (self->_tempSpeed-- > 0) {
            *(self->_port1) = self->_direction;
            *(self->_port2) = !self->_direction;
        } else {
            *(self->_port1) = LOW;
            *(self->_port2) = LOW;
        }
    } else {
        self->_tempSpeed = ((self->_speed) > BASETIME) ? BASETIME : self->_speed;
        self->_tempTime = BASETIME;
    }
}
