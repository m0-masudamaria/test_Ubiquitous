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

enum signal {
    A,
    B,
    X,
    Y,
    RIGHT,
    LEFT,
    UP,
    DOWN,
    SIGNAL_NUM
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
    m_CameraIn("Camera", m_Camera),
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
    addInPort("Camera", m_CameraIn);
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
            cout << "start:" << m_GamePad_Arg_Speed.data[0] << endl; //.exeにstartが表示され，データが来たことが分かる．
            //if (signal == LEFT) { //LEFTボタンが押されたら
            //    short kobuki_send;
            //    kobuki_send = signal;
            //    m_SendSpeed.data = kobuki_send;
            //    m_SendSpeedOut.write(); //コマンドを次のポートに送る

            //}
            m_SendSpeed.data.length(2);

            if (signal == A) {


                bool flg = true;


                std::cout << "IK of 4 motors" << std::endl;

                short send_arg[5];

                send_arg[0] = 0; //mode
                send_arg[1] = 60; //x
                send_arg[2] = 50; //y
                send_arg[3] = 230; //z
                send_arg[4] = 30; //theta


                std::cout << "complete_arg" << std::endl;

                m_SendArg.data.length(5);

                m_SendArg.data[0] = 0; //send_arg[0];
                m_SendArg.data[1] = 60; //send_arg[1];
                m_SendArg.data[2] = 50;//send_arg[2];
                m_SendArg.data[3] = 230; //send_arg[3];
                m_SendArg.data[4] = 30;//send_arg[4];

                m_SendArgOut.write(m_SendArg);
            }

            
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
    return RTC::RTC_OK;

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
