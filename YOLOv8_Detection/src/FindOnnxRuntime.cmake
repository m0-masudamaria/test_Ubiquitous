# FindOnnxRuntime.cmake

# Adjust the path to your ONNXRuntime installation
set(ONNXRUNTIME_DIR "${CMAKE_BINARY_DIR}/packages/Microsoft.ML.OnnxRuntime.1.18.1" CACHE STRING "ONNX runtime package directory")

set(ONNXRUNTIME_PROPS_FILE "${ONNXRUNTIME_DIR}/build/native/Microsoft.ML.OnnxRuntime.props")

# Include directories for ONNXRuntime
set(ONNXRUNTIME_INCLUDE_DIR "${ONNXRUNTIME_DIR}/build/native/include")
# Library directories for ONNXRuntime
set(ONNXRUNTIME_LIBRARY_DIR "${ONNXRUNTIME_DIR}/runtimes/win-x64/native")

# Set the library name (adjust as necessary)
set(ONNXRUNTIME_LIBRARIES "${ONNXRUNTIME_LIBRARY_DIR}/onnxruntime.lib")
