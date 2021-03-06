cmake_minimum_required(VERSION 3.1)

set(PROJ_NAME GLPlayground)

project(${PROJ_NAME} VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

option(DEBUG "Debug Version" on)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32 AND MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG /MTd")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG /MTd")
elseif(APPLE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
else()
    if(DEBUG)
        add_definitions(-DDEBUG)
    endif(DEBUG)
endif()

set(PROJ_SOURCE_ROOT ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/libs/cglm/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/glfw/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/rlib/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/rglu/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/SOIL2/src)
include_directories(${PROJECT_SOURCE_DIR}/libs/assimp/include)

add_subdirectory(libs/glad)
add_subdirectory(libs/glfw)
add_subdirectory(libs/rlib)
add_subdirectory(libs/cglm)
add_subdirectory(libs/rglu)
add_subdirectory(libs/SOIL2)
add_subdirectory(libs/assimp)
add_subdirectory(projects)
