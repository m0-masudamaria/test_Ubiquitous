#ifndef OPERATE_MOTOR_H
#define OPERATE_MOTOR_H

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

class OperateMotor
{
public:
	OperateMotor();
	~OperateMotor();

	void operate_single_motor(double* q_cur_rad, double* q_rad_cal, int* data, bool* flg);

	void Ready_for_Throw(double* q_cur_rad, double* q_rad_cal);
	void Throw_Ball_Motion(double* q_rad_cal, double* q_release_point);
	void Rerelase_Ball(double* q_rad_cal, double* q_release_point);

private:
};



#endif // !OPERATE_MOTOR_H
