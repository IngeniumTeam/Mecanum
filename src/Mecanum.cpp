#include <Arduino.h>

#include "Mecanum.h"

/**
 * Setup the mecanum
 */
Mecanum::Mecanum() {}

void Mecanum::stop()
{
    motors[Left][Top].stop();
    motors[Left][Bottom].stop();
    motors[Right][Top].stop();
    motors[Right][Bottom].stop();
}