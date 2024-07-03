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

enum signal{
    A,
    B,
    X,
    Y,
    RIGHT,
    LEFT,
    UP,
    DOWN
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
    m_TSSIn("TSS", m_TSS),
    m_TSUIn("TSU", m_TSU),
    m_TV2Out("TV2", m_TV2),
    m_TUSOut("TUS", m_TUS)
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
  addInPort("TSS", m_TSSIn);
  addInPort("TSU", m_TSUIn);
  
  // Set OutPort buffer
  addOutPort("TV2", m_TV2Out);
  addOutPort("TUS", m_TUSOut);

  
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


RTC::ReturnCode_t Master::onExecute(RTC::UniqueId /*ec_id*/)
{

    if (m_TSSIn.isNew()) {//signalreceive(仮)にデータが来たか確認
        while (!m_TSSIn.isEmpty()) {//データが空でないときに
            m_TSSIn.read();//データの読み込み
            short signal;
            signal = m_TSS.data[0];//配列でデータを格納
            cout << "start:" << m_TSS.data[0] << endl;
            if (signal == A) { //Aボタンが押されたら

            }
            else if(signal == RIGHT) {
            }

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
