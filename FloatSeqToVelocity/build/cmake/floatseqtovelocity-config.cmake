# FloatSeqToVelocity CMake config file
#
# This file sets the following variables:
# FloatSeqToVelocity_FOUND - Always TRUE.
# FloatSeqToVelocity_INCLUDE_DIRS - Directories containing the FloatSeqToVelocity include files.
# FloatSeqToVelocity_IDL_DIRS - Directories containing the FloatSeqToVelocity IDL files.
# FloatSeqToVelocity_LIBRARIES - Libraries needed to use FloatSeqToVelocity.
# FloatSeqToVelocity_DEFINITIONS - Compiler flags for FloatSeqToVelocity.
# FloatSeqToVelocity_VERSION - The version of FloatSeqToVelocity found.
# FloatSeqToVelocity_VERSION_MAJOR - The major version of FloatSeqToVelocity found.
# FloatSeqToVelocity_VERSION_MINOR - The minor version of FloatSeqToVelocity found.
# FloatSeqToVelocity_VERSION_REVISION - The revision version of FloatSeqToVelocity found.
# FloatSeqToVelocity_VERSION_CANDIDATE - The candidate version of FloatSeqToVelocity found.

message(STATUS "Found FloatSeqToVelocity-1.0.0")
set(FloatSeqToVelocity_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(FloatSeqToVelocity_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/floatseqtovelocity-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(FloatSeqToVelocity_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/floatseqtovelocity-1/idl")
set(FloatSeqToVelocity_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(FloatSeqToVelocity_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include//idl")


if(WIN32)
    set(FloatSeqToVelocity_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category//floatseqtovelocity.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(FloatSeqToVelocity_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category//floatseqtovelocity.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(FloatSeqToVelocity_DEFINITIONS ${<dependency>_DEFINITIONS})

set(FloatSeqToVelocity_VERSION 1.0.0)
set(FloatSeqToVelocity_VERSION_MAJOR 1)
set(FloatSeqToVelocity_VERSION_MINOR 0)
set(FloatSeqToVelocity_VERSION_REVISION 0)
set(FloatSeqToVelocity_VERSION_CANDIDATE )

