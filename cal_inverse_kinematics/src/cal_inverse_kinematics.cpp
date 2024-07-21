// -*- C++ -*-
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
#include "basic_function.h"
#include "cal_4motor_ik.h"
#include "operate_motor.h"

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
    "conf.default.motor_num", "5",
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
  bindParameter("motor_num", m_motor_num, "5");
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
    flg_motor = false;

    link_length[0] = m_l0;
    link_length[1] = m_l1;
    link_length[2] = m_l2;
    link_length[3] = m_l3;
    link_length[4] = m_l4;

    check_data_length = 5;

    //L0 = { 0, 0, m_l0 };
    //L1 = { 0, 0, m_l1 };
    //L2 = { 0, 0, m_l2 };
    //L3 = { 0, 0, m_l3 };
    //L4 = { 0, 0, m_l4 };

    for (int i = 0; i < m_motor_num; i++)
    {
        q_rad_cal[i] = 0.0;
    }

    for (int i = 0; i < m_motor_num; i++)
    {
        q_cur_signal[i] = 512;
        q_cur_rad[i] = (double)0.0;
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
        flg_motor = false;
        bool length_flag = false;

        //m_motor_speed.data.length(5);
        //m_motor_speed.data[0] = 100;
        //m_motor_speed.data[1] = 100;
        //m_motor_speed.data[2] = 100;
        //m_motor_speed.data[3] = 100;
        //m_motor_speed.data[4] = 100;
        //m_motor_speedOut.write();

        //必要な配列長であるか判断
        if (m_d_position.data.length() == check_data_length)
        {
            length_flag = true;

            for (int i = 0; i < check_data_length; i++)
            {
                data[i] = (int)m_d_position.data[i];
            }
        }

        if (m_d_position.data[0] == 0)
        {

            cal_4_motor_IK_.cal_IK(q_rad_cal, data, link_length, &flg);
            

            ////座標軸の設定ミスにより必要
            //q_rad_cal[2] = -q_rad_cal[2];
            //q_rad_cal[3] = -q_rad_cal[3];
            //
            //for (int i = 0; i < m_motor_num; i++)
            //{
            //    std::cout << "q " << i << " deg : " << q_rad_cal[i] * 180.0 / M_PI << std::endl;
            //    
            //    if (flg == false)
            //    {
            //        std::cout << "break: " << i - 1 << std::endl;
            //        break;
            //    }

            //    if (flg == true)
            //    {
            //        flg = check_rad_range(&q_rad_cal[i], i);
            //    }
            //    
            //    std::cout << "q" << i << ": " << q_rad_cal[i] << std::endl;
            //}            


            //if (flg == true)
            //{
            //    //角度の制限つける
            //    short send_q[5];

            //    m_motor_deg.data.length(4);

            //    for (int i = 0; i < m_motor_num; i++)
            //    {
            //        send_q[i] = rad2goalPosition(q_rad_cal[i]);
            //        m_motor_deg.data[i] = send_q[i];

            //        q_cur_signal[i] = send_q[i];
            //        q_cur_rad[i] = (double)((150.0 / 512.0 * send_q[i] - 150.0) * M_PI / 180.0);
            //    }

            //    m_motor_degOut.write();
            //}

            //std::cout << "flg: " << flg << std::endl;

        }
        else if (m_d_position.data[0] == 1)
        {
            cal_3_motor_IK_.cal_IK(q_rad_cal, data, link_length, &flg);

            /*
            //座標軸の設定ミスにより必要
            q_rad_cal[2] = -q_rad_cal[2];
            q_rad_cal[3] = -q_rad_cal[3];

            for (int i = 0; i < m_motor_num; i++)
            {
                std::cout << "q " << i << " deg : " << q_rad_cal[i] * 180.0 / M_PI << std::endl;

                if (flg == false)
                {
                    std::cout << "break: " << i - 1 << std::endl;
                    break;
                }

                if (flg == true)
                {
                    flg = check_rad_range(&q_rad_cal[i], i);
                }

                std::cout << "q" << i << ": " << q_rad_cal[i] << std::endl;
            }


            if (flg == true)
            {
                short send_q[5];

                m_motor_deg.data.length(4);

                for (int i = 0; i < m_motor_num; i++)
                {
                    send_q[i] = rad2goalPosition(q_rad_cal[i]);
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
            */
            
        }
        /*
        else if (m_d_position.data[0] == 2)
        {
            //手首のモータだけ少し動かす
            double delta_signal = 5.0;
            double dq_3_signal = (double)q_cur_signal[3];

            if (m_d_position.data[1] == 0)
            {
                dq_3_signal -= delta_signal;
            }
            else if(m_d_position.data[1] == 1)
            {
                dq_3_signal += delta_signal;
            }
            else
            {
                flg = false;
            }

            if(flg)
            {

                if (180 <= dq_3_signal && dq_3_signal <= 850)
                {
                    q_cur_signal[3] = (int)dq_3_signal;
                    q_cur_rad[3] = (double)((150.0 / 512.0 * q_cur_signal[3] - 150.0) * M_PI / 180.0);
                }

                m_motor_deg.data.length(4);
                m_motor_deg.data[0] = q_cur_signal[0];
                m_motor_deg.data[1] = q_cur_signal[1];
                m_motor_deg.data[2] = q_cur_signal[2];
                m_motor_deg.data[3] = q_cur_signal[3];
                m_motor_degOut.write();
            }


        }
        */
        else if (m_d_position.data[0] == 2)
        {
            if (data[2] == 0 || data[2] == 1)
            {
                flg_motor = true;
                std::cout << "motor flg is true" << std::endl;
            }

            change_motor_speed(100);

            operate_motor_.operate_single_motor(q_cur_rad, q_rad_cal, data, &flg);
            /*for (int i = 0; i < 5; i++)
            {
                std::cout << "motor" << i << ": " << q_cur_rad[i] << std::endl;
            }*/
            

            /*
            if(flg)
            {                
                double dq_rad = (double)((150.0 / 512.0 * dq_signal - 150.0) * M_PI / 180.0);

                b_f_.check_rad_range(&dq_rad, motor_id);

                q_cur_rad[motor_id] = dq_rad;
                q_cur_signal[motor_id] = (int)((dq_rad * 180.0 / M_PI + 150.0) * 512.0 / 150.0);

                m_motor_deg.data.length(4);
                m_motor_deg.data[0] = q_cur_signal[0];
                m_motor_deg.data[1] = q_cur_signal[1];
                m_motor_deg.data[2] = q_cur_signal[2];
                m_motor_deg.data[3] = q_cur_signal[3];
                m_motor_degOut.write();
            }
            */

            /*std::cout << "after" << std::endl;
            for (int i = 0; i < 5; i++)
            {
                std::cout << "motor" << i << ": " << q_cur_rad[i] << std::endl;
            }*/


        }
        else if (m_d_position.data[0] == 3)
        {
            q_rad_cal[0] = 0.0;
            q_rad_cal[1] = 30.0 * M_PI / 180.0;
            q_rad_cal[2] = 90.0 * M_PI / 180.0;
            q_rad_cal[3] = 0.0;
            q_rad_cal[4] = q_cur_rad[4];
        }
        else if (m_d_position.data[0] == 4)
        {

            if (m_d_position.data[1] == 0)
            {
                //initial position
                q_rad_cal[0] = q_cur_rad[0];
                q_rad_cal[1] = q_cur_rad[1];
                q_rad_cal[2] = -q_cur_rad[2];
                q_rad_cal[3] = -q_cur_rad[3];
                q_rad_cal[4] = q_cur_rad[4];
            }
            else if(m_d_position.data[1] == 1)
            {
                //grab
                q_rad_cal[0] = q_cur_rad[0];
                q_rad_cal[1] = q_cur_rad[1];
                q_rad_cal[2] = -q_cur_rad[2];
                q_rad_cal[3] = -q_cur_rad[3];
                q_rad_cal[4] = 7.0 * M_PI / 180.0;
            }
            else if (m_d_position.data[1] == 2)
            {
                //open hand
                q_rad_cal[0] = q_cur_rad[0];
                q_rad_cal[1] = q_cur_rad[1];
                q_rad_cal[2] = -q_cur_rad[2];
                q_rad_cal[3] = -q_cur_rad[3];
                q_rad_cal[4] = -30.0 * M_PI / 180.0;
            }
        }
        else if (m_d_position.data[0] == 5)
        {
            if (m_d_position.data[1] == 0)
            {
                std::cout << "input release position" << std::endl;
                //input release point
                q_release_point[0] = q_cur_rad[0];
                q_release_point[1] = q_cur_rad[1];
                q_release_point[2] = q_cur_rad[2];
                q_release_point[3] = q_cur_rad[3];
                q_release_point[4] = q_cur_rad[4];

                operate_motor_.Ready_for_Throw(q_cur_rad, q_rad_cal);
            }
            else if (m_d_position.data[1] == 1)
            {
                change_motor_speed(1023);

                std::cout << "throwwwwwwwwww" << std::endl;
                operate_motor_.Throw_Ball_Motion(q_rad_cal, q_release_point);
                send_data();

                std::this_thread::sleep_for(std::chrono::milliseconds(10));

                operate_motor_.Rerelase_Ball(q_rad_cal, q_release_point);
                send_data();

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                flg = false;

                change_motor_speed(100);
            }
        }
        else
        {
            std::cout << "d_position size is NOT correct! size: " << m_d_position.data.length() << std::endl;
        }

        send_data();
    }

   

    if (flg_motor)
    {
        operate_motor_.operate_single_motor(q_cur_rad, q_rad_cal, data, &flg);

        send_data();
        /*
        //座標軸の設定ミスにより必要
        q_rad_cal[2] = -q_rad_cal[2];
        q_rad_cal[3] = -q_rad_cal[3];

        for (int i = 0; i < m_motor_num; i++)
        {
            std::cout << "q " << i << " deg : " << q_rad_cal[i] * 180.0 / M_PI << std::endl;

            if (flg == false)
            {
                std::cout << "break: " << i - 1 << std::endl;
                break;
            }

            if (flg == true)
            {
                flg = basic_f_.check_rad_range(&q_rad_cal[i], i);
            }

            std::cout << "q" << i << ": " << q_rad_cal[i] << std::endl;
        }

        if (flg == true)
        {
            //角度の制限つける
            short send_q[5];

            m_motor_deg.data.length(m_motor_num);

            for (int i = 0; i < m_motor_num; i++)
            {
                send_q[i] = basic_f_.rad2goalPosition(q_rad_cal[i]);
                m_motor_deg.data[i] = send_q[i];

                q_cur_signal[i] = send_q[i];
                q_cur_rad[i] = q_rad_cal[i];
                //q_cur_rad[i] = (double)((150.0 / 512.0 * send_q[i] - 150.0) * M_PI / 180.0);
            }

            m_motor_degOut.write();
        }

        std::cout << "flg: " << flg << std::endl;

        std::cout << "motor current deg: ";
        for (int i = 0; i < m_motor_num; i++)
        {
            std::cout << q_cur_rad[i] * 180.0 / M_PI << ", ";
        }
        std::cout << std::endl;
        */
    }
   
    
  return RTC::RTC_OK;
}

