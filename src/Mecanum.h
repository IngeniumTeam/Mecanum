#include <Arduino.h>
#include <Motor.h>

#define Left 0
#define Right 1
#define Top 0
#define Bottom 1

class Mecanum
{
    public:
        Mecanum(uint8_t leftTop1, uint8_t leftTop2, uint8_t leftBottom1, uint8_t leftBottom2, uint8_t rightTop1, uint8_t rightTop2, uint8_t rightBottom1, uint8_t rightBottom2);
        Motor motors[2][2] = { { Motor(0, 0), Motor(0, 0) }, { Motor(0, 0), Motor(0, 0) } };
        void forward(int speed);
        void backward(int speed);
        void stop();
};
