# Install script for directory: C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category")
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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Debug/FloatSeqToVelocity.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Release/FloatSeqToVelocity.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/MinSizeRel/FloatSeqToVelocity.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/RelWithDebInfo/FloatSeqToVelocity.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Debug/FloatSeqToVelocity.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Release/FloatSeqToVelocity.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/MinSizeRel/FloatSeqToVelocity.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE SHARED_LIBRARY FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/RelWithDebInfo/FloatSeqToVelocity.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Debug/FloatSeqToVelocityComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/Release/FloatSeqToVelocityComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/MinSizeRel/FloatSeqToVelocityComp.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE EXECUTABLE FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/build/src/RelWithDebInfo/FloatSeqToVelocityComp.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "component" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/FloatSeqToVelocity" TYPE FILE FILES "C:/Users/cakes/workspace/test_Ubiquitous/FloatSeqToVelocity/RTC.xml")
endif()

