#ifndef _DCRobot_h_
#define _DCRobot_h_

#include <Arduino.h>
#include <AFMotor.h>

class DCRobot{
	static AF_DCMotor motor1;
	static AF_DCMotor motor2;
	static AF_DCMotor motor3;
	static AF_DCMotor motor4;
	static int speed;
	static int toleft;
	public:
	static void Move();//apply changes
	static void SetSpeed(int speed);
	static void AddSpeed(int speed);
	static void SetTurnLeft(int speed);
	static void AddTurnLeft(int speed);
	static int GetSpeed();
	static int GetTurnLeft();
	static void reset();
};

#endif
