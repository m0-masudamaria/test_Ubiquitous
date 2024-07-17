﻿// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RealSense_RGBD_CameraTest.h
 * @brief Access to RealSense RGB-D Camera with librealsense2 (test code)
 *
 */
// </rtc-template>

#ifndef REALSENSE_RGBD_CAMERA_TEST__H
#define REALSENSE_RGBD_CAMERA_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class RealSense_RGBD_CameraTest
 * @brief Access to RealSense RGB-D Camera with librealsense2
 *
 */
class RealSense_RGBD_CameraTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  RealSense_RGBD_CameraTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~RealSense_RGBD_CameraTest() override;

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  // <rtc-template block="activity">
  /***
   * Check for librealsense2 availability.
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre librealsense2 binaries are available.
   * @post librealsense2 library is available for use.
   * 
   */
   RTC::ReturnCode_t onInitialize() override;

  /***
   * 
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onFinalize() override;

  /***
   * Start camera configuration and system IO-related resources.
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre RealSense camera is available on the system
   * (connected).
   * @post RealSense camera configuration applied and is
   * available for operation.
   * 
   */
   RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id) override;

  /***
   * Release system IO-related resources.
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre RealSense Camera has stopped operation.
   * @post RealSense Camera connection closed successfully.
   * 
   */
   RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id) override;

  /***
   * Activate data acquiring.
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre RealSense Camera configured.
   * @post RealSense pipeline started and available for dataflow.
   * 
   */
   RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id) override;

  /***
   * Release periodic resources.
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre Dataflow has stopped.
   * @post RealSense Camera pipeline stopped and released it's
   * resources.
   * 
   */
   RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id) override;

  /***
   * Acquire RGB and-or Depth frames.
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * @pre RealSense Camera pipeline is available to fetch frames.
   * @post RGB and-or Depth frames dataflow.
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
  // RTC::ReturnCode_t onReset(RTC::UniqueId ec_id) override;
  
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

  bool runTest();

 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  colorResCfg
   * - DefaultValue: w640h480
   */
  rs_Resolution m_colorResCfg;
  /*!
   * 
   * - Name:  depthResCfg
   * - DefaultValue: w640h480
   */
  rs_Resolution m_depthResCfg;
  /*!
   * 
   * - Name:  alignToType
   * - DefaultValue: Color
   */
  rs_AlignTo m_alignToType;
  /*!
   * 
   * - Name:  rsviewCfgFileStr
   * - DefaultValue: none
   */
  std::string m_rsviewCfgFileStr;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::CameraImage m_outColorFrame;
  /*!
   */
  RTC::InPort<RTC::CameraImage> m_outColorFrameIn;
  RTC::PointCloud m_outPointCloud;
  /*!
   */
  RTC::InPort<RTC::PointCloud> m_outPointCloudIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
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

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void RealSense_RGBD_CameraTestInit(RTC::Manager* manager);
};

#endif // REALSENSE_RGBD_CAMERA_TEST_H