cmake_minimum_required(VERSION 3.0)

add_library(GrimBulldozer
    src/Node.cpp
    src/Node.h
    src/test.cpp
    src/test.h
)

add_executable(GrimBulldozerFrontend
    src/main.cpp
)

target_link_libraries(GrimBulldozerFrontend GrimBulldozer ${POCO_LIBRARIES})