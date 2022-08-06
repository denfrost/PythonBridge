cmake_minimum_required(VERSION 3.23)
project(PythonBridge)

set(CMAKE_CXX_STANDARD 17)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output CACHE PATH ${CMAKE_CURRENT_BINARY_DIR} FORCE)

add_library(PythonBridge SHARED library.cpp)

if(WIN32)
    target_include_directories(PythonBridge PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty/Win/Python/Include)
    target_link_libraries(PythonBridge PRIVATE
            ${CMAKE_SOURCE_DIR}/thirdparty/Win/Python/libs/_tkinter.lib
            ${CMAKE_SOURCE_DIR}/thirdparty/Win/Python/libs/python3.lib
            ${CMAKE_SOURCE_DIR}/thirdparty/Win/Python/libs/python39.lib
            ${CMAKE_SOURCE_DIR}/thirdparty/Win/Python/libs/python39_d.lib
            )

    message("Coping .dll files to Unreal binaries")
    add_custom_command(TARGET PythonBridge POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/PythonBridge.dll ${CMAKE_CURRENT_SOURCE_DIR}/../../../Binaries/ThirdParty/PythonLibrary/Win64
            )
elseif(UNIX)
    target_include_directories(PythonBridge PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty/Linux/Python/include)
    #[[
    target_link_libraries(PythonBridge PRIVATE
            ${CMAKE_SOURCE_DIR}/thirdparty/Linux/Python/lib/x86_64-linux-gnu/libpython3.9.so
            )
    ]]
    message("Coping .so files to Unreal binaries")
    #[[
    add_custom_command(TARGET PythonBridge POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/PythonBridge.so ${CMAKE_CURRENT_SOURCE_DIR}/../../../Binaries/ThirdParty/PythonLibrary/Win64
            )
            ]]
endif()