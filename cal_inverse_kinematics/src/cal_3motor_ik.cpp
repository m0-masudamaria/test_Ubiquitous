#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "cal_3motor_ik.h"
#include "basic_function.h"

using namespace std;

Cal3MotorIK::Cal3MotorIK()
{

}

Cal3MotorIK::~Cal3MotorIK()
{

}

void Cal3MotorIK::cal_IK(double *q_rad_cal, int* data, double* link_length, bool* flg)
{
    L0 = { 0, 0, link_length[0] };
    L1 = { 0, 0, link_length[1] };
    L2 = { 0, 0, link_length[2] };
    L3 = { 0, 0, link_length[3] };
    L4 = { 0, 0, link_length[4] };
    
    //３つのモータの逆運動学
    //目標位置、目標角度の代入
    dP = { (double)data[1], (double)data[2], (double)data[3] };
     
    if (b_f_.vector_norm(dP) > 
        (link_length[0] + link_length[1] + link_length[2] + link_length[3] + link_length[4]))
    {
        std::cout << "dP is too far!" << std::endl;
        *flg = false;
    }

    //q0を求める、dP[1]=dP[0]=0の時はそのまま
    if (dP[1] != 0 || dP[0] != 0)
    {
        if (((tan(b_f_.deg2rad(-150)) * dP[0]) <= dP[1]) && (dP[1] <= (tan(b_f_.deg2rad(150)) * dP[0])))
        {
            q_rad_cal[0] = atan2(dP[1], dP[0]) + M_PI;
            std::cout << "out of the range" << std::endl;
            //std::cout << "atan2      = " << atan2(dP[1], dP[0]) << std::endl;
            //std::cout << "atan2 + pi = " << q_rad_cal[0] << std::endl;
        }
        else
        {
            q_rad_cal[0] = atan2(dP[1], dP[0]);
        }
    }

    //いろいろ定義
    P0 = L0;
    P1 = b_f_.vector_sum(L0, L1);
    P3 = dP;
    P13 = b_f_.vector_dif(P3, P1);

    std::vector<double> L34 = { L3[0] + L4[0],L3[1] + L4[1], L3[2] + L4[2] };

    //q2を求めるための引数を計算
    double cos_val;
    cos_val = b_f_.vector_norm(P13) * b_f_.vector_norm(P13);
    cos_val -= b_f_.vector_norm(L2) * b_f_.vector_norm(L2) + b_f_.vector_norm(L34) * b_f_.vector_norm(L34);
    cos_val /= 2 * b_f_.vector_norm(L2) * b_f_.vector_norm(L34);

    std::cout << "cos(q2) = " << cos_val << std::endl;

    if (fabs(cos_val) > 1.0)
    {
        *flg = false;
        std::cout << "cos value is NOT good" << std::endl;
    }

    if (tan(b_f_.deg2rad(-150)) * dP[0] <= dP[1] && dP[1] < tan(b_f_.deg2rad(150)) * dP[0])
    {
        q_rad_cal[2] = -acos(cos_val);
    }
    else
    {
        q_rad_cal[2] = acos(cos_val);
    }

    if (fabs(q_rad_cal[2] - M_PI) < 0.1 || fabs(q_rad_cal[2] + M_PI) < 0.1)
    {
        *flg = false;
        std::cout << "q2 is not good" << std::endl;
    }

    //q1を求めるための計算
            // SinCos = 1 / d * AA * PP
    std::vector<double> SinCos = { 0, 0 };

    double PP[2] = { dP[0] * cos(q_rad_cal[0]) + dP[1] * sin(q_rad_cal[0]),
                    dP[2] - (link_length[0] + link_length[1])};


    double AA[2][2] = { {link_length[2] + (link_length[3] + link_length[4]) * cos(q_rad_cal[2]),       -(link_length[3] + link_length[4]) * sin(q_rad_cal[2])},
                        {       (link_length[3] + link_length[4]) * sin(q_rad_cal[2]), link_length[2] + (link_length[3] + link_length[4]) * cos(q_rad_cal[2])}};


    double d;
    d = AA[0][0] * AA[1][1] - AA[0][1] * AA[1][0];

    for (int i = 0; i < 2; i++)
    {
        SinCos[0] += 1 / d * AA[0][i] * PP[i];
        SinCos[1] += 1 / d * AA[1][i] * PP[i];
    }

    q_rad_cal[1] = atan2(SinCos[0], SinCos[1]);

    //q3 
    q_rad_cal[3] = 0;
}
