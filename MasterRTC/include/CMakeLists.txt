add_subdirectory(Master)

MAP_ADD_STR(hdrs "${PROJECT_NAME}/" headers)
set(headers ${headers} PARENT_SCOPE)

MAP_ADD_STR(hdrs_1 "${PROJECT_NAME}/" headers_1)
set(headers_1 ${headers_1} PARENT_SCOPE)
