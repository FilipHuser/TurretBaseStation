cmake_minimum_required(VERSION 3.18.4)

project(baseStation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} pthread ${OPENSSL_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
