cmake_minimum_required(VERSION 3.8)
project(Goku)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(SOURCE_FILES main.cpp Window.cpp Window.h Game.cpp Game.h Animation.cpp Animation.h Goku.cpp Goku.h)
add_executable(Goku ${SOURCE_FILES})


set(EXECUTABLE_NAME ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()