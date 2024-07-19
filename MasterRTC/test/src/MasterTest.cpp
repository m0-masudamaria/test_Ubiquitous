// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  MasterTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "MasterTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const master_spec[] =
#else
static const char* master_spec[] =
#endif
  {
    "implementation_id", "MasterTest",
    "type_name",         "MasterTest",
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
MasterTest::MasterTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_TSSOut("TSS", m_TSS),
    m_TSUOut("TSU", m_TSU),
    m_IK_CompOut("IK_Comp", m_IK_Comp),
    m_kobuki_CompOut("kobuki_Comp", m_kobuki_Comp),
    m_TV2In("TV2", m_TV2),
    m_TUSIn("TUS", m_TUS),
    m_gamepad_CompIn("gamepad_Comp", m_gamepad_Comp)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
MasterTest::~MasterTest()
{
}



RTC::ReturnCode_t MasterTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("TV2", m_TV2In);
  addInPort("TUS", m_TUSIn);
  addInPort("gamepad_Comp", m_gamepad_CompIn);
  
  // Set OutPort buffer
  addOutPort("TSS", m_TSSOut);
  addOutPort("TSU", m_TSUOut);
  addOutPort("IK_Comp", m_IK_CompOut);
  addOutPort("kobuki_Comp", m_kobuki_CompOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MasterTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t MasterTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t MasterTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t MasterTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MasterTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MasterTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t MasterTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t MasterTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t MasterTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t MasterTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t MasterTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool MasterTest::runTest()
{
    return true;
}


extern "C"
{
 
  void MasterTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(master_spec);
    manager->registerFactory(profile,
                             RTC::Create<MasterTest>,
                             RTC::Delete<MasterTest>);
  }
  
}
