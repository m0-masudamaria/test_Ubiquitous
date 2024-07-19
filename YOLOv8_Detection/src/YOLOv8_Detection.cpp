// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  YOLOv8_Detection.cpp
 * @brief Detect object using YOLOv8 ONNX model
 *
 */
// </rtc-template>

#include "YOLOv8_Detection.h"

#include <numeric>
#include <functional>

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
YOLOv8_Detection::YOLOv8_Detection(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_camImageIn("in_image", m_camImage),
    m_outObjectsOut("out_objects", m_outObjects)
    // </rtc-template>
    , ortEnvWrap(ORT_LOGGING_LEVEL_VERBOSE, "YOLOv8_Detection_RTComponent")
    , infWrap(nullptr)
    , memInfo(nullptr)
    , in_tensor(nullptr)
    , out_tensor(nullptr)
    //, img_src(cv::USAGE_ALLOCATE_DEVICE_MEMORY)
    //, img_in(cv::USAGE_ALLOCATE_DEVICE_MEMORY)
    //, blob(cv::USAGE_ALLOCATE_DEVICE_MEMORY)
{
    //CheckStatus(ortApi, ortApi->CreateEnv(ORT_LOGGING_LEVEL_VERBOSE, "YOLOv8_Detection_RTComponent", &ortEnv));
}

//bool YOLOv8_Detection::CheckStatus(const OrtApi* g_ort, OrtStatus* status) {
//    if (status != nullptr) {
//        const char* msg = g_ort->GetErrorMessage(status);
//        std::cerr << msg << std::endl;
//        g_ort->ReleaseStatus(status);
//        throw Ort::Exception(msg, OrtErrorCode::ORT_EP_FAIL);
//    }
//    return true;
//}

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
  bindParameter("Confidence_Threshold", m_cf_thres, "0.75");
  bindParameter("Overlap_IoU_Threshold", m_iou_thres, "0.75");
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
    std::cout << "YOLOv8_Detection::onStartup" << std::endl;

    std::cout << "Using ONNX " << Ort::GetVersionString() << std::endl
        << "Available providers: ";
    for (auto& prov : Ort::GetAvailableProviders()) std::cout << "[" << prov << "] ";
    std::cout << std::endl;

    if (cv::ocl::haveOpenCL()) {
        std::cout << "Using OpenCV" << cv::getVersionString() << " (OpenCL-capable)" << std::endl;

        cv::ocl::useOpenCL();
        cv::ocl::setUseOpenCL(true);

        // Get information about the OpenCL device
        cv::ocl::Context context;
        if (context.create(cv::ocl::Device::TYPE_ALL)) {
            std::vector<cv::ocl::PlatformInfo> platforms;
            cv::ocl::getPlatfomsInfo(platforms);

            for (const auto& platform : platforms) {
                std::cout << "Platform Name: " << platform.name() << std::endl;

                for (int i = 0; i < platform.deviceNumber(); i++) {
                    cv::ocl::Device device;
                    platform.getDevice(device, i);

                    std::cout << "Device Name: " << device.name() << std::endl;
                    std::cout << "Vendor: " << device.vendorName() << std::endl;
                    std::cout << "Version: " << device.version() << std::endl;
                    std::cout << "Max Compute Units: " << device.maxComputeUnits() << std::endl;
                    std::cout << "Global Memory Size: " << device.globalMemSize() << " bytes" << std::endl;
                    std::cout << "Max Clock Frequency: " << device.maxClockFrequency() << " MHz" << std::endl;
                }
            }
        }
    }
    else std::cout << "Using OpenCV" << cv::getVersionString() << std::endl;


    /*OrtSessionOptions* opt;

    CheckStatus(ortApi, ortApi->CreateSessionOptions(&opt));
    CheckStatus(ortApi, ortApi->SetIntraOpNumThreads(opt, 1));
    CheckStatus(ortApi, ortApi->SetSessionGraphOptimizationLevel(opt, ORT_ENABLE_BASIC));

    CheckStatus(ortApi, ortApi->CreateSession(ortEnv, L"C:/Users/HaveS/workspace/test_Ubiquitous/YOLOv8_Detection/best_full.onnx", opt, &inf));*/

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t YOLOv8_Detection::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t YOLOv8_Detection::onActivated(RTC::UniqueId /*ec_id*/)
{
    std::cout << "YOLOv8_Detection::onActivated" << std::endl;

    //auto& envOpt = Ort::ThreadingOptions();
    //envOpt.SetGlobalInterOpNumThreads(1);
    //envOpt.SetGlobalIntraOpNumThreads(1);

    //ortEnv = Ort::Env(envOpt, ORT_LOGGING_LEVEL_VERBOSE, "YOLOv8_Detection_RTComponent");

    auto& sessopt = Ort::SessionOptions();
    //sessopt.AppendExecutionProvider_CUDA();
    sessopt.SetLogSeverityLevel(ORT_LOGGING_LEVEL_VERBOSE);
    sessopt.SetIntraOpNumThreads(1);
    //sessopt.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_BASIC);

    infWrap = Ort::Session(ortEnvWrap, std::wstring(m_onnxFileStr.begin(), m_onnxFileStr.end()).c_str(), sessopt);

    //model = cv::dnn::readNetFromONNX(m_onnxFileStr);

    /*std::cout << "PRELOADED model:" << std::endl
        << model.;*/

    inputDims = infWrap.GetInputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
    inputSize = std::accumulate(inputDims.begin(), inputDims.end(), 1.0, std::multiplies<int64_t>());

    outputDims = infWrap.GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
    outputSize = std::accumulate(outputDims.begin(), outputDims.end(), 1.0, std::multiplies<int64_t>());

    in_sz = cv::Size(inputDims[3], inputDims[2]);
    channels = outputDims[2];
    labels = std::vector<std::string>({ "ball", "pin", "board" });

    memInfo = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);

    output0_tensor = std::vector<float>(outputSize);

    out_tensor = Ort::Value::CreateTensor<float>(memInfo, output0_tensor.data(), outputSize, outputDims.data(), outputDims.size());

    img_in = cv::UMat(in_sz, CV_8UC3, cv::USAGE_ALLOCATE_DEVICE_MEMORY) = (0, 0, 0);

  return RTC::RTC_OK;
}

