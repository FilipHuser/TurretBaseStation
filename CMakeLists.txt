cmake_minimum_required(VERSION 3.18.4)

project(baseStation)

file(GLOB SOURCE_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

install(TARGETS ${PROJECT_NAME} DESTINATION  bin)