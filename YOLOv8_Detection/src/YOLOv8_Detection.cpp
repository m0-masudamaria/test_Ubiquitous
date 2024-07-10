// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  YOLOv8_Detection.cpp
 * @brief Detect object using YOLOv8 ONNX model
 *
 */
// </rtc-template>

#include "YOLOv8_Detection.h"
#include <opencv2/opencv.hpp>

#include <onnxruntime/core/session/onnxruntime_cxx_api.h>

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const yolov8_detection_spec[] =
#else
static const char* yolov8_detection_spec[] =
#endif
  {
    "implementation_id", "YOLOv8_Detection",
    "type_name",         "YOLOv8_Detection",
    "description",       "Detect object using YOLOv8 ONNX model",
    "version",           "1.0.0",
    "vendor",            "ha-ves",
    "category",          "ImageProcessiong",
    "activity_type",     "SPORADIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "0",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.ONNX_File", "none",

    // Widget
    "conf.__widget__.ONNX_File", "text",
    // Constraints

    "conf.__type__.ONNX_File", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
YOLOv8_Detection::YOLOv8_Detection(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_camImageIn("in_image", m_camImage),
    m_outObjectsOut("out_objects", m_outObjects)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
YOLOv8_Detection::~YOLOv8_Detection()
{
}



RTC::ReturnCode_t YOLOv8_Detection::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in_image", m_camImageIn);
  
  // Set OutPort buffer
  addOutPort("out_objects", m_outObjectsOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ONNX_File", m_onnxFileStr, "none");
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t YOLOv8_Detection::onFinalize()
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t YOLOv8_Detection::onStartup(RTC::UniqueId /*ec_id*/)
{


  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_Detection::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t YOLOv8_Detection::onActivated(RTC::UniqueId /*ec_id*/)
{
    std::cout << "YOLOv8_Detection::onActivated" << std::endl;

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_Detection::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t YOLOv8_Detection::onExecute(RTC::UniqueId /*ec_id*/)
{
    cv2::GpuMat

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_Detection::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_Detection::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_Detection::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_Detection::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_Detection::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void YOLOv8_DetectionInit(RTC::Manager* manager)
  {
    coil::Properties profile(yolov8_detection_spec);
    manager->registerFactory(profile,
                             RTC::Create<YOLOv8_Detection>,
                             RTC::Delete<YOLOv8_Detection>);
  }
  
}