int in_w, in_h;
float scale;

RTC::ReturnCode_t YOLOv8_Detection::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t YOLOv8_Detection::onExecute(RTC::UniqueId /*ec_id*/)
{
    //cv::imread("C:/Users/HaveS/Downloads/61SChd1wwtL.jpg", img_src);

    if (m_camImageIn.isNew()) {
        m_camImageIn.read();

        auto& tim = std::chrono::high_resolution_clock::now();
        auto& tim_one = tim;

        if (in_w != m_camImage.width || in_h != m_camImage.height)
        {
            //img_in_buf = m_camImage.pixels.get_buffer();

            img_src = cv::Mat(m_camImage.height, m_camImage.width, CV_8UC3, m_camImage.pixels.get_buffer());

            in_w = m_camImage.width; in_h = m_camImage.height;
            
            // height pad
            if ((float)img_src.rows / img_src.cols < 1.0f)
            {
                scale = (float)in_sz.width / img_src.cols;

                auto it = scale * img_src.rows;

                pad_roi_rect = cv::Rect(cv::Point(0, (in_sz.width - scale * img_src.rows) / 2),
                                        cv::Size(in_sz.width, img_src.rows * scale));
            }
            // width pad
            else
            {
                scale = (float)in_sz.height / img_src.rows;

                pad_roi_rect = cv::Rect(cv::Point((in_sz.height - scale * img_src.cols) / 2, 0),
                                        cv::Size(img_src.cols * scale, in_sz.height));
            }
        }

        img_src_n = img_src.getUMat(cv::ACCESS_FAST, cv::USAGE_ALLOCATE_DEVICE_MEMORY);

        cv::resize(img_src_n, img_in(pad_roi_rect), cv::Size(pad_roi_rect.width, pad_roi_rect.height), 0, 0, cv::INTER_AREA);

        //cv::imshow("img_src", img_in);

        //cv::waitKey(1);
        
        auto& tim_d = std::chrono::high_resolution_clock::now();

        std::cout << "======== PRE PROCESSED (1) [" 
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]" 
            << std::endl;

        tim = tim_d;

        cv::dnn::blobFromImage(img_in, blob, 1 / 255.0f, in_sz, cv::Scalar(), true, false, CV_32F);

        //model.setInput(blob);

        //auto& outp_tensor = model.forward();

        in_tensor = Ort::Value::CreateTensor<float>(memInfo, (float*)blob.getMat(cv::ACCESS_FAST).data, inputSize, inputDims.data(), inputDims.size());

        tim_d = std::chrono::high_resolution_clock::now();

        std::cout << "PRE PROCESSED (2) ["
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]"
            << std::endl;

        tim = tim_d;


        infWrap.Run(Ort::RunOptions(), 
            std::vector<const char*>({ "images" }).data(), &in_tensor, 1,
            std::vector<const char*>({ "output0" }).data(), &out_tensor, 1
        );

        tim_d = std::chrono::high_resolution_clock::now();

        std::cout << "INFERENCED ["
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]"
            << std::endl;

        tim = tim_d;

        auto& scores = std::vector<float>();
        auto& types = std::vector<int>();
        auto& counts = std::vector<cv::Rect>();
        auto& ind = std::vector<int>();

        for (int i = 0; i < channels; i++) {
            auto lbl_offset = i + channels * 4;

            for (int l = 0; l < labels.size(); l++, lbl_offset += channels) {
                auto& cf = output0_tensor[lbl_offset];

                if (cf < m_cf_thres) continue;

                scores.push_back(cf);
                types.push_back(l);
                counts.push_back(cv::Rect(
                    output0_tensor[i] - output0_tensor[i + channels * 2] / 2,
                    output0_tensor[i + channels] - output0_tensor[i + channels * 3] / 2,
                    output0_tensor[i + channels * 2],
                    output0_tensor[i + channels * 3])
                );
            }
        }

        tim_d = std::chrono::high_resolution_clock::now();

        std::cout << "POST PROCESSED (1) ["
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]"
            << std::endl;

        tim = tim_d;

        auto& nms_scores = std::vector<float>();

        cv::dnn::softNMSBoxes(counts, scores, nms_scores, m_cf_thres, m_iou_thres, ind);

        tim_d = std::chrono::high_resolution_clock::now();

        std::cout << "POST PROCESSED (2) ["
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]"
            << std::endl;

        tim = tim_d;

        auto& res = std::vector<std::tuple<int, float, cv::Rect>>();

        m_outObjects.data = 0;

        for (auto& id : ind) {
            if (types[id] == 1) m_outObjects.data++;
            res.push_back(std::make_tuple(types[id], scores[id], counts[id]));
        }

        tim_d = std::chrono::high_resolution_clock::now();

        m_outObjectsOut.write(m_outObjects);

        std::cout << "POST PROCESSED (3) ["
            << std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(tim_d - tim).count()) << " ms]"
            << std::endl;

        tim = tim_d;

        for (auto& bx : res) {
            auto& bbx = std::get<2>(bx);
            auto& cf = std::get<1>(bx);

            switch (std::get<0>(bx))
            {
            case 0: cv::rectangle(img_in, bbx, cv::Scalar(255, 0, 0), 3, cv::LineTypes::FILLED);
                break;
            case 1: cv::rectangle(img_in, bbx, cv::Scalar(0, 255, 0), 3, cv::LineTypes::FILLED);
                break;                       
            case 2: cv::rectangle(img_in, bbx, cv::Scalar(0, 0, 255), 3, cv::LineTypes::FILLED);
                break;
            default:
                break;
            }
        }

        //cv::imshow("detected", img_in);

        //cv::waitKey(1);
    }

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


RTC::ReturnCode_t YOLOv8_Detection::onReset(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


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
