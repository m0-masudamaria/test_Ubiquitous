# cal_inverse_kinematics CMake config file
#
# This file sets the following variables:
# cal_inverse_kinematics_FOUND - Always TRUE.
# cal_inverse_kinematics_INCLUDE_DIRS - Directories containing the cal_inverse_kinematics include files.
# cal_inverse_kinematics_IDL_DIRS - Directories containing the cal_inverse_kinematics IDL files.
# cal_inverse_kinematics_LIBRARIES - Libraries needed to use cal_inverse_kinematics.
# cal_inverse_kinematics_DEFINITIONS - Compiler flags for cal_inverse_kinematics.
# cal_inverse_kinematics_VERSION - The version of cal_inverse_kinematics found.
# cal_inverse_kinematics_VERSION_MAJOR - The major version of cal_inverse_kinematics found.
# cal_inverse_kinematics_VERSION_MINOR - The minor version of cal_inverse_kinematics found.
# cal_inverse_kinematics_VERSION_REVISION - The revision version of cal_inverse_kinematics found.
# cal_inverse_kinematics_VERSION_CANDIDATE - The candidate version of cal_inverse_kinematics found.

message(STATUS "Found cal_inverse_kinematics-1.0.0")
set(cal_inverse_kinematics_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(cal_inverse_kinematics_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics/include/cal_inverse_kinematics-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(cal_inverse_kinematics_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics/include/cal_inverse_kinematics-1/idl")
set(cal_inverse_kinematics_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(cal_inverse_kinematics_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics/include//idl")


if(WIN32)
    set(cal_inverse_kinematics_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics//cal_inverse_kinematics.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(cal_inverse_kinematics_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics//cal_inverse_kinematics.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(cal_inverse_kinematics_DEFINITIONS ${<dependency>_DEFINITIONS})

set(cal_inverse_kinematics_VERSION 1.0.0)
set(cal_inverse_kinematics_VERSION_MAJOR 1)
set(cal_inverse_kinematics_VERSION_MINOR 0)
set(cal_inverse_kinematics_VERSION_REVISION 0)
set(cal_inverse_kinematics_VERSION_CANDIDATE )

