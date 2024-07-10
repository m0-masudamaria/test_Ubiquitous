﻿// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RealSense_RGBD_CameraTest.cpp
 * @brief Access to RealSense RGB-D Camera with librealsense2 (test code)
 *
 */
// </rtc-template>

#include "RealSense_RGBD_CameraTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const realsense_rgbd_camera_spec[] =
#else
static const char* realsense_rgbd_camera_spec[] =
#endif
  {
    "implementation_id", "RealSense_RGBD_CameraTest",
    "type_name",         "RealSense_RGBD_CameraTest",
    "description",       "Access to RealSense RGB-D Camera with librealsense2",
    "version",           "1.0.0",
    "vendor",            "ha-ves",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "0",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.ColorResolution", "w640h480",
    "conf.default.DepthResolution", "w640h480",
    "conf.default.Alignment", "Color",
    "conf.default.RealSenseViewerCfgFile", "none",

    // Widget
    "conf.__widget__.ColorResolution", "radio",
    "conf.__widget__.DepthResolution", "radio",
    "conf.__widget__.Alignment", "radio",
    "conf.__widget__.RealSenseViewerCfgFile", "text",
    // Constraints
    "conf.__constraints__.ColorResolution", "(w1920h1080, w1280h720, w640h480)",
    "conf.__constraints__.DepthResolution", "(w1920h1080, w1280h720, w640h480)",
    "conf.__constraints__.Alignment", "(Color, Depth)",

    "conf.__type__.ColorResolution", "rs_Resolution",
    "conf.__type__.DepthResolution", "rs_Resolution",
    "conf.__type__.Alignment", "rs_AlignTo",
    "conf.__type__.RealSenseViewerCfgFile", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
RealSense_RGBD_CameraTest::RealSense_RGBD_CameraTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outColorFrameIn("ColorFrame", m_outColorFrame),
    m_outPointCloudIn("PointCloud", m_outPointCloud)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RealSense_RGBD_CameraTest::~RealSense_RGBD_CameraTest()
{
}


/*!
 * Check for librealsense2 availability.
 */
RTC::ReturnCode_t RealSense_RGBD_CameraTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("ColorFrame", m_outColorFrameIn);
  addInPort("PointCloud", m_outPointCloudIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ColorResolution", m_colorResCfg, "w640h480");
  bindParameter("DepthResolution", m_depthResCfg, "w640h480");
  bindParameter("Alignment", m_alignToType, "Color");
  bindParameter("RealSenseViewerCfgFile", m_rsviewCfgFileStr, "none");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t RealSense_RGBD_CameraTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*!
 * Start camera configuration and system IO-related resources.
 */

RTC::ReturnCode_t RealSense_RGBD_CameraTest::onStartup(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Release system IO-related resources.
 */

RTC::ReturnCode_t RealSense_RGBD_CameraTest::onShutdown(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Activate data acquiring.
 */

RTC::ReturnCode_t RealSense_RGBD_CameraTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Release periodic resources.
 */

RTC::ReturnCode_t RealSense_RGBD_CameraTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Acquire RGB and-or Depth frames.
 */

RTC::ReturnCode_t RealSense_RGBD_CameraTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t RealSense_RGBD_CameraTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_CameraTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_CameraTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_CameraTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_CameraTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool RealSense_RGBD_CameraTest::runTest()
{
    return true;
}


extern "C"
{
 
  void RealSense_RGBD_CameraTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(realsense_rgbd_camera_spec);
    manager->registerFactory(profile,
                             RTC::Create<RealSense_RGBD_CameraTest>,
                             RTC::Delete<RealSense_RGBD_CameraTest>);
  }
  
}
