#include <Arduino.h>

#include "Mecanum.h"

/**
 * Setup the mecanum
 */
Mecanum::Mecanum(uint8_t in1_1, uint8_t in1_2, uint8_t pwm1, uint8_t offset1,
                 uint8_t in2_1, uint8_t in2_2, uint8_t pwm2, uint8_t offset2, uint8_t standBy1,
                 uint8_t in3_1, uint8_t in3_2, uint8_t pwm3, uint8_t offset3,
                 uint8_t in4_1, uint8_t in4_2, uint8_t pwm4, uint8_t offset4, uint8_t standBy2, int min = 0, int max = 255)
{
    motors[Left][Top] = Motor(in1_1, in1_2, pwm1, offset1, standBy1, min, max);
    motors[Left][Bottom] = Motor(in2_1, in2_2, pwm2, offset2, standBy1, min, max);
    motors[Right][Top] = Motor(in3_1, in3_2, pwm3, offset3, standBy2, min, max);
    motors[Right][Bottom] = Motor(in4_1, in4_2, pwm4, offset4, standBy2, min, max);
}

void Mecanum::forward(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Left][Bottom].forward(speed);
    motors[Right][Top].forward(speed);
    motors[Right][Bottom].forward(speed);
}

void Mecanum::forward(int speed, int duration)
{
    motors[Left][Top].forward(speed, duration);
    motors[Left][Bottom].forward(speed, duration);
    motors[Right][Top].forward(speed, duration);
    motors[Right][Bottom].forward(speed, duration);
}

void Mecanum::backward(int speed)
{
    motors[Left][Top].backward(speed);
    motors[Left][Bottom].backward(speed);
    motors[Right][Top].backward(speed);
    motors[Right][Bottom].backward(speed);
}

void Mecanum::backward(int speed, int duration)
{
    motors[Left][Top].backward(speed, duration);
    motors[Left][Bottom].backward(speed, duration);
    motors[Right][Top].backward(speed, duration);
    motors[Right][Bottom].backward(speed, duration);
}

void Mecanum::stop()
{
    motors[Left][Top].stop();
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].stop();
}

void Mecanum::sidewayLeft(int speed)
{
    motors[Left][Top].backward(speed);
    motors[Left][Bottom].forward(speed);
    motors[Right][Top].backward(speed);
    motors[Right][Bottom].forward(speed);
}

void Mecanum::sidewayRight(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Left][Bottom].backward(speed);
    motors[Right][Top].forward(speed);
    motors[Right][Bottom].backward(speed);
}

void Mecanum::diagonalForward(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].forward(speed);
}

void Mecanum::diagonalBackward(int speed)
{
    motors[Left][Top].stop();
    motors[Left][Bottom].forward(speed);
    motors[Right][Top].forward(speed);
    motors[Right][Bottom].stop();
}