void cal_inverse_kinematics::send_data()
{
    //座標軸の設定ミスにより必要
    q_rad_cal[2] = -q_rad_cal[2];
    q_rad_cal[3] = -q_rad_cal[3];

    for (int i = 0; i < m_motor_num; i++)
    {
        std::cout << "q " << i << " deg : " << q_rad_cal[i] * 180.0 / M_PI << std::endl;

        if (flg == false)
        {
            std::cout << "break: " << i - 1 << std::endl;
            break;
        }

        if (flg == true)
        {
            flg = basic_f_.check_rad_range(&q_rad_cal[i], i);
        }

        std::cout << "q" << i << ": " << q_rad_cal[i] << std::endl;
    }

    if (flg == true)
    {
        //角度の制限つける
        short send_q[5];

        m_motor_deg.data.length(m_motor_num);

        for (int i = 0; i < m_motor_num; i++)
        {
            send_q[i] = basic_f_.rad2goalPosition(q_rad_cal[i]);
            m_motor_deg.data[i] = send_q[i];

            q_cur_signal[i] = send_q[i];
            q_cur_rad[i] = q_rad_cal[i];
            //q_cur_rad[i] = (double)((150.0 / 512.0 * send_q[i] - 150.0) * M_PI / 180.0);
        }

        m_motor_degOut.write();
    }

    std::cout << "flg: " << flg << std::endl;

    std::cout << "motor current deg: ";
    for (int i = 0; i < m_motor_num; i++)
    {
        std::cout << q_cur_rad[i] * 180.0 / M_PI << ", ";
    }
    std::cout << std::endl;
}

void cal_inverse_kinematics::change_motor_speed(uint16_t speed)
{
    m_motor_speed.data.length(5);
    m_motor_speed.data[0] = speed;
    m_motor_speed.data[1] = speed;
    m_motor_speed.data[2] = speed;
    m_motor_speed.data[3] = speed;
    m_motor_speed.data[4] = speed;
    m_motor_speedOut.write();
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
