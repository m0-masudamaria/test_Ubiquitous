// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  YOLOv8_Detection.h
 * @brief Detect object using YOLOv8 ONNX model
 *
 */
// </rtc-template>

#ifndef YOLOV8_DETECTION_H
#define YOLOV8_DETECTION_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "InterfaceDataTypesStub.h"
#include "BasicDataTypeStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>


#include <onnxruntime_cxx_api.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

struct Detection {
	cv::Rect box;
	float score;
	int class_id;
};

// <rtc-template block="component_description">
/*!
 * @class YOLOv8_Detection
 * @brief Detect object using YOLOv8 ONNX model
 *
 */
// </rtc-template>
class YOLOv8_Detection
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  YOLOv8_Detection(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~YOLOv8_Detection() override;

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  // <rtc-template block="activity">
  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onInitialize() override;

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onFinalize() override;

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id) override;

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id) override;

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id) override;

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id) override;

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onError(RTC::UniqueId ec_id) override;

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onReset(RTC::UniqueId ec_id) override;
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id) override;

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id) override;
  // </rtc-template>


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  onnxFileStr
   * - DefaultValue: none
   */
  std::string m_onnxFileStr;
  /*!
   * 
   * - Name:  cf_thres
   * - DefaultValue: 0.75
   */
  float m_cf_thres;
  /*!
   * 
   * - Name:  iou_thres
   * - DefaultValue: 0.75
   */
  float m_iou_thres;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::CameraImage m_camImage;
  /*!
   */
  RTC::InPort<RTC::CameraImage> m_camImageIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedUShort m_outObjects;
  /*!
   */
  RTC::OutPort<RTC::TimedUShort> m_outObjectsOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>


 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

	 //const OrtApi* ortApi = OrtGetApiBase()->GetApi(ORT_API_VERSION);;

	 //OrtEnv* ortEnv;
	 Ort::Env ortEnvWrap;

	 //OrtSession* inf;
	 Ort::Session infWrap;

	 Ort::MemoryInfo memInfo;

	 std::vector<int64_t> inputDims, outputDims;
	 int64_t inputSize, outputSize;

	 cv::Size in_sz;

	 std::vector<std::string> labels;
	 int64_t channels;

	 Ort::Value in_tensor, out_tensor;
	 std::vector<float> output0_tensor;

	 //cv::dnn::Net model;

	 //void* img_in_buf;
	 cv::Rect pad_roi_rect;
	 cv::Mat img_src;
	 cv::UMat img_src_n, img_in, blob;

  // <rtc-template block="private_operation">
  
  // </rtc-template>

	 //bool YOLOv8_Detection::CheckStatus(const OrtApi*, OrtStatus*);
};


extern "C"
{
  DLL_EXPORT void YOLOv8_DetectionInit(RTC::Manager* manager);
};

#endif // YOLOV8_DETECTION_H
