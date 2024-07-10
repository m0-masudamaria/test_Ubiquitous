// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  sender.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include <iostream>
#include <string>
#include <vector>
#include "sender.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const sender_spec[] =
#else
static const char* sender_spec[] =
#endif
  {
    "implementation_id", "sender",
    "type_name",         "sender",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
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
sender::sender(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_senderOut("sender", m_sender)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sender::~sender()
{
}



RTC::ReturnCode_t sender::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("sender", m_senderOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sender::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t sender::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t sender::onExecute(RTC::UniqueId /*ec_id*/)
{
    int N = 5;
    //std::cout << "num:";
    //std::cin >> N;
    //std::cout << std::endl;

    m_sender.data.length(N);

    //for (int i = 0; i < N; i++)
    //{
    //    uint16_t aaa;
    //    std::cout << "data" << i << ": ";
    //    std::cin >> (uint16_t)aaa;

    //    m_sender.data[i] = aaa;
    //}

    bool flg = true;

    float aaa;
    std::cout << "0 : IK of 4 motors , 1 : IK of 3 motors , 2 : move wrist motor" << std::endl;
    std::cout << "select mode" << ": ";
    std::cin >> aaa;
    m_sender.data[0] = (uint16_t)aaa;

    if (m_sender.data[0] == 0)
    {
        std::string bbb[4] = { "x", "y", "z", "theta" };
        for (int i = 1; i < N; i++)
        {
            std::cout << bbb[i - 1] << ": ";
            std::cin >> aaa;

            m_sender.data[i] = (uint16_t)aaa;
        }
    }
    else if (m_sender.data[0] == 1)
    {
        std::string bbb[4] = { "x", "y", "z" };
        for (int i = 1; i < N - 1; i++)
        {
            std::cout << bbb[i - 1] << ": ";
            std::cin >> aaa;

            m_sender.data[i] = (uint16_t)aaa;
        }

        m_sender.data[4] = 0;
    }
    else if (m_sender.data[0] == 2)
    {
        std::cout << "move wrist motor" << std::endl;
        std::cout << "positive rotate : input more than 0" << std::endl;
        std::cout << "negative rotate : input less than 0" << std::endl;

        std::cout << "input: ";
        std::cin >> aaa;

        m_sender.data[1] = (uint16_t)aaa;


        for (int i = 2; i < N; i++)
        {
            m_sender.data[i] = 0;
        }
    }
    else
    {
        flg = false;
    }

    if (flg)
    {
        m_senderOut.write();
    }


    std::cout << "================================" << std::endl;

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t sender::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t sender::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void senderInit(RTC::Manager* manager)
  {
    coil::Properties profile(sender_spec);
    manager->registerFactory(profile,
                             RTC::Create<sender>,
                             RTC::Delete<sender>);
  }
  
}
