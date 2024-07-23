// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  Master.cpp
 * @brief ModuleDescription
 *
 */
 // </rtc-template>

#include "Master.h"

using namespace std;

//送られてきた信号の番号割り当て
enum signal {
    A,
    B,
    X,
    Y,
    RIGHT,
    LEFT,
    UP,
    DOWN,
    SIGNAL_NUM,
    Arelease,
    Brelease,
    Xrelease,
    Yrelease,
    LB,
    RB
};


// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const master_spec[] =
#else
static const char* master_spec[] =
#endif
{
  "implementation_id", "Master",
  "type_name",         "Master",
  "description",       "ModuleDescription",
  "version",           "1.0.0",
  "vendor",            "VenderName",
  "category",          "Actuator",
  "activity_type",     "PERIODIC",
  "kind",              "DataFlowComponent",
  "max_instance",      "1",
  "language",          "C++",
  "lang_type",         "compile",
  ""
};
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Master::Master(RTC::Manager* manager)
// <rtc-template block="initializer">
    : RTC::DataFlowComponentBase(manager),
    m_GamePad_Arg_SpeedIn("GamePad_Arg_Speed", m_GamePad_Arg_Speed),
    m_nb_of_pinsIn("Nb_of_pins", m_nb_of_pins),
    m_IK_CompIn("IK_Comp", m_IK_Comp),
    m_kobuki_CompIn("kobuki_Comp", m_kobuki_Comp),
    m_SendSpeedOut("SendSpeed", m_SendSpeed),
    m_SendArgOut("SendArg", m_SendArg),
    m_gamepad_CompOut("gamepad_Comp", m_gamepad_Comp)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Master::~Master()
{
}



