cmake_minimum_required(VERSION 3.18.4)

project(baseStation)

file(GLOB SOURCE_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} DESTINATION  bin)