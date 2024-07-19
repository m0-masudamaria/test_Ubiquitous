// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  YOLOv8_DetectionTest.cpp
 * @brief Detect object using YOLOv8 ONNX model (test code)
 *
 */
// </rtc-template>

#include "YOLOv8_DetectionTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const yolov8_detection_spec[] =
#else
static const char* yolov8_detection_spec[] =
#endif
  {
    "implementation_id", "YOLOv8_DetectionTest",
    "type_name",         "YOLOv8_DetectionTest",
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
    "conf.default.Confidence_Threshold", "0.75",
    "conf.default.Overlap_IoU_Threshold", "0.75",

    // Widget
    "conf.__widget__.ONNX_File", "text",
    "conf.__widget__.Confidence_Threshold", "slider.0.01",
    "conf.__widget__.Overlap_IoU_Threshold", "slider.0.01",
    // Constraints
    "conf.__constraints__.Confidence_Threshold", "0.01<=x<=1.0",
    "conf.__constraints__.Overlap_IoU_Threshold", "0.01<=x<=1.0",

    "conf.__type__.ONNX_File", "string",
    "conf.__type__.Confidence_Threshold", "float",
    "conf.__type__.Overlap_IoU_Threshold", "float",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
YOLOv8_DetectionTest::YOLOv8_DetectionTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_camImageOut("in_image", m_camImage),
    m_outObjectsIn("out_objects", m_outObjects)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
YOLOv8_DetectionTest::~YOLOv8_DetectionTest()
{
}



RTC::ReturnCode_t YOLOv8_DetectionTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("out_objects", m_outObjectsIn);
  
  // Set OutPort buffer
  addOutPort("in_image", m_camImageOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ONNX_File", m_onnxFileStr, "none");
  bindParameter("Confidence_Threshold", m_cf_thres, "0.75");
  bindParameter("Overlap_IoU_Threshold", m_iou_thres, "0.75");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t YOLOv8_DetectionTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t YOLOv8_DetectionTest::onStartup(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t YOLOv8_DetectionTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t YOLOv8_DetectionTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t YOLOv8_DetectionTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool YOLOv8_DetectionTest::runTest()
{
    return true;
}


extern "C"
{
 
  void YOLOv8_DetectionTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(yolov8_detection_spec);
    manager->registerFactory(profile,
                             RTC::Create<YOLOv8_DetectionTest>,
                             RTC::Delete<YOLOv8_DetectionTest>);
  }
  
}
