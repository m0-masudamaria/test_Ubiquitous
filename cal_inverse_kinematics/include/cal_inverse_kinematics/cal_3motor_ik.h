#ifndef CAL_3MOTOR_IK_H
#define CAL_3MOTOR_IK_H

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "basic_function.h"

class Cal3MotorIK
{
public:
	Cal3MotorIK();
	~Cal3MotorIK();

	void cal_IK(double* q_rad_cal, int* dP_array, double* link_length, bool* flg);

private:
	BasicFunction b_f_;
	
	//手先の目標座標
	std::vector<double> dP;

	//手先の目標角度 rad
	double dq;

	//計算して得られたモータの角度
	//基準:0
	//double q_rad_cal[5];

	//L4のベクトル
	std::vector<double> L4_cur_vec;

	//対偶の位置
	std::vector<double> P0;
	std::vector<double> P1;
	std::vector<double> P3;
	std::vector<double> P4;
	std::vector<double> P13;

	//初期姿勢のリンクのベクトル
	std::vector<double> L0;
	std::vector<double> L1;
	std::vector<double> L2;
	std::vector<double> L3;
	std::vector<double> L4;


};



#endif // !CAL_3MOTOR_IK_H
