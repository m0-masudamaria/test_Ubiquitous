# Install script for directory: C:/Users/cakes/workspace/cal_inverse_kinematics/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Debug/cal_inverse_kinematics.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Release/cal_inverse_kinematics.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/MinSizeRel/cal_inverse_kinematics.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/RelWithDebInfo/cal_inverse_kinematics.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Debug/cal_inverse_kinematics.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Release/cal_inverse_kinematics.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/MinSizeRel/cal_inverse_kinematics.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/RelWithDebInfo/cal_inverse_kinematics.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Debug/cal_inverse_kinematicsComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/Release/cal_inverse_kinematicsComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/MinSizeRel/cal_inverse_kinematicsComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/build/src/RelWithDebInfo/cal_inverse_kinematicsComp.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cal_inverse_kinematics" TYPE FILE FILES "C:/Users/cakes/workspace/cal_inverse_kinematics/RTC.xml")
endif()

