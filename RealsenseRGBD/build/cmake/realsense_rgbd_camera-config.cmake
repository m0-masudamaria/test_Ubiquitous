# RealSense_RGBD_Camera CMake config file
#
# This file sets the following variables:
# RealSense_RGBD_Camera_FOUND - Always TRUE.
# RealSense_RGBD_Camera_INCLUDE_DIRS - Directories containing the RealSense_RGBD_Camera include files.
# RealSense_RGBD_Camera_IDL_DIRS - Directories containing the RealSense_RGBD_Camera IDL files.
# RealSense_RGBD_Camera_LIBRARIES - Libraries needed to use RealSense_RGBD_Camera.
# RealSense_RGBD_Camera_DEFINITIONS - Compiler flags for RealSense_RGBD_Camera.
# RealSense_RGBD_Camera_VERSION - The version of RealSense_RGBD_Camera found.
# RealSense_RGBD_Camera_VERSION_MAJOR - The major version of RealSense_RGBD_Camera found.
# RealSense_RGBD_Camera_VERSION_MINOR - The minor version of RealSense_RGBD_Camera found.
# RealSense_RGBD_Camera_VERSION_REVISION - The revision version of RealSense_RGBD_Camera found.
# RealSense_RGBD_Camera_VERSION_CANDIDATE - The candidate version of RealSense_RGBD_Camera found.

message(STATUS "Found RealSense_RGBD_Camera-")
set(RealSense_RGBD_Camera_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(RealSense_RGBD_Camera_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor/include/realsense_rgbd_camera-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(RealSense_RGBD_Camera_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor/include/realsense_rgbd_camera-/idl")
set(RealSense_RGBD_Camera_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(RealSense_RGBD_Camera_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor/include//idl")


if(WIN32)
    set(RealSense_RGBD_Camera_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor//realsense_rgbd_camera.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(RealSense_RGBD_Camera_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Sensor/OpenRTM-aist/2.0.1/Components/c++/Sensor//realsense_rgbd_camera.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(RealSense_RGBD_Camera_DEFINITIONS ${<dependency>_DEFINITIONS})

set(RealSense_RGBD_Camera_VERSION )
set(RealSense_RGBD_Camera_VERSION_MAJOR )
set(RealSense_RGBD_Camera_VERSION_MINOR )
set(RealSense_RGBD_Camera_VERSION_REVISION )
set(RealSense_RGBD_Camera_VERSION_CANDIDATE )

