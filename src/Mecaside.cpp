#include <Arduino.h>

#include "Mecanum.h"

Mecaside::Mecaside(int iSide)
{
    side = iSide;
}
void Mecaside::forward(int speed)
{
    mecanum.motors[side][Front].forward(speed);
    mecanum.motors[side][Back].forward(speed);
}
void Mecaside::backward(int speed)
{
    mecanum.motors[side][Front].backward(speed);
    mecanum.motors[side][Back].backward(speed);
}
void Mecaside::move(int speed)
{
    if (speed > 0)
        forward(speed);
    if (speed == 0)
        stop();
    if (speed < 0)
        backward(-speed);
}
void Mecaside::stop()
{
    mecanum.motors[side][Front].stop();
    mecanum.motors[side][Back].stop();
}