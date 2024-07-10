// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  FloatSeqToVelocityTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "FloatSeqToVelocityTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const floatseqtovelocity_spec[] =
#else
static const char* floatseqtovelocity_spec[] =
#endif
  {
    "implementation_id", "FloatSeqToVelocityTest",
    "type_name",         "FloatSeqToVelocityTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Masuda",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.rotation_by_position", "-0.02",
    "conf.default.velocity_by_position", "0.002",

    // Widget
    "conf.__widget__.rotation_by_position", "text",
    "conf.__widget__.velocity_by_position", "text",
    // Constraints

    "conf.__type__.rotation_by_position", "double",
    "conf.__type__.velocity_by_position", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
FloatSeqToVelocityTest::FloatSeqToVelocityTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inOut("in", m_in),
    m_outIn("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
FloatSeqToVelocityTest::~FloatSeqToVelocityTest()
{
}



RTC::ReturnCode_t FloatSeqToVelocityTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("out", m_outIn);
  
  // Set OutPort buffer
  addOutPort("in", m_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("rotation_by_position", m_rotation_by_position, "-0.02");
  bindParameter("velocity_by_position", m_velocity_by_position, "0.002");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t FloatSeqToVelocityTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t FloatSeqToVelocityTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t FloatSeqToVelocityTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t FloatSeqToVelocityTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t FloatSeqToVelocityTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t FloatSeqToVelocityTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool FloatSeqToVelocityTest::runTest()
{
    return true;
}


extern "C"
{
 
  void FloatSeqToVelocityTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(floatseqtovelocity_spec);
    manager->registerFactory(profile,
                             RTC::Create<FloatSeqToVelocityTest>,
                             RTC::Delete<FloatSeqToVelocityTest>);
  }
  
}
