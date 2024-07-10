# YOLOv8_Detection CMake config file
#
# This file sets the following variables:
# YOLOv8_Detection_FOUND - Always TRUE.
# YOLOv8_Detection_INCLUDE_DIRS - Directories containing the YOLOv8_Detection include files.
# YOLOv8_Detection_IDL_DIRS - Directories containing the YOLOv8_Detection IDL files.
# YOLOv8_Detection_LIBRARIES - Libraries needed to use YOLOv8_Detection.
# YOLOv8_Detection_DEFINITIONS - Compiler flags for YOLOv8_Detection.
# YOLOv8_Detection_VERSION - The version of YOLOv8_Detection found.
# YOLOv8_Detection_VERSION_MAJOR - The major version of YOLOv8_Detection found.
# YOLOv8_Detection_VERSION_MINOR - The minor version of YOLOv8_Detection found.
# YOLOv8_Detection_VERSION_REVISION - The revision version of YOLOv8_Detection found.
# YOLOv8_Detection_VERSION_CANDIDATE - The candidate version of YOLOv8_Detection found.

message(STATUS "Found YOLOv8_Detection-")
set(YOLOv8_Detection_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(YOLOv8_Detection_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong/include/yolov8_detection-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(YOLOv8_Detection_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong/include/yolov8_detection-/idl")
set(YOLOv8_Detection_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(YOLOv8_Detection_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong/include//idl")


if(WIN32)
    set(YOLOv8_Detection_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong//yolov8_detection.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(YOLOv8_Detection_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/ImageProcessiong/OpenRTM-aist/2.0.1/Components/c++/ImageProcessiong//yolov8_detection.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(YOLOv8_Detection_DEFINITIONS ${<dependency>_DEFINITIONS})

set(YOLOv8_Detection_VERSION )
set(YOLOv8_Detection_VERSION_MAJOR )
set(YOLOv8_Detection_VERSION_MINOR )
set(YOLOv8_Detection_VERSION_REVISION )
set(YOLOv8_Detection_VERSION_CANDIDATE )

