#ifndef SENDMOTORMOTION_H
#define SENDMOTORMOTION_H

#include <iostream>

class SendMotorMotion
{
public:
	SendMotorMotion();
	~SendMotorMotion();

	void Grab_Ball_Position(uint16_t* motor_data);
	void Grab_Ball(uint16_t* motor_data);
	void Open_Hand(uint16_t* motor_data);

	void Throw_Ball_iniPosition(uint16_t* motor_data);
	void Input_Throw_Position(uint16_t* motor_data);
	void Throw_Ball(uint16_t* motor_data);

	void Stop_Motor(uint16_t* motor_data, int motor_id);
	void Positive_Rotation(uint16_t* motor_data, int motor_id);
	void Negative_Rotation(uint16_t* motor_data, int motor_id);

private:
};


#endif // !SENDMOTORMOTION_H
