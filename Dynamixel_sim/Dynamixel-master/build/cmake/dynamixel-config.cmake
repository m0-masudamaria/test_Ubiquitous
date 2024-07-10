# Dynamixel CMake config file
#
# This file sets the following variables:
# Dynamixel_FOUND - Always TRUE.
# Dynamixel_INCLUDE_DIRS - Directories containing the Dynamixel include files.
# Dynamixel_IDL_DIRS - Directories containing the Dynamixel IDL files.
# Dynamixel_LIBRARIES - Libraries needed to use Dynamixel.
# Dynamixel_DEFINITIONS - Compiler flags for Dynamixel.
# Dynamixel_VERSION - The version of Dynamixel found.
# Dynamixel_VERSION_MAJOR - The major version of Dynamixel found.
# Dynamixel_VERSION_MINOR - The minor version of Dynamixel found.
# Dynamixel_VERSION_REVISION - The revision version of Dynamixel found.
# Dynamixel_VERSION_CANDIDATE - The candidate version of Dynamixel found.

message(STATUS "Found Dynamixel-1.0.0")
set(Dynamixel_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Dynamixel_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel/include/dynamixel-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Dynamixel_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel/include/dynamixel-1/idl")
set(Dynamixel_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Dynamixel_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel/include//idl")


if(WIN32)
    set(Dynamixel_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel//dynamixel.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Dynamixel_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/..Components/c++/Actuator/Dynamixel//dynamixel.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Dynamixel_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Dynamixel_VERSION 1.0.0)
set(Dynamixel_VERSION_MAJOR 1)
set(Dynamixel_VERSION_MINOR 0)
set(Dynamixel_VERSION_REVISION 0)
set(Dynamixel_VERSION_CANDIDATE )

