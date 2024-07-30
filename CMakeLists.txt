cmake_minimum_required(VERSION 3.18...3.26 FATAL_ERROR)

project(SerialLine LANGUAGES CXX
        VERSION 1.3.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/TangoCMakeModules)
find_package(Tango REQUIRED)

set(CMAKE_CXX_EXTENSIONS OFF)

set(LIB_SOURCES
        src/Serial.cpp
        src/SerialClass.cpp
        src/SerialStateMachine.cpp)
set(SOURCES
        src/ClassFactory.cpp
        src/main.cpp)

set(HEADERS
    src/Serial.h
    src/SerialClass.h)

if(WIN32)
    list(APPEND LIB_SOURCES src/SerialWin32.cpp)
elseif(UNIX)
    list(APPEND LIB_SOURCES src/SerialLinux.cpp)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(serial_lib EXCLUDE_FROM_ALL ${LIB_SOURCES})
target_link_libraries(serial_lib PRIVATE Tango::Tango)
target_include_directories(serial_lib PUBLIC src)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Tango::Tango serial_lib)

set_target_properties(serial_lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")

install(TARGETS ${PROJECT_NAME} serial_lib RUNTIME DESTINATION bin)

if (WIN32 AND (Tango_IS_STATIC OR Tango_FORCE_STATIC))
    set_target_properties(${PROJECT_NAME} serial_lib
      PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
endif()

option(TANGO_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

if(TANGO_WARNINGS_AS_ERRORS)
  target_compile_options(${PROJECT_NAME} PUBLIC -Werror -Wall -Wextra -Wformat -Werror=format-security -pedantic)
endif()
