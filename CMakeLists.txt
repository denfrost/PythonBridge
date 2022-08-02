cmake_minimum_required(VERSION 3.14)

project(QtPythonBridge LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(QtPythonBridge SHARED
  QtPythonBridge_global.h
  qtpythonbridge.cpp
  qtpythonbridge.h
)

if(WIN32)
    target_include_directories(QtPythonBridge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Win64/Python/Include)
    target_link_libraries(QtPythonBridge PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Win64/Python/libs/python39_d.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Win64/Python/libs/python39.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Win64/Python/libs/python3.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Win64/Python/libs/_tkinter.lib
    )
endif(WIN32)

target_link_libraries(QtPythonBridge PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(QtPythonBridge PRIVATE QTPYTHONBRIDGE_LIBRARY)
