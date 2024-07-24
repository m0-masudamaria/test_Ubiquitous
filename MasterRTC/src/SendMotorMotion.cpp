#include <iostream>

#include "SendMotorMotion.h"

SendMotorMotion::SendMotorMotion()
{

}

SendMotorMotion::~SendMotorMotion()
{

}

void SendMotorMotion::Grab_Ball_Position_1(uint16_t* motor_data)
{
	motor_data[0] = 0; //send_arg[0];
	motor_data[1] = 60; //send_arg[1];
	motor_data[2] = 0;//send_arg[2];
	motor_data[3] = 80;//send_arg[3];
	motor_data[4] = 180;//send_arg[4];
}

void SendMotorMotion::Grab_Ball_Position_2(uint16_t* motor_data)
{
	motor_data[0] = 0; //send_arg[0];
	motor_data[1] = -10; //send_arg[1];
	motor_data[2] = -60;//send_arg[2];
	motor_data[3] = 80; //send_arg[3];
	motor_data[4] = 180;//send_arg[4];
}

void SendMotorMotion::Grab_Ball_Position_3(uint16_t* motor_data)
{
	motor_data[0] = 0; //send_arg[0];
	motor_data[1] = -20; //send_arg[1];
	motor_data[2] = -100;//send_arg[2];
	motor_data[3] = 150; //send_arg[3];
	motor_data[4] = 100;//send_arg[4];
}
void SendMotorMotion::Grab_Ball(uint16_t* motor_data)
{
	motor_data[0] = 4;
	motor_data[1] = 1;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;
}

void SendMotorMotion::Open_Hand(uint16_t* motor_data)
{
	motor_data[0] = 4;
	motor_data[1] = 2;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;
}

void SendMotorMotion::Throw_Ball_iniPosition(uint16_t* motor_data)
{
	motor_data[0] = 3;
	motor_data[1] = 0;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;
}

void SendMotorMotion::Input_Throw_Position(uint16_t* motor_data)
{
	motor_data[0] = 5;
	motor_data[1] = 0;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;
}

void SendMotorMotion::Throw_Ball(uint16_t* motor_data)
{
	motor_data[0] = 5;
	motor_data[1] = 1;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;
}

void SendMotorMotion::Stop_Motor(uint16_t* motor_data, int motor_id)
{
	motor_data[0] = 2;
	motor_data[1] = motor_id;
	motor_data[2] = 2;
	motor_data[3] = 0;
	motor_data[4] = 0;
}


void SendMotorMotion::Positive_Rotation(uint16_t *motor_data, int motor_id)
{
	motor_data[0] = 2;
	motor_data[1] = motor_id;
	motor_data[2] = 1;
	motor_data[3] = 0;
	motor_data[4] = 0;
}


void SendMotorMotion::Negative_Rotation(uint16_t* motor_data, int motor_id)
{
	motor_data[0] = 2;
	motor_data[1] = motor_id;
	motor_data[2] = 0;
	motor_data[3] = 0;
	motor_data[4] = 0;

}

