# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "C:/Users/cakes/workspace/cal_inverse_kinematics;C:/Users/cakes/workspace/test_Ubiquitous/cal_inverse_kinematics/build")
set(CPACK_CMAKE_GENERATOR "Visual Studio 17 2022")
set(CPACK_COMPONENTS_ALL "component")
set(CPACK_COMPONENTS_ALL_SET_BY_USER "TRUE")
set(CPACK_COMPONENT_COMPONENT_DESCRIPTION "Component library and stand-alone executable")
set(CPACK_COMPONENT_COMPONENT_DISPLAY_NAME "Applications")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "cal_inverse_kinematics built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "7Z;ZIP")
set(CPACK_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALLED_DIRECTORIES "C:/Users/cakes/workspace/cal_inverse_kinematics;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/calculate inverse kinematics/OpenRTM-aist/2.0.1/Components/c++/calculate inverse kinematics")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "OpenRTM-aist/2.0.1/Components/c++/calculate inverse kinematics")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "OpenRTM-aist/2.0.1/Components/c++/calculate inverse kinematics")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/cakes/workspace/test_Ubiquitous/cal_inverse_kinematics/build/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ModuleDescription")
set(CPACK_PACKAGE_EXECUTABLES "cal_inverse_kinematicsComp;cal_inverse_kinematicsComp.exe")
set(CPACK_PACKAGE_FILE_NAME "cal_inverse_kinematics_rtm201_--Source")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpenRTM-aist/2.0.1/Components/c++/calculate inverse kinematics")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "OpenRTM-aist/2.0.1/Components/c++/calculate inverse kinematics")
set(CPACK_PACKAGE_NAME "cal_inverse_kinematics_rtm201_")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "TMU")
set(CPACK_PACKAGE_VERSION "")
set(CPACK_PACKAGE_VERSION_MAJOR "")
set(CPACK_PACKAGE_VERSION_MINOR "")
set(CPACK_PACKAGE_VERSION_PATCH "")
set(CPACK_PROJECT_CONFIG_FILE "C:/Users/cakes/workspace/test_Ubiquitous/cal_inverse_kinematics/build/cpack_options.cmake")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Users/cakes/workspace/cal_inverse_kinematics/cmake/License.rtf")
set(CPACK_RESOURCE_FILE_README "C:/Program Files/CMake/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Program Files/CMake/share/cmake-3.29/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_NAME "cal_inverse_kinematics")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "C:/Users/cakes/workspace/cal_inverse_kinematics;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/cakes/workspace/test_Ubiquitous/cal_inverse_kinematics/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "cal_inverse_kinematics_rtm201_--Source")
set(CPACK_SOURCE_TOPLEVEL_TAG "win64-Source")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_STRIP_FILES "")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64-Source")
set(CPACK_UNINSTALL_NAME "cal_inverse_kinematics")
set(CPACK_WIX_CULTURES "ja-jp")
set(CPACK_WIX_PRODUCT_ICON "C:/Users/cakes/workspace/cal_inverse_kinematics/cmake\rt_middleware_logo.ico")
set(CPACK_WIX_PROPERTY_ARPURLINFOABOUT "http://www.openrtm.org")
set(CPACK_WIX_SIZEOF_VOID_P "8")
set(CPACK_WIX_UI_BANNER "C:/Users/cakes/workspace/cal_inverse_kinematics/cmake/rt_middleware_banner.bmp")
set(CPACK_WIX_UI_DIALOG "C:/Users/cakes/workspace/cal_inverse_kinematics/cmake/rt_middleware_dlg.bmp")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/cakes/workspace/test_Ubiquitous/cal_inverse_kinematics/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
