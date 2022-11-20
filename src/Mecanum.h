#include <Arduino.h>
#include <Motor.h>

#define Left 0
#define Right 1
#define Top 0
#define Bottom 1

class Mecanum
{
    public:
        Mecanum();
        Motor motors[2][2] = { { Motor(2, 3), Motor(4, 5) }, { Motor(6, 7), Motor(8, 9) } };
        void stop();
};
