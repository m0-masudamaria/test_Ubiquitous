﻿// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  cal_inverse_kinematics.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include "cal_inverse_kinematics.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const cal_inverse_kinematics_spec[] =
#else
static const char* cal_inverse_kinematics_spec[] =
#endif
  {
    "implementation_id", "cal_inverse_kinematics",
    "type_name",         "cal_inverse_kinematics",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "TMU",
    "category",          "calculate inverse kinematics",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.motor_num", "4",
    "conf.default.L0", "40",
    "conf.default.L1", "26.5",
    "conf.default.L2", "83",
    "conf.default.L3", "93.5",
    "conf.default.L4", "63.5",

    // Widget
    "conf.__widget__.motor_num", "text",
    "conf.__widget__.L0", "text",
    "conf.__widget__.L1", "text",
    "conf.__widget__.L2", "text",
    "conf.__widget__.L3", "text",
    "conf.__widget__.L4", "text",
    // Constraints

    "conf.__type__.motor_num", "short",
    "conf.__type__.L0", "double",
    "conf.__type__.L1", "double",
    "conf.__type__.L2", "double",
    "conf.__type__.L3", "double",
    "conf.__type__.L4", "double",

    ""
  };
// </rtc-template>

double deg2rad(double deg)
{
    return deg * M_PI / 180.0;
}

std::vector<double> vector_sum(std::vector<double> vector1, std::vector<double> vector2)
{
    std::vector<double> sum;

    if (vector1.size() != vector2.size())
    {
        std::cout<< "size is NOT same" << std::endl;
        return sum;
    }

    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        double sum_tmp;
        sum_tmp = vector1[i] + vector2[i];
        sum.push_back(sum_tmp);
    }

    return sum;
}

std::vector<double> vector_dif(std::vector<double> vector1, std::vector<double> vector2)
{
    std::vector<double> dif;

    if (vector1.size() != vector2.size())
    {
        std::cout<< "size is NOT same" << std::endl;

        return dif;
    }

    for (unsigned int i = 0; i < vector1.size(); i++)
    {
        double dif_tmp;
        dif_tmp = vector1[i] - vector2[i];
        dif.push_back(dif_tmp);
    }

    return dif;
}

double vector_length(std::vector<double> vector_1)
{
    if (vector_1.size() != 3)
    {
        std::cout<< "vector size is NOT 3!" << std::endl;
        return 1000000000.0;
    }

    double sum_squared = 0.0;
    for (unsigned int i = 0; i < vector_1.size(); i++)
    {
        sum_squared += vector_1[i] * vector_1[i];
    }

    return sqrt(sum_squared);
}

