// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  cal_inverse_kinematicsTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "cal_inverse_kinematicsTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const cal_inverse_kinematics_spec[] =
#else
static const char* cal_inverse_kinematics_spec[] =
#endif
  {
    "implementation_id", "cal_inverse_kinematicsTest",
    "type_name",         "cal_inverse_kinematicsTest",
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
    "conf.default.L0", "50",
    "conf.default.L1", "50",
    "conf.default.L2", "50",
    "conf.default.L3", "50",
    "conf.default.L4", "50",

    // Widget
    "conf.__widget__.L0", "text",
    "conf.__widget__.L1", "text",
    "conf.__widget__.L2", "text",
    "conf.__widget__.L3", "text",
    "conf.__widget__.L4", "text",
    // Constraints

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
cal_inverse_kinematicsTest::cal_inverse_kinematicsTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_d_positionOut("d_position", m_d_position),
    m_motor_degIn("motor_deg", m_motor_deg),
    m_motor_speedIn("motor_speed", m_motor_speed)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
cal_inverse_kinematicsTest::~cal_inverse_kinematicsTest()
{
}



RTC::ReturnCode_t cal_inverse_kinematicsTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("motor_deg", m_motor_degIn);
  addInPort("motor_speed", m_motor_speedIn);
  
  // Set OutPort buffer
  addOutPort("d_position", m_d_positionOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("L0", m_l0, "50");
  bindParameter("L1", m_l1, "50");
  bindParameter("L2", m_l2, "50");
  bindParameter("L3", m_l3, "50");
  bindParameter("L4", m_l4, "50");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t cal_inverse_kinematicsTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t cal_inverse_kinematicsTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t cal_inverse_kinematicsTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t cal_inverse_kinematicsTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t cal_inverse_kinematicsTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool cal_inverse_kinematicsTest::runTest()
{
    return true;
}


extern "C"
{
 
  void cal_inverse_kinematicsTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(cal_inverse_kinematics_spec);
    manager->registerFactory(profile,
                             RTC::Create<cal_inverse_kinematicsTest>,
                             RTC::Delete<cal_inverse_kinematicsTest>);
  }
  
}
