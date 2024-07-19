# SetReferences.cmake

# Define the path to nuget.exe
set(NUGET_EXECUTABLE "${CMAKE_SOURCE_DIR}/nuget.exe")

# Define the packages.config file location
set(PACKAGES_CONFIG "${CMAKE_SOURCE_DIR}/src/packages.config")

# Define the output directory
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/packages")

# Run nuget.exe install command
execute_process(
    COMMAND ${NUGET_EXECUTABLE} install ${PACKAGES_CONFIG} -OutputDirectory ${OUTPUT_DIRECTORY}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE NUGET_RESULT
    ERROR_VARIABLE NUGET_ERROR
)

# Check the result of the nuget install command
if (NUGET_RESULT)
    message(FATAL_ERROR "NuGet install failed: ${NUGET_ERROR}")
endif()