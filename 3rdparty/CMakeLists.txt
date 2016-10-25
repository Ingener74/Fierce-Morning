cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

option(ENABLE_DEPEND_POCO "Enable POCO dependency" ON)
if(ENABLE_DEPEND_POCO)
    add_subdirectory(POCO)
endif()

