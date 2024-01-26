#include <Arduino.h>

class Mecaside
{
public:
    Mecaside(int iSide, int iMiddle)
    {
        side = iSide;
        middle = iMiddle;
    }
    int side;
    int middle;
    void forward(int speed)
    {
        mecanum.motors[side][0].forward(speed);
        mecanum.motors[side][1].forward(speed);
    }
    void backward(int speed)
    {
        mecanum.motors[side][0].backward(speed);
        mecanum.motors[side][1].backward(speed);
    }
    void move(int speed)
    {
        if (speed > middle)
            forward(speed);
        if (speed == middle)
            stop();
        if (speed < middle)
            backward(-speed);
    }
    void stop()
    {
        mecanum.motors[side][0].stop();
        mecanum.motors[side][1].stop();
    }
};