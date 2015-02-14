#include "DCRobot.h"

int DCRobot::speed=0;
int DCRobot::toleft=0;
AF_DCMotor DCRobot::motor1=AF_DCMotor(1);
AF_DCMotor DCRobot::motor2=AF_DCMotor(2);
AF_DCMotor DCRobot::motor3=AF_DCMotor(3);
AF_DCMotor DCRobot::motor4=AF_DCMotor(4);
void DCRobot::reset(){
	SetSpeed(0);
	SetTurnLeft(0);
	Move();
}
void DCRobot::Move(){
	toleft=toleft<-510?-510:(toleft>510?510:toleft);
	speed=speed<-255?-255:(speed>255?255:speed);
	int speedl=speed-toleft;
	int speedr=speed+toleft;
	
	if(speedl>255){
	  speedr-=(speedl-255);
	  speedl=255;
	}
	else if(speedl<-255){
	  speedr-=(speedl+255);
	  speedl=-255;
	}
	else if(speedr>255){
	  speedl-=(speedr-255);
	  speedr=255;
	}
	else if(speedr<-255){
	  speedl-=(speedr+255);
	  speedr=-255;
	}
	
	speedl=speedl<-255?-255:(speedl>255?255:speedl);
	speedr=speedr<-255?-255:(speedr>255?255:speedr);
	
	if(speedl>0){
	  motor1.run(FORWARD);
	  motor4.run(FORWARD);
	}
	else if(speedl<0){
		motor1.run(BACKWARD);
		motor4.run(BACKWARD);
	}
	else if(speedl==0){
		motor1.run(RELEASE);
		motor4.run(RELEASE);
	}
	
	if(speedr>0){
		motor2.run(FORWARD);
		motor3.run(FORWARD);
	}
	else if(speedr<0){
		motor2.run(BACKWARD);
		motor3.run(BACKWARD);
	}
	else if(speedr==0){
		motor2.run(RELEASE);
		motor3.run(RELEASE);
	}
	
	
	motor1.setSpeed(abs(speedl));
	motor4.setSpeed(abs(speedl));
	
	motor2.setSpeed(abs(speedr));
	motor3.setSpeed(abs(speedr));
	
}
void DCRobot::SetSpeed(int speed1){
	speed=speed1;
}
void DCRobot::AddSpeed(int speed1){
	speed+=speed1;
}
void DCRobot::SetTurnLeft(int speed){
	toleft=speed;
}
void DCRobot::AddTurnLeft(int speed){
	toleft+=speed;
}
int DCRobot::GetSpeed(){
	return speed;
}
int DCRobot::GetTurnLeft(){
	return toleft;
}

