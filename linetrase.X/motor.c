#include "motor.h"
int get_speed(const Motor* self)
{
    return self->speed;
}
int get_direction(const Motor* self)
{
    return self->direction;
}
void set_speed(Motor* self, uint8_t value)
{
    self->speed = value;
}
void set_direction(Motor* self, bool value)
{
    self->direction = value;
}
