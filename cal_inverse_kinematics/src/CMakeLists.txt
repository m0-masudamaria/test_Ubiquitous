set(comp_srcs cal_inverse_kinematics.cpp basic_funtion.cpp cal_4motor_ik.cpp cal_3motor_ik.cpp operate_motor.cpp)
set(standalone_srcs cal_inverse_kinematicsComp.cpp)

if(${OPENRTM_VERSION_MAJOR} LESS 2)
  set(OPENRTM_CFLAGS ${OPENRTM_CFLAGS} ${OMNIORB_CFLAGS})
  set(OPENRTM_INCLUDE_DIRS ${OPENRTM_INCLUDE_DIRS} ${OMNIORB_INCLUDE_DIRS})
  set(OPENRTM_LIBRARY_DIRS ${OPENRTM_LIBRARY_DIRS} ${OMNIORB_LIBRARY_DIRS})
else()
  set(CMAKE_CXX_STANDARD 11)
endif()

if (DEFINED OPENRTM_INCLUDE_DIRS)
  string(REGEX REPLACE "-I" ";"
    OPENRTM_INCLUDE_DIRS "${OPENRTM_INCLUDE_DIRS}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_INCLUDE_DIRS "${OPENRTM_INCLUDE_DIRS}")
endif (DEFINED OPENRTM_INCLUDE_DIRS)

if (DEFINED OPENRTM_LIBRARY_DIRS)
  string(REGEX REPLACE "-L" ";"
    OPENRTM_LIBRARY_DIRS "${OPENRTM_LIBRARY_DIRS}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_LIBRARY_DIRS "${OPENRTM_LIBRARY_DIRS}")
endif (DEFINED OPENRTM_LIBRARY_DIRS)

if (DEFINED OPENRTM_LIBRARIES)
  string(REGEX REPLACE "-l" ";"
    OPENRTM_LIBRARIES "${OPENRTM_LIBRARIES}")
  string(REGEX REPLACE " ;" ";"
    OPENRTM_LIBRARIES "${OPENRTM_LIBRARIES}")
endif (DEFINED OPENRTM_LIBRARIES)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME})
include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_BINARY_DIR}/idl)
include_directories(${OPENRTM_INCLUDE_DIRS})
add_definitions(${OPENRTM_CFLAGS})

MAP_ADD_STR(comp_hdrs "../" comp_headers)
MAP_ADD_STR(comp_hdrs_1 "../" comp_headers_1)
MAP_ADD_STR(comp_hdrs_2 "../" comp_headers_2)
MAP_ADD_STR(comp_hdrs_3 "../" comp_headers_3)
MAP_ADD_STR(comp_hdrs_4 "../" comp_headers_4)

link_directories(${OPENRTM_LIBRARY_DIRS})

add_library(${PROJECT_NAME} ${LIB_TYPE} ${comp_srcs}
  ${comp_headers} ${comp_headers_1} ${comp_headers_2} ${comp_headers_3} ${comp_headers_4} ${ALL_IDL_SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_source_files_properties(${ALL_IDL_SRCS} PROPERTIES GENERATED 1)
if(NOT TARGET ALL_IDL_TGT)
 add_custom_target(ALL_IDL_TGT)
endif(NOT TARGET ALL_IDL_TGT)
add_dependencies(${PROJECT_NAME} ALL_IDL_TGT)
target_link_libraries(${PROJECT_NAME} ${OPENRTM_LIBRARIES})

add_executable(${PROJECT_NAME}Comp ${standalone_srcs}
  ${comp_srcs} ${comp_headers} ${comp_headers_1} ${comp_headers_2} ${comp_headers_3} ${comp_headers_4} ${ALL_IDL_SRCS})
add_dependencies(${PROJECT_NAME}Comp ALL_IDL_TGT)
target_link_libraries(${PROJECT_NAME}Comp ${OPENRTM_LIBRARIES})

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}Comp
    EXPORT ${PROJECT_NAME}
    RUNTIME DESTINATION ${INSTALL_PREFIX} COMPONENT component
    LIBRARY DESTINATION ${INSTALL_PREFIX} COMPONENT component
    ARCHIVE DESTINATION ${INSTALL_PREFIX} COMPONENT component)

install(FILES ${PROJECT_SOURCE_DIR}/RTC.xml DESTINATION ${INSTALL_PREFIX}
        COMPONENT component)
