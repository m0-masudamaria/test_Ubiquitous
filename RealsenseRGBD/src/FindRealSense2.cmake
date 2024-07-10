# FindRealSense2.cmake

# Adjust the path to your RealSense SDK installation
set(realsense2_DIR "C:/Program Files (x86)/Intel RealSense SDK 2.0")

# Check if the path exists
if(NOT EXISTS "${realsense2_DIR}")
  message(FATAL_ERROR "RealSense SDK not found in ${realsense2_DIR}")
endif()

# Include directories for RealSense SDK
set(realsense2_INCLUDE_DIR "${realsense2_DIR}/include")
# Library directories for RealSense SDK
set(realsense2_LIBRARY_DIR "${realsense2_DIR}/lib/x64")

# Set the library name (adjust as necessary)
set(realsense2_LIBRARIES realsense2)

# Provide the include directories to the parent scope
set(realsense2_INCLUDE_DIRS ${realsense2_INCLUDE_DIR} PARENT_SCOPE)
# Provide the library directories to the parent scope
set(realsense2_LIBRARY_DIRS ${realsense2_LIBRARY_DIR} PARENT_SCOPE)
# Provide the libraries to the parent scope
set(realsense2_LIBRARIES ${realsense2_LIBRARIES} PARENT_SCOPE)