bool check_rad_range(double *m_rad, short motor_num)
{
    //モータの角度が範囲に収まっている必要がある
    double rad_range[5][2] = { {-150.0, 150.0},
                               {-100.0, 100.0},
                               {-142.0, 137.0},
                               {-100.0, 100.0},
                               {-100.0,  35.0}};

    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            rad_range[i][j] *= M_PI / 180.0;
        }
    }

    while (*m_rad < rad_range[motor_num][0])
    {
        *m_rad += 2.0 * M_PI;
    }

    while (rad_range[motor_num][1] < *m_rad)
    {
        *m_rad -= 2.0 * M_PI;
    }

    if (rad_range[motor_num][0] <= *m_rad && *m_rad < rad_range[motor_num][1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

short rad2goalPosition(double rad_q)
{
    rad_q = rad_q * 180.0 / M_PI;
 
    std::cout << "deg: " << rad_q << std::endl;
    rad_q += 150;

    short signal;
    //signal = (rad_q - 0) * (1024 - 0) / (300 - 0) + 0;
    signal = (short)(rad_q * 512.0 / 150.0);

    std::cout << "signal: " << signal << std::endl;

    return signal;
}

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
cal_inverse_kinematics::cal_inverse_kinematics(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_d_positionIn("d_position", m_d_position),
    m_motor_degOut("motor_deg", m_motor_deg),
    m_motor_speedOut("motor_speed", m_motor_speed),
    m_hand_axisOut("hand_axis", m_hand_axis)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
cal_inverse_kinematics::~cal_inverse_kinematics()
{
}



RTC::ReturnCode_t cal_inverse_kinematics::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("d_position", m_d_positionIn);
  
  // Set OutPort buffer
  addOutPort("motor_deg", m_motor_degOut);
  addOutPort("motor_speed", m_motor_speedOut);
  addOutPort("m_hand_axis", m_hand_axisOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("motor_num", m_motor_num, "4");
  bindParameter("L0", m_l0, "50");
  bindParameter("L1", m_l1, "50");
  bindParameter("L2", m_l2, "50");
  bindParameter("L3", m_l3, "50");
  bindParameter("L4", m_l4, "50");
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t cal_inverse_kinematics::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t cal_inverse_kinematics::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematics::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t cal_inverse_kinematics::onActivated(RTC::UniqueId /*ec_id*/)
{
    flg = true;

    L0 = { 0, 0, m_l0 };
    L1 = { 0, 0, m_l1 };
    L2 = { 0, 0, m_l2 };
    L3 = { 0, 0, m_l3 };
    L4 = { 0, 0, m_l4 };

    for (int i = 0; i < m_motor_num; i++)
    {
        q_cal[i] = 0.0;
    }

    for (int i = 0; i < 5; i++)
    {
        q_cur_signal[i] = 512;
        q_cur_rad[i] = (double)((150.0 / 512.0 * q_cur_signal[i] - 150.0) * M_PI / 180.0);;
    }


    
  return RTC::RTC_OK;
}


RTC::ReturnCode_t cal_inverse_kinematics::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t cal_inverse_kinematics::onExecute(RTC::UniqueId /*ec_id*/)
{

    if (m_d_positionIn.isNew())
    {
        std::cout << "=====================================" << std::endl;

        m_d_positionIn.read();

        flg = true;

        //必要な配列長であるか判断
        if (m_d_position.data[0] == 0 && m_d_position.data.length() == 5)
        {

            //目標位置、目標角度の代入
            dP = {(double)m_d_position.data[1], (double)m_d_position.data[2], (double)m_d_position.data[3] };
            dq = deg2rad(m_d_position.data[4]);

            if (vector_length(dP) > (m_l0 + m_l1 + m_l2 + m_l3 + m_l4))
            {
                std::cout << "dP is too far!" << std::endl;
                flg = false;
            }
            
            //q0を求める、dP[1]=dP[0]=0の時はそのまま
            if (dP[1] != 0 || dP[0] != 0)
            {
                //可動域ではない範囲に入ったらPIだけ回すようにする
                if (((tan(deg2rad(-150)) * dP[0]) <= dP[1]) && (dP[1] <= (tan(deg2rad(150)) * dP[0])))
                {
                    q_cal[0] = atan2(dP[1], dP[0]) + M_PI;
                    std::cout << "out of the range" << std::endl;
                    //std::cout << "atan2      = " << atan2(dP[1], dP[0]) << std::endl;
                    //std::cout << "atan2 + pi = " << q_cal[0] << std::endl;
                }
                else
                {
                    q_cal[0] = atan2(dP[1], dP[0]);
                }
            }

            //いろいろ定義
            L4_cur_vec = { m_l4 * sin(dq) * cos(q_cal[0]), m_l4 * sin(dq) * sin(q_cal[0]), m_l4 * cos(dq) };
            P0 = L0;
            P1 = vector_sum(L0, L1);
            P3 = vector_dif(dP, L4_cur_vec);
            P4 = dP;

            P13 = vector_dif(P3, P1);

            //q2を求めるための引数を計算
            double cos_val;
            cos_val = vector_length(P13) * vector_length(P13);
            cos_val -= vector_length(L2) * vector_length(L2) + vector_length(L3) * vector_length(L3);
            cos_val /= 2 * vector_length(L2) * vector_length(L3);

            std::cout << "cos(q2) = " << cos_val << std::endl;

            if (fabs(cos_val) > 1.0)
            {
                flg = false;
                std::cout << "cos value is NOT good" << std::endl;
            }
            
            if (tan(deg2rad(-150)) * dP[0] <= dP[1] && dP[1] < tan(deg2rad(150)) * dP[0])
            {
                q_cal[2] = -acos(cos_val);
            }
            else
            {
                q_cal[2] = acos(cos_val);
            }

            if (fabs(q_cal[2] - M_PI) < 0.1 || fabs(q_cal[2] + M_PI) < 0.1)
            {
                flg = false;
                std::cout << "q2 is not good" << std::endl;
            }

            //q1を求めるための計算
            // SinCos = 1 / d * AA * PP
            std::vector<double> SinCos = { 0, 0 };

            double PP[2] = { dP[0] * cos(q_cal[0]) + dP[1] * sin(q_cal[0]) - m_l4 * sin(dq),
                            dP[2] - (m_l4 * cos(dq) + m_l0 + m_l1) };


            double AA[2][2] = { {m_l2 + m_l3 * cos(q_cal[2]),       -m_l3 * sin(q_cal[2])},
                                {       m_l3 * sin(q_cal[2]), m_l2 + m_l3 * cos(q_cal[2])} };


            double d;
            d = AA[0][0] * AA[1][1] - AA[0][1] * AA[1][0];

            for (int i = 0; i < 2; i++)
            {
                SinCos[0] += 1 / d * AA[0][i] * PP[i];
                SinCos[1] += 1 / d * AA[1][i] * PP[i];
            }


            q_cal[1] = atan2(SinCos[0], SinCos[1]);

            //q3 
            q_cal[3] = dq - (q_cal[1] + q_cal[2]);

            //座標軸の設定ミスにより必要
            q_cal[2] = -q_cal[2];
            q_cal[3] = -q_cal[3];
            
            for (int i = 0; i < m_motor_num; i++)
            {
                std::cout << "q " << i << " deg : " << q_cal[i] * 180.0 / M_PI << std::endl;
                
                if (flg == false)
                {
                    std::cout << "break: " << i - 1 << std::endl;
                    break;
                }

                if (flg == true)
                {
                    flg = check_rad_range(&q_cal[i], i);
                }
                
                std::cout << "q" << i << ": " << q_cal[i] << std::endl;
            }            


            if (flg == true)
            {
                //角度の制限つける
                short send_q[5];

                m_motor_deg.data.length(4);

                for (int i = 0; i < m_motor_num; i++)
                {
                    send_q[i] = rad2goalPosition(q_cal[i]);
                    m_motor_deg.data[i] = send_q[i];

                    q_cur_signal[i] = send_q[i];
                    q_cur_rad[i] = (double)((150.0 / 512.0 * send_q[i] - 150.0) * M_PI / 180.0);
                }

                m_motor_degOut.write();
            }

            std::cout << "flg: " << flg << std::endl;

        }
        else if (m_d_position.data[0] == 1)
        {
            //目標位置、目標角度の代入
            dP = { (double)m_d_position.data[1], (double)m_d_position.data[2], (double)m_d_position.data[3] };
            
            if (vector_length(dP) > (m_l0 + m_l1 + m_l2 + m_l3 + m_l4))
            {
                std::cout << "dP is too far!" << std::endl;
                flg = false;
            }

            //q0を求める、dP[1]=dP[0]=0の時はそのまま
            if (dP[1] != 0 || dP[0] != 0)
            {
                if (((tan(deg2rad(-150)) * dP[0]) <= dP[1]) && (dP[1] <= (tan(deg2rad(150)) * dP[0])))
                {
                    q_cal[0] = atan2(dP[1], dP[0]) + M_PI;
                    std::cout << "out of the range" << std::endl;
                    //std::cout << "atan2      = " << atan2(dP[1], dP[0]) << std::endl;
                    //std::cout << "atan2 + pi = " << q_cal[0] << std::endl;
                }
                else
                {
                    q_cal[0] = atan2(dP[1], dP[0]);
                }
            }

            //いろいろ定義
            P0 = L0;
            P1 = vector_sum(L0, L1);
            P3 = dP;

            P13 = vector_dif(P3, P1);
            std::vector<double> L34 = { L3[0] + L4[0],L3[1] + L4[1], L3[2] + L4[2] };

            //q2を求めるための引数を計算
            double cos_val;
            cos_val = vector_length(P13) * vector_length(P13);
            cos_val -= vector_length(L2) * vector_length(L2) + vector_length(L34) * vector_length(L34);
            cos_val /= 2 * vector_length(L2) * vector_length(L34);

            std::cout << "cos(q2) = " << cos_val << std::endl;

            if (fabs(cos_val) > 1.0)
            {
                flg = false;
                std::cout << "cos value is NOT good" << std::endl;
            }

            if (tan(deg2rad(-150)) * dP[0] <= dP[1] && dP[1] < tan(deg2rad(150)) * dP[0])
            {
                q_cal[2] = -acos(cos_val);
            }
            else
            {
                q_cal[2] = acos(cos_val);
            }

            if (fabs(q_cal[2] - M_PI) < 0.1 || fabs(q_cal[2] + M_PI) < 0.1)
            {
                flg = false;
                std::cout << "q2 is not good" << std::endl;
            }

            //q1を求めるための計算
            // SinCos = 1 / d * AA * PP
            std::vector<double> SinCos = { 0, 0 };

            double PP[2] = { dP[0] * cos(q_cal[0]) + dP[1] * sin(q_cal[0]),
                            dP[2] - (m_l0 + m_l1) };


            double AA[2][2] = { {m_l2 + (m_l3 + m_l4) * cos(q_cal[2]),       -(m_l3 + m_l4) * sin(q_cal[2])},
                                {       (m_l3 + m_l4) * sin(q_cal[2]), m_l2 + (m_l3 + m_l4) * cos(q_cal[2])} };


            double d;
            d = AA[0][0] * AA[1][1] - AA[0][1] * AA[1][0];

            for (int i = 0; i < 2; i++)
            {
                SinCos[0] += 1 / d * AA[0][i] * PP[i];
                SinCos[1] += 1 / d * AA[1][i] * PP[i];
            }


            q_cal[1] = atan2(SinCos[0], SinCos[1]);

            //q3 
            q_cal[3] = 0;

            //座標軸の設定ミスにより必要
            q_cal[2] = -q_cal[2];
            q_cal[3] = -q_cal[3];

            for (int i = 0; i < m_motor_num; i++)
            {
                std::cout << "q " << i << " deg : " << q_cal[i] * 180.0 / M_PI << std::endl;

                if (flg == false)
                {
                    std::cout << "break: " << i - 1 << std::endl;
                    break;
                }

                if (flg == true)
                {
                    flg = check_rad_range(&q_cal[i], i);
                }

                std::cout << "q" << i << ": " << q_cal[i] << std::endl;
            }


            if (flg == true)
            {
                short send_q[5];

                m_motor_deg.data.length(4);

                for (int i = 0; i < m_motor_num; i++)
                {
                    send_q[i] = rad2goalPosition(q_cal[i]);
                    m_motor_deg.data[i] = send_q[i];

                    q_cur_signal[i] = send_q[i];
                    q_cur_rad[i] = (double)((150.0 / 512.0 * send_q[i] - 150.0) * M_PI / 180.0);

                }

                m_motor_degOut.write();

                m_hand_axis.data.length(3);
                hand_axis[0] = (double)m_l2 * cos(q_cur_rad[0]) * sin(q_cur_rad[1])
                             + (double)m_l3 * cos(q_cur_rad[0]) * sin(q_cur_rad[1] - q_cur_rad[2])
                             + (double)m_l4 * cos(q_cur_rad[0]) * sin(q_cur_rad[1] - q_cur_rad[2] - q_cur_rad[3]);
                hand_axis[1] = (double)m_l2 * sin(q_cur_rad[0]) * sin(q_cur_rad[1])
                             + (double)m_l3 * sin(q_cur_rad[0]) * sin(q_cur_rad[1] - q_cur_rad[2])
                             + (double)m_l4 * sin(q_cur_rad[0]) * sin(q_cur_rad[1] - q_cur_rad[2] - q_cur_rad[3]);
                hand_axis[2] = (double)m_l0 + (double)m_l1
                             + (double)m_l2 * cos(q_cur_rad[1])
                             + (double)m_l3 * cos(q_cur_rad[1] - q_cur_rad[2])
                             + (double)m_l4 * cos(q_cur_rad[1] - q_cur_rad[2] - q_cur_rad[3]);

                m_hand_axis.data[0] = hand_axis[0];
                m_hand_axis.data[1] = hand_axis[1];
                m_hand_axis.data[2] = hand_axis[2];

                m_hand_axisOut.write();

            }

            std::cout << "flg: " << flg << std::endl;

            std::cout << "hand current position: ";
            for (int i = 0; i < 3; i++)
            {
                std::cout << hand_axis[i] << ", ";
            }
            std::cout << std::endl;
        }
        else if (m_d_position.data[0] == 2)
        {
            double delta_signal = 5.0;
            double dq_3_signal = q_cur_signal[3];

            if (m_d_position.data[1] >= 0)
            {
                dq_3_signal -= delta_signal;
            }
            else
            {
                dq_3_signal += delta_signal;
            }

            if (180 <= dq_3_signal && dq_3_signal <= 850)
            {
                q_cur_signal[3] = dq_3_signal;
                q_cur_rad[3] = (double)((150.0 / 512.0 * q_cur_signal[3] - 150.0) * M_PI / 180.0);
            }

            m_motor_deg.data.length(4);
            m_motor_deg.data[0] = q_cur_signal[0];
            m_motor_deg.data[1] = q_cur_signal[1];
            m_motor_deg.data[2] = q_cur_signal[2];
            m_motor_deg.data[3] = q_cur_signal[3];
            m_motor_degOut.write();


        }
        else
        {
            std::cout << "d_position size is NOT correct! size: " << m_d_position.data.length() << std::endl;
        }


        std::cout << "motor current deg: ";
        for (int i = 0; i < 5; i++)
        {
            std::cout << q_cur_rad[i] * 180.0 / M_PI << ", ";
        }
        std::cout << std::endl;

    }

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t cal_inverse_kinematics::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematics::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematics::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematics::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematics::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void cal_inverse_kinematicsInit(RTC::Manager* manager)
  {
    coil::Properties profile(cal_inverse_kinematics_spec);
    manager->registerFactory(profile,
                             RTC::Create<cal_inverse_kinematics>,
                             RTC::Delete<cal_inverse_kinematics>);
  }
  
}