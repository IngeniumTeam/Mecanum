#include <Arduino.h>
#include <Motor.h>

#define Left 0
#define Right 1
#define Top 0
#define Bottom 1

class Mecanum
{
public:
	Mecanum(uint8_t in1_1, uint8_t in1_2, uint8_t pwm1, uint8_t offset1,
			uint8_t in2_1, uint8_t in2_2, uint8_t pwm2, uint8_t offset2, uint8_t standBy1,
			uint8_t in3_1, uint8_t in3_2, uint8_t pwm3, uint8_t offset3,
			uint8_t in4_1, uint8_t in4_2, uint8_t pwm4, uint8_t offset4, uint8_t standBy2, int min = 0, int max = 255);
	Motor motors[2][2] = {{Motor(0, 0, 0, 0, 0), Motor(0, 0, 0, 0, 0)}, {Motor(0, 0, 0, 0, 0), Motor(0, 0, 0, 0, 0)}};
	void forward(int speed);
	void forward(int speed, int duration);
	void backward(int speed);
	void backward(int speed, int duration);
	void stop();
	void sidewayLeft(int speed);
	void sidewayRight(int speed);
	void diagonalForward(int speed);
	void diagonalBackward(int speed);
};

class Mecaside
{
public:
	Mecaside(int iSide, Mecanum &iMecanum)
	{
		side = iSide;
		mecanum = iMecanum;
	}
	Mecanum &mecanum;
	int side = 0;
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
	void stop()
	{
		mecanum.motors[side][0].stop();
		mecanum.motors[side][1].stop();
	}
};