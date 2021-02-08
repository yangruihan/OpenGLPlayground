aux_source_directory(./src SRC_FILES)

set(PROJ_NAME demo)

project(${PROJ_NAME})

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")

source_group("Headers" FILES ${HEADERS})

include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/../../libs/cglm/include)
include_directories(${PROJECT_SOURCE_DIR}/../../libs/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/../../libs/glfw/include)
include_directories(${PROJECT_SOURCE_DIR}/../../libs/rlib/src)

if (WIN32)
    set(EXECUTABLE_OUTPUT_PATH "${PROJ_SOURCE_ROOT}/bin/${PROJ_NAME}")
else (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(EXECUTABLE_OUTPUT_PATH "${PROJ_SOURCE_ROOT}/bin/Debug")
    else (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(EXECUTABLE_OUTPUT_PATH "${PROJ_SOURCE_ROOT}/bin/Release")
    endif (CMAKE_BUILD_TYPE MATCHES "Debug")
endif (WIN32)

add_executable(
    ${PROJ_NAME}
    ${SRC_FILES}
    ${HEADERS}
)

target_link_libraries(
    ${PROJ_NAME}
    glad
    glfw
    rlib
    cglm
)
