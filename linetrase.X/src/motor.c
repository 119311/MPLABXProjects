#include "motor.h"
uint8_t getSpeed(const Motor* self)
{
    return self->_speed;
}
uint8_t getTargetSpeed(const Motor* self)
{
    return self->_targetSpeed;
}
bool getDirection(const Motor* self)
{
    return self->_direction;
}
void setSpeed(Motor* self, uint8_t value)
{
    uint8_t nowValue = getSpeed(self);
    int8_t difference = value - nowValue;
    if (difference >> 8)
        nowValue -= (((1 + difference) >> 8) ? 4 : -difference);
    else if (difference)
        nowValue += (nowValue - 4) >> 8 ? 1 : ((difference - 1) >> 8 ? difference : 2);
    nowValue = nowValue ? nowValue : 1;
    nowValue = 0 < nowValue - BASETIME ? BASETIME : nowValue;
    self->_speed = nowValue;
}
void setTargetSpeed(Motor* self, uint8_t value)
{
    self->_targetSpeed = value;
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
    uint8_t tempVal = *self->_port, temp = 0;
    if (self->_tempTime-- > 0) {
        if (self->_tempSpeed-- > 0)
            temp += getDirection(self) ? self->_addr1 : self->_addr2;
    } else {
        if (!((self->_tempCount++) % 400))
            setSpeed(self, getSpeed(self) + 1);
        self->_tempSpeed = getSpeed(self);
        self->_tempTime = BASETIME;
    }
    *self->_port = (tempVal & ~(self->_addr1 | self->_addr2)) | (temp & (self->_addr1 | self->_addr2));
}
