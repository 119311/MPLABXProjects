#include "motor.h"
#include <string.h>
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
void setPort(Motor* self, volatile uint8_t* port, uint8_t addr1, uint8_t addr2)
{
    self->_port = port, self->_addr1 = addr1, self->_addr2 = addr2;
}
void runMotor(Motor* self)
{
    uint8_t tempVal = *self->_port;
    uint8_t temp = 0;
    if (self->_tempTime-- > 0) {
        if (self->_tempSpeed-- > 0) {
            temp += self->_direction ? self->_addr1 : 0;
            temp += self->_direction ? 0 : self->_addr2;
        }
    } else {
        if (!((self->_tempCount++) % 1500))
            self->_speed += 1;
        // self->_tempSpeed = 4;
        self->_tempSpeed = ((self->_speed) > BASETIME) ? BASETIME : self->_speed;
        self->_tempTime = BASETIME;
    }
    *self->_port = (tempVal & ~(self->_addr1 | self->_addr2)) | (temp & (self->_addr1 | self->_addr2));
}
