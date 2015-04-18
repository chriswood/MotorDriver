/* This is a much condensed version of the older driver.
   Chris Wood, April 17, 2015
/*******************************************************************************/
#include "MotorDriver.h"

void MotorDriver::init() {
	pinMode(MOTORSHIELD_IN1, OUTPUT);
	pinMode(MOTORSHIELD_IN2, OUTPUT);
	pinMode(MOTORSHIELD_IN3, OUTPUT);
	pinMode(MOTORSHIELD_IN4, OUTPUT);
	pinMode(SPEEDPIN_A, OUTPUT);
	pinMode(SPEEDPIN_B, OUTPUT);
	stop();
	setSpeed(255, MOTORA);
	setSpeed(255, MOTORB);
}

int _getSpeedPin(uint8_t motorID) {
	if(motorID == MOTORA) {
		return(SPEEDPIN_A);
	}
	else {
		return(SPEEDPIN_B);
	}
}

void MotorDriver::forward() {
    rotate(COUNTER_CLOCKWISE, MOTORA);
    rotate(CLOCKWISE, MOTORB);
}

void MotorDriver::setSpeed(int8_t speed, uint8_t motorID) {
	if(motorID == MOTORA) {
        motorA.speed = speed;
    }
	else if(motorID == MOTORB) {
        motorB.speed = speed;
    }
}

void MotorDriver::rotate(uint8_t direction, uint8_t motorID) {
	uint8_t in1_level = LOW;
	uint8_t in2_level = LOW;

	if(direction == CLOCKWISE) {
		in2_level = HIGH;
	}
	else {
		in1_level = HIGH;
	}

	if(motorID == MOTORA) {
		analogWrite(SPEEDPIN_A, motorA.speed);
		digitalWrite(MOTORSHIELD_IN1, in1_level);
     	digitalWrite(MOTORSHIELD_IN2, in2_level);
	}
	else if(motorID == MOTORB) {
		analogWrite(SPEEDPIN_B, motorB.speed);
		digitalWrite(MOTORSHIELD_IN3, in1_level);
     	digitalWrite(MOTORSHIELD_IN4, in2_level);
	}
}

void MotorDriver::stop() {
	digitalWrite(SPEEDPIN_A,LOW);
    digitalWrite(SPEEDPIN_B,LOW);
}

MotorDriver motordriver;
