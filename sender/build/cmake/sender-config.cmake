# sender CMake config file
#
# This file sets the following variables:
# sender_FOUND - Always TRUE.
# sender_INCLUDE_DIRS - Directories containing the sender include files.
# sender_IDL_DIRS - Directories containing the sender IDL files.
# sender_LIBRARIES - Libraries needed to use sender.
# sender_DEFINITIONS - Compiler flags for sender.
# sender_VERSION - The version of sender found.
# sender_VERSION_MAJOR - The major version of sender found.
# sender_VERSION_MINOR - The minor version of sender found.
# sender_VERSION_REVISION - The revision version of sender found.
# sender_VERSION_CANDIDATE - The candidate version of sender found.

message(STATUS "Found sender-1.0.0")
set(sender_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(sender_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/sender-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(sender_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/sender-1/idl")
set(sender_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(sender_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/include//idl")


if(WIN32)
    set(sender_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category//sender.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(sender_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category//sender.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(sender_DEFINITIONS ${<dependency>_DEFINITIONS})

set(sender_VERSION 1.0.0)
set(sender_VERSION_MAJOR 1)
set(sender_VERSION_MINOR 0)
set(sender_VERSION_REVISION 0)
set(sender_VERSION_CANDIDATE )

