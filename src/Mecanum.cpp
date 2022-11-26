#include <Arduino.h>

#include "Mecanum.h"

/**
 * Setup the mecanum
 */
Mecanum::Mecanum(uint8_t leftTop1, uint8_t leftTop2, uint8_t leftBottom1, uint8_t leftBottom2, uint8_t rightTop1, uint8_t rightTop2, uint8_t rightBottom1, uint8_t rightBottom2)
{
    motors[Left][Top] = Motor(leftTop1, leftTop2);
    motors[Left][Bottom] = Motor(leftBottom1, leftBottom2);
    motors[Right][Top] = Motor(rightTop1, rightTop2);
    motors[Right][Bottom] = Motor(rightBottom1, rightBottom2);
}

void Mecanum::forward(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Left][Bottom].forward(speed);
    motors[Right][Top].forward(speed);
    motors[Right][Bottom].forward(speed);
}

void Mecanum::backward(int speed)
{
    motors[Left][Top].backward(speed);
    motors[Left][Bottom].backward(speed);
    motors[Right][Top].backward(speed);
    motors[Right][Bottom].backward(speed);
}

void Mecanum::stop()
{
    motors[Left][Top].stop();
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].stop();
}