// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  RealSense_RGBD_Camera.cpp
 * @brief Access to RealSense RGB-D Camera with librealsense2
 *
 */
// </rtc-template>

#include "RealSense_RGBD_Camera.h"
#include <fstream>

#include <chrono>

#include <json.hpp>
using json = nlohmann::json;

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const realsense_rgbd_camera_spec[] =
#else
static const char* realsense_rgbd_camera_spec[] =
#endif
  {
    "implementation_id", "RealSense_RGBD_Camera",
    "type_name",         "RealSense_RGBD_Camera",
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
RealSense_RGBD_Camera::RealSense_RGBD_Camera(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outColorFrameOut("ColorFrame", m_outColorFrame),
    m_outPointCloudOut("PointCloud", m_outPointCloud)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
RealSense_RGBD_Camera::~RealSense_RGBD_Camera()
{
}


/*!
 * Check for librealsense2 availability.
 */
RTC::ReturnCode_t RealSense_RGBD_Camera::onInitialize()
{
  std::cout << "RealSense_RGBD_Camera::onInitialize" << std::endl;

  std::cout << "Using librealsense " << RS2_API_FULL_VERSION_STR << std::endl;

  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("ColorFrame", m_outColorFrameOut);
  addOutPort("PointCloud", m_outPointCloudOut);

  
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
RTC::ReturnCode_t RealSense_RGBD_Camera::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*!
 * Start camera configuration and system IO-related resources.
 */

RTC::ReturnCode_t RealSense_RGBD_Camera::onStartup(RTC::UniqueId /*ec_id*/)
{
    std::cout << std::endl << "RealSense_RGBD_Camera::onStartup" << std::endl;

    rs2_ctx = rs2::context();

    devs = rs2_ctx.query_devices();

    std::cout << "Devices:" << std::endl;

    if (devs.size() > 0)
        for (size_t i = 0; i < devs.size(); i++)
            std::cout << " [" << i + 1 << "]: " << getDeviceInfos(devs[i]) << std::endl;
    else std::cout << "[NO REALSENSE DEVICE FOUND]" << std::endl;

    //TODO: add device selection in OpenRTP

  return RTC::RTC_OK;
}

/*!
 * Release system IO-related resources.
 */

RTC::ReturnCode_t RealSense_RGBD_Camera::onShutdown(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Activate data acquiring.
 */

RTC::ReturnCode_t RealSense_RGBD_Camera::onActivated(RTC::UniqueId /*ec_id*/)
{
    std::cout << std::endl << "RealSense_RGBD_Camera::onActivated" << std::endl;

    rs2_usedDev = devs[0];
    std::cout << "Using device: " << std::string(rs2_usedDev.supports(RS2_CAMERA_INFO_NAME) ? rs2_usedDev.get_info(RS2_CAMERA_INFO_NAME) : "??") << std::endl;

    std::cout << "Starting device..." << std::endl;

    auto& cfg = rs2::config();

    cfg.enable_device(rs2_usedDev.get_info(RS2_CAMERA_INFO_SERIAL_NUMBER));
    //TODO: resolution selection
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);
    //TODO: use other streams
    //cfg.enable_stream(RS2_STREAM_DEPTH, 1920, 1080, RS2_FORMAT_RGB8, 30);

    pipe = rs2::pipeline(rs2_ctx);
    auto& pf = pipe.start(cfg);

    //TODO: device settings
    /*std::cout << "Checking device setting file..." << std::endl;
    rs_SensorSetting(m_rsviewCfgFileStr);*/

    auto& f1 = pipe.wait_for_frames();
    auto& frm = alignColor.process(f1);

    auto& clr_frm = frm.get_color_frame();
    //auto& dpt_frm = frm.get_depth_frame();

    m_outColorFrame.width = clr_frm.get_width();
    m_outColorFrame.height = clr_frm.get_height();
    m_outColorFrame.pixels.length(3 * m_outColorFrame.width * m_outColorFrame.height);

  return RTC::RTC_OK;
}

std::string RealSense_RGBD_Camera::getDeviceInfos(rs2::device& dev) {
    return std::string(dev.supports(RS2_CAMERA_INFO_NAME) ? dev.get_info(RS2_CAMERA_INFO_NAME) : "??")
        + " on " + (dev.supports(RS2_CAMERA_INFO_PHYSICAL_PORT) ? dev.get_info(RS2_CAMERA_INFO_PHYSICAL_PORT) : "??")
        + " (USB " + (dev.supports(RS2_CAMERA_INFO_USB_TYPE_DESCRIPTOR) ? dev.get_info(RS2_CAMERA_INFO_USB_TYPE_DESCRIPTOR) : "??") + ")";
}

bool RealSense_RGBD_Camera::rs_SensorSetting(const std::string& cfgFile) {
    std::ifstream cfgStream(cfgFile);

    if (!cfgStream.good()) return false;

    auto &params = json::parse(cfgStream)["parameters"];

    if (!params.is_array())
        return false;

    for (auto& seten : params.items())
    {
        std::cout << "Setting: " << seten.key() << " = " << seten.value() << std::endl;
    }

    return true;
}

/*!
 * Release periodic resources.
 */

RTC::ReturnCode_t RealSense_RGBD_Camera::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}

/*!
 * Acquire RGB and-or Depth frames.
 */

bool firstexec = true;

std::chrono::steady_clock::time_point sw_start, sw_end;

RTC::ReturnCode_t RealSense_RGBD_Camera::onExecute(RTC::UniqueId /*ec_id*/)
{
    if (firstexec) {
        std::cout << std::endl << "RealSense_RGBD_Camera::onExecute" << std::endl;
        firstexec = false;
    }
    

    sw_start = std::chrono::high_resolution_clock::now();

    auto& f1 = pipe.wait_for_frames();
    auto& frm = alignColor.process(f1);

    auto& clr_frm = frm.get_color_frame();
    //auto& dpt_frm = frm.get_depth_frame();

    //m_outColorFrame.pixels.length(clr_frm.get_data_size());

    // copy to output (direct librealsense)
    //memcpy_s((void*)&(m_outColorFrame.pixels[0]), m_outColorFrame.pixels.length(), clr_frm.get_data(), clr_frm.get_data_size());

    // convert to opencv mat & output
    //clrFrm = cv::Mat(cv::Size(clr_frm.get_width(), clr_frm.get_height()), CV_8UC3, (void*)clr_frm.get_data(), cv::Mat::AUTO_STEP);
    //memcpy_s((void*)&(m_outColorFrame.pixels[0]), m_outColorFrame.pixels.length(), clrFrm.data, clr_frm.get_data_size());

    //m_outColorFrame.tm.nsec = clr_frm.get_timestamp() * 1e6;

    m_outColorFrameOut.write(m_outColorFrame);

    sw_end = std::chrono::high_resolution_clock::now();

    std::cout << "FRAME " << clr_frm.get_width() << "x" << clr_frm.get_height() << " PROCESSED IN " << std::chrono::duration_cast<std::chrono::milliseconds>(sw_end - sw_start).count() << " ms." << std::endl;
    
    //cv::resize(clrFrm, clrFrm, cv::Size(640, 320));
    //cv::imshow("input", clrFrm);

    //cv::waitKey(1);

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t RealSense_RGBD_Camera::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_Camera::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_Camera::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_Camera::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t RealSense_RGBD_Camera::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void RealSense_RGBD_CameraInit(RTC::Manager* manager)
  {
    coil::Properties profile(realsense_rgbd_camera_spec);
    manager->registerFactory(profile,
                             RTC::Create<RealSense_RGBD_Camera>,
                             RTC::Delete<RealSense_RGBD_Camera>);
  }
  
}
