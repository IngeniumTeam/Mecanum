#include <Arduino.h>

#include "Mecanum.h"

/**
 * Setup the mecanum
 */
Mecanum::Mecanum(uint8_t in1_1, uint8_t in1_2, uint8_t pwm1, uint8_t offset1,
                 uint8_t in2_1, uint8_t in2_2, uint8_t pwm2, uint8_t offset2, uint8_t standBy1,
                 uint8_t in3_1, uint8_t in3_2, uint8_t pwm3, uint8_t offset3,
                 uint8_t in4_1, uint8_t in4_2, uint8_t pwm4, uint8_t offset4, uint8_t standBy2,
                 int fromMin = 0, int fromMax = 1023, int toMin = 0, int toMax = 255)
{
    motors[Left][Top] = Motor(in1_1, in1_2, pwm1, offset1, standBy1, fromMin, fromMax, toMin, toMax);
    motors[Left][Bottom] = Motor(in2_1, in2_2, pwm2, offset2, standBy1, fromMin, fromMax, toMin, toMax);
    motors[Right][Top] = Motor(in3_1, in3_2, pwm3, offset3, standBy2, fromMin, fromMax, toMin, toMax);
    motors[Right][Bottom] = Motor(in4_1, in4_2, pwm4, offset4, standBy2, fromMin, fromMax, toMin, toMax);
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

void Mecanum::move(int speed)
{
    if (speed > 0)
        forward(speed);
    if (speed == 0)
        stop();
    if (speed < 0)
        backward(speed);
}

void Mecanum::move(int speed, int duration)
{
    if (speed > 0)
        forward(speed, duration);
    if (speed == 0)
        stop();
    if (speed < 0)
        backward(speed, duration);
}

void Mecanum::stop()
{
    motors[Left][Top].stop();
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].stop();
}

void Mecanum::sideway(int speed)
{
    if (speed > 0)
        sidewayRight(speed);
    if (speed < 0)
        sidewayLeft(speed);
}

void Mecanum::sidewayLeft(int speed)
{
    motors[Left][Top].backward(speed);
    motors[Right][Top].backward(speed);
    motors[Left][Bottom].forward(speed);
    motors[Right][Bottom].forward(speed);
}

void Mecanum::sidewayRight(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Right][Top].forward(speed);
    motors[Left][Bottom].backward(speed);
    motors[Right][Bottom].backward(speed);
}

void Mecanum::diagonal(int xSpeed, int ySpeed)
{
    if (xSpeed > 0)
        diagonalLeft(ySpeed);
    if (xSpeed < 0)
        diagonalRight(ySpeed);
}

void Mecanum::diagonalLeft(int speed)
{
    if (speed > 0)
        diagonalLeftForward(speed);
    if (speed < 0)
        diagonalLeftBackward(speed);
}

void Mecanum::diagonalRight(int speed)
{
    if (speed > 0)
        diagonalRightForward(speed);
    if (speed < 0)
        diagonalRightBackward(speed);
}

void Mecanum::diagonalLeftForward(int speed)
{
    motors[Left][Top].forward(speed);
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].forward(speed);
}

void Mecanum::diagonalRightForward(int speed)
{
    motors[Left][Top].stop();
    motors[Left][Bottom].forward(speed);
    motors[Right][Top].forward(speed);
    motors[Right][Bottom].stop();
}

void Mecanum::diagonalLeftBackward(int speed)
{
    motors[Left][Top].backward(speed);
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].backward(speed);
}

void Mecanum::diagonalRightBackward(int speed)
{
    motors[Left][Top].stop();
    motors[Left][Bottom].backward(speed);
    motors[Right][Top].backward(speed);
    motors[Right][Bottom].stop();
}