RTC::ReturnCode_t Master::onInitialize()
{
    // Registration: InPort/OutPort/Service
    // <rtc-template block="registration">
    // Set InPort buffers
    addInPort("GamePad_Arg_Speed", m_GamePad_Arg_SpeedIn);
    addInPort("Nb_of_pins", m_nb_of_pinsIn);
    addInPort("IK_Comp", m_IK_CompIn);
    addInPort("kobuki_Comp", m_kobuki_CompIn);


    // Set OutPort buffer
    addOutPort("SendSpeed", m_SendSpeedOut);
    addOutPort("SendArg", m_SendArgOut);
    addOutPort("gamepad_Comp", m_gamepad_CompOut);


    // Set service provider to Ports

    // Set service consumers to Ports

    // Set CORBA Service Ports

    // </rtc-template>

    // <rtc-template block="bind_config">
    // </rtc-template>

    cout << "Initialize" << endl;
    return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Master::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t Master::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Master::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t Master::onActivated(RTC::UniqueId /*ec_id*/)
{
    motor_id = 1;
    grab_ball_flg = false;
    throw_ball_flg = false;
    cout << "Activate" << endl;
    return RTC::RTC_OK;
}


RTC::ReturnCode_t Master::onDeactivated(RTC::UniqueId /*ec_id*/)
{
    cout << "Deactivate" << endl;
    return RTC::RTC_OK;
}

//onExecuteがループ処理部分だあら，ここに全てを入れる．\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

RTC::ReturnCode_t Master::onExecute(RTC::UniqueId /*ec_id*/)
{

    if (m_GamePad_Arg_SpeedIn.isNew()) {//signalreceive(仮)にデータが来たか確認
        while (!m_GamePad_Arg_SpeedIn.isEmpty()) {//データが空でないときに
            m_GamePad_Arg_SpeedIn.read();//データの読み込み
            short signal; //int,float,short 型の指定
            signal = m_GamePad_Arg_Speed.data[0];//配列でデータを格納,GamePad_Arg_Speedの0番目に0,1,2の数値が入っている．
            cout << "start:" << m_GamePad_Arg_Speed.data[0] << endl; //.exeに「start」が表示され，データが来たことが分かる．
            m_SendSpeed.data.length(2);

            if (signal == A) {
                cout << "A" << endl;
                send_motor_motion_.Positive_Rotation(motor_data, motor_id);
                send_motor_data();

            }
            else if (signal == Arelease) {
                cout << "Arelease" << endl;
                send_motor_motion_.Stop_Motor(motor_data, motor_id);
                send_motor_data();
            }
            else if (signal == B) {
                cout << "B" << endl;
                send_motor_motion_.Negative_Rotation(motor_data, motor_id);
                send_motor_data();
            }
            else if (signal == Brelease) {
                cout << "Brelease" << endl;
                send_motor_motion_.Stop_Motor(motor_data, motor_id);
                send_motor_data();
            }
            else if (signal == X) {
                cout << "X" << endl;
                
                if (!grab_ball_flg)
                {
                    //open hand
                    send_motor_motion_.Open_Hand(motor_data);
                    send_motor_data();

                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                    //move to the position to grab the ball
                    send_motor_motion_.Grab_Ball_Position(motor_data);
                    send_motor_data();

                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

                    //grab the ball
                    send_motor_motion_.Grab_Ball(motor_data);
                    send_motor_data();

                    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                    grab_ball_flg = true;
                }


                send_motor_motion_.Throw_Ball_iniPosition(motor_data);
                send_motor_data();
            }
            else if (signal == Xrelease) {
                cout << "Xrelease" << endl;
                //m_SendArgOut.write();
            }
            else if (signal == Y) {
                cout << "Y" << endl;
                motor_id++;

                if (motor_id >= 5)
                {
                    motor_id = 1;
                }
            }
            else if (signal == Yrelease) {
                cout << "Yrelease" << endl;
                //m_SendArgOut.write();
            }
            else if (signal == LB)
            {
                cout << "LB" << endl;
            }
            else if (signal == RB) {
                cout << "RB" << endl;
                if (!throw_ball_flg)
                {
                    send_motor_motion_.Input_Throw_Position(motor_data);
                    send_motor_data();
                    throw_ball_flg = true;
                }
                else
                {
                    send_motor_motion_.Throw_Ball(motor_data);
                    send_motor_data();

                    grab_ball_flg = false;
                    throw_ball_flg = false;
                    motor_id = 1;
                }
            }
            

            //Kobukiに信号を送る左の十字キー
            else if (signal == LEFT) {
                
                std::cout << "kobuki left" << std::endl;
                m_SendSpeed.data[0] = 0;
                m_SendSpeed.data[1] = 20;
                m_SendSpeedOut.write(m_SendSpeed);
            }
            else if (signal == RIGHT) {
                
                std::cout << "kobuki right" << std::endl;
                m_SendSpeed.data[0] = 0;
                m_SendSpeed.data[1] = -20;
                m_SendSpeedOut.write(m_SendSpeed);
            }
            else if (signal == UP) {
                ;
                std::cout << "kobuki up" << std::endl;
                m_SendSpeed.data[0] = 10;
                m_SendSpeed.data[1] = 0;
                m_SendSpeedOut.write(m_SendSpeed);
            }
            else if (signal == DOWN) {
                
                std::cout << "kobuki down" << std::endl;
                m_SendSpeed.data[0] = -10;
                m_SendSpeed.data[1] = 0;
                m_SendSpeedOut.write(m_SendSpeed);
            }
            else if (signal == SIGNAL_NUM) {

                std::cout << "kobuki stop" << std::endl;
                m_SendSpeed.data[0] = 0;
                m_SendSpeed.data[1] = 0;
                m_SendSpeedOut.write(m_SendSpeed);
            }
            //ここまでがKobukiにデータを送る用


            /*else if (m_sender.data[0] == 1)
            {
                std::string bbb[4] = { "x", "y", "z" };
                for (int i = 1; i < N - 1; i++)
                {
                    std::cout << bbb[i - 1] << ": ";
                    std::cin >> aaa;

                    m_sender.data[i] = (uint16_t)aaa;
                }

                m_sender.data[4] = 0;
            }
            else if (m_sender.data[0] == 2)
            {
                std::cout << "move wrist motor" << std::endl;
                std::cout << "positive rotate : input more than 0" << std::endl;
                std::cout << "negative rotate : input less than 0" << std::endl;

                std::cout << "input: ";
                std::cin >> aaa;

                m_sender.data[1] = (uint16_t)aaa;


                for (int i = 2; i < N; i++)
                {
                    m_sender.data[i] = 0;
                }
            }
            else
            {
                flg = false;
            }

            if (flg)
            {
                m_senderOut.write();
            }


            std::cout << "================================" << std::endl;

            return RTC::RTC_OK;
        }*/


        }

    }
    
#pragma region Number of Pins detected

    if (m_nb_of_pinsIn.isNew()) {
        m_nb_of_pinsIn.read();

        std::cout << "Bowling pins detected: " << m_nb_of_pins.data << std::endl;

        switch (m_nb_of_pins.data) {
            case 0: // 0 pins remaining
                // ACE

                break;
            case 1:
            case 2:
            case 3:
                // When 1-3 pins remaining

                break;
            case 4:
            case 5:
            case 6:
                // When 4-6 pins remaining

                break;
            case 7:
            case 8:
            case 9:
                // When 7-9 pins remaining

                break;
            case 10: // all pins remain (no pin hit)
                // fail
                
                break;

            default:
                // undefined condition, nothing.
                break;
        }
    }

#pragma endregion

    
    return RTC::RTC_OK;

}

void Master::send_motor_data()
{
    m_SendArg.data.length(5);

    for (int i = 0; i < 5; i++)
    {
        m_SendArg.data[i] = motor_data[i]; 
    }

    m_SendArgOut.write(m_SendArg);
}

//RTC::ReturnCode_t Master::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Master::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Master::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Master::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Master::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void MasterInit(RTC::Manager* manager)
  {
    coil::Properties profile(master_spec);
    manager->registerFactory(profile,
                             RTC::Create<Master>,
                             RTC::Delete<Master>);
  }
  
}
