#include <Arduino.h>

#include "Mecanum.h"

/**
 * Setup the mecanum
 */
Mecanum::Mecanum(uint8_t in1_1, uint8_t in1_2, uint8_t pwm1,
                 uint8_t in2_1, uint8_t in2_2, uint8_t pwm2, uint8_t standBy1,
                 uint8_t in3_1, uint8_t in3_2, uint8_t pwm3,
                 uint8_t in4_1, uint8_t in4_2, uint8_t pwm4, uint8_t standBy2,
                 int fromMin = 0, int fromMax = 1023, int toMin = 0, int toMax = 255)
{
    middle = (fromMax - fromMin) / 2;
    motors[Left][Front] = Motor(in1_1, in1_2, pwm1, standBy1, fromMin, fromMax, toMin, toMax);
    motors[Left][Back] = Motor(in2_1, in2_2, pwm2, standBy1, fromMin, fromMax, toMin, toMax);
    motors[Right][Front] = Motor(in3_1, in3_2, pwm3, standBy2, fromMin, fromMax, toMin, toMax);
    motors[Right][Back] = Motor(in4_1, in4_2, pwm4, standBy2, fromMin, fromMax, toMin, toMax);
}

void Mecanum::forward(int speed)
{
    motors[Left][Front].forward(speed);
    motors[Left][Back].forward(speed);
    motors[Right][Front].forward(speed);
    motors[Right][Back].forward(speed);
}

void Mecanum::backward(int speed)
{
    motors[Left][Front].backward(speed);
    motors[Left][Back].backward(speed);
    motors[Right][Front].backward(speed);
    motors[Right][Back].backward(speed);
}

void Mecanum::move(int speed)
{
    if (speed > middle)
        forward(speed);
    if (speed == middle)
        stop();
    if (speed < middle)
        backward(-speed);
}

void Mecanum::stop()
{
    motors[Left][Front].stop();
    motors[Left][Back].stop();
    motors[Right][Front].stop();
    motors[Right][Back].stop();
}

void Mecanum::sideway(int speed)
{
    if (speed > middle)
        sidewayRight(speed);
    if (speed < middle)
        sidewayLeft(-speed);
}

void Mecanum::sidewayLeft(int speed)
{
    motors[Left][Front].backward(speed);
    motors[Left][Back].forward(speed);
    motors[Right][Front].forward(speed);
    motors[Right][Back].backward(speed);
}

void Mecanum::sidewayRight(int speed)
{
    motors[Left][Front].forward(speed);
    motors[Left][Back].backward(speed);
    motors[Right][Front].backward(speed);
    motors[Right][Back].forward(speed);
}

void Mecanum::diagonal(int xSpeed, int ySpeed)
{
    if (xSpeed > middle)
        diagonalLeft(ySpeed);
    if (xSpeed < middle)
        diagonalRight(ySpeed);
}

void Mecanum::diagonalLeft(int speed)
{
    if (speed > middle)
        diagonalLeftForward(speed);
    if (speed < middle)
        diagonalLeftBackward(-speed);
}

void Mecanum::diagonalRight(int speed)
{
    if (speed > middle)
        diagonalRightForward(speed);
    if (speed < middle)
        diagonalRightBackward(-speed);
}

void Mecanum::diagonalLeftForward(int speed)
{
    motors[Left][Front].stop();
    motors[Left][Back].forward(speed);
    motors[Right][Front].forward(speed);
    motors[Right][Back].stop();
}

void Mecanum::diagonalRightForward(int speed)
{
    motors[Left][Front].forward(speed);
    motors[Left][Back].stop();
    motors[Right][Front].stop();
    motors[Right][Back].forward(speed);
}

void Mecanum::diagonalLeftBackward(int speed)
{
    motors[Left][Front].stop();
    motors[Left][Back].backward(speed);
    motors[Right][Front].backward(speed);
    motors[Right][Back].stop();
}

void Mecanum::diagonalRightBackward(int speed)
{
    motors[Left][Front].backward(speed);
    motors[Left][Back].stop();
    motors[Right][Front].stop();
    motors[Right][Back].backward(speed);
}

void Mecanum::setMaxSpeed(int speed)
{
    motors[Left][Front].toMax = speed;
    motors[Left][Back].toMax = speed;
    motors[Right][Front].toMax = speed;
    motors[Right][Back].toMax = speed;
}