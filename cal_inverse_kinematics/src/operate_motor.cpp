#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "operate_motor.h"

using namespace std;

OperateMotor::OperateMotor()
{

}

OperateMotor::~OperateMotor()
{

}

void OperateMotor::operate_single_motor(double *q_cur_rad, double *q_rad_cal, int *data, bool *flg)
{
    //一つひとつのモータを少しずつ動かす
    double delta_rad = (double)(0.2 * M_PI / 180.0);
    int motor_id = (int)(data[1] - 1);

    if (motor_id <= -1 || 4 <= motor_id)
    {
        std::cout << "id is not correct" << std::endl;
        *flg = false;
    }

    if(*flg)
    {
        //double dq_signal = (double)q_cur_signal[motor_id];
        q_rad_cal[motor_id] = q_cur_rad[motor_id];
    }

    q_rad_cal[2] = -q_rad_cal[2];
    q_rad_cal[3] = -q_rad_cal[3];

    /*if (motor_id == 0 || motor_id == 1)
    {
        if (data[2] == 0)
        {
            q_rad_cal[motor_id] -= delta_rad;
        }
        else if (data[2] == 1)
        {
            q_rad_cal[motor_id] += delta_rad;
        }
    }
    else if (motor_id == 2 || motor_id == 3)
    {
        if (data[2] == 0)
        {
            q_rad_cal[motor_id] += delta_rad;
        }
        else if (data[2] == 1)
        {
            q_rad_cal[motor_id] -= delta_rad;
        }
    }*/
    if (data[2] == 0)
    {
        q_rad_cal[motor_id] -= delta_rad;
    }
    else if (data[2] == 1)
    {
        q_rad_cal[motor_id] += delta_rad;
    }
    else if (data[2] == 2)
    {
        q_rad_cal[motor_id] = q_rad_cal[motor_id];
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    }

    else
    {
        *flg = false;
    }
}

void OperateMotor::Ready_for_Throw(double* q_cur_rad, double* q_rad_cal)
{
    //q_rad_cal[0] = 0.0 * M_PI / 180.0;
    q_rad_cal[1] = 90.0 * M_PI / 180.0;
    q_rad_cal[2] = 90.0 * M_PI / 180.0;
    q_rad_cal[3] = 0.0 * M_PI / 180.0;
    //q_rad_cal[2] = -q_rad_cal[2];
    //q_rad_cal[3] = 95.0 * M_PI / 180.0;
}


void OperateMotor::Throw_Ball_Motion(double* q_rad_cal, double* q_release_point)
{
    q_rad_cal[0] = q_release_point[0];
    q_rad_cal[1] = q_release_point[1];
    q_rad_cal[2] = -q_release_point[2];
    q_rad_cal[3] = -q_release_point[3];
    //q_rad_cal[4] = -30.0 * M_PI / 180.0;
}

void OperateMotor::Rerelase_Ball(double* q_rad_cal, double* q_release_point)
{
    q_rad_cal[0] = q_release_point[0];
    q_rad_cal[1] = q_release_point[1];
    q_rad_cal[2] = -q_release_point[2];
    q_rad_cal[3] = -q_release_point[3];
    q_rad_cal[4] = -30.0 * M_PI / 180.0;
}
