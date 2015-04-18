#ifndef __MOTORDRIVER_H__
#define __MOTORDRIVER_H__
#include <Arduino.h>
/******Pins definitions*************/
#define MOTORSHIELD_IN1	8
#define MOTORSHIELD_IN2	11
#define MOTORSHIELD_IN3	12
#define MOTORSHIELD_IN4	13
#define SPEEDPIN_A		9
#define SPEEDPIN_B		10
/**************Motor ID**********************/
#define MOTORA 			0
#define MOTORB 			1

#define MOTOR_POSITION_LEFT  0
#define MOTOR_POSITION_RIGHT 1
#define CLOCKWISE      0
#define COUNTER_CLOCKWISE  1

#define USE_DC_MOTOR		0

struct MotorStruct
{
	int8_t speed;
	uint8_t direction;
};
/**Class for Motor Shield**/
class MotorDriver
{
	MotorStruct motorA;
	MotorStruct motorB;
public:
	void init();
	void forward();
	void backward();
	void rotateLeft();
	void rotateRight();
	void setSpeed(int8_t speed, uint8_t motorID);
	void rotate(uint8_t direction, uint8_t motorID);
	void stop();
};
extern MotorDriver motordriver;

#endif
