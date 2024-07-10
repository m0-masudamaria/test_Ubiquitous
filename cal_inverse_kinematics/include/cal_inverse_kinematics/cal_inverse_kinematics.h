// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  cal_inverse_kinematics.h
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#ifndef CAL_INVERSE_KINEMATICS_H
#define CAL_INVERSE_KINEMATICS_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "BasicDataTypeStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

// <rtc-template block="component_description">
/*!
 * @class cal_inverse_kinematics
 * @brief ModuleDescription
 *
 */
// </rtc-template>
class cal_inverse_kinematics
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  cal_inverse_kinematics(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~cal_inverse_kinematics() override;

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
  // RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id) override;

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


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   *
   * - Name:  motor_num
   * - DefaultValue: 4
   */
	 double m_motor_num;  /*!
   * 
   * - Name:  l0
   * - DefaultValue: 50
   */
  double m_l0;
  /*!
   * 
   * - Name:  l1
   * - DefaultValue: 50
   */
  double m_l1;
  /*!
   * 
   * - Name:  l2
   * - DefaultValue: 50
   */
  double m_l2;
  /*!
   * 
   * - Name:  l3
   * - DefaultValue: 50
   */
  double m_l3;
  /*!
   * 
   * - Name:  l4
   * - DefaultValue: 50
   */
  double m_l4;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedShortSeq m_d_position;
  /*!
   * 目標位置のx,y,z座標、目標姿勢、boolを配列で受け取る
   */
  RTC::InPort<RTC::TimedShortSeq> m_d_positionIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedUShortSeq m_motor_deg;
  /*!
   */
  RTC::OutPort<RTC::TimedUShortSeq> m_motor_degOut;
  RTC::TimedUShortSeq m_motor_speed;
  /*!
   */
  RTC::OutPort<RTC::TimedUShortSeq> m_motor_speedOut;
  
  RTC::TimedShortSeq m_hand_axis;
  /*!
   */
  RTC::OutPort<RTC::TimedShortSeq> m_hand_axisOut;

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

	 bool flg;

	 int q_cur_signal[5];
	 double q_cur_rad[5];
	 double hand_axis[3];

	 std::vector<double> L0;
	 std::vector<double> L1;
	 std::vector<double> L2;
	 std::vector<double> L3;
	 std::vector<double> L4;

	 double dq;

	 double q_cal[5];
	 //double q0;
	 //double q1;
	 //double q2;
	 //double q3;
	 //double q4;

	 

	 std::vector<double> dP;

	 std::vector<double> L4_cur_vec;
	 std::vector<double> P0;
	 std::vector<double> P1;
	 std::vector<double> P3;
	 std::vector<double> P4;
	 std::vector<double> P13;

};


extern "C"
{
  DLL_EXPORT void cal_inverse_kinematicsInit(RTC::Manager* manager);
};

#endif // CAL_INVERSE_KINEMATICS_H
