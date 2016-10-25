cmake_minimum_required(VERSION 3.0)

# include modules
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

unset(BUILD_PLATFORM)
if(MINGW OR MSYS)
    message(STATUS "MinGW or MSYS build")
    set(BUILD_PLATFORM msys_mingw)
    add_definitions(-std=gnu++0x)
    include(FindPatch)
elseif(MSVC)
    message(STATUS "Microsoft Visual Studio 2013 build")
    set(BUILD_PLATFORM msvc)
    add_definitions(/DYY_NO_UNISTD_H)
elseif(EMSCRIPTEN)
    message(STATUS "Emscripten build")
    set(BUILD_PLATFORM emscripten)
elseif(ANDROID)
    message(STATUS "Android build")
    set(BUILD_PLATFORM android)
elseif(APPLE)
    message(STATUS "MacOS build")
    set(BUILD_PLATFORM macos)
    add_definitions(-std=c++11)
else()
    message(STATUS "Linux build")
    set(BUILD_PLATFORM linux)
    add_definitions(-std=c++11)
endif()

set(SYSROOT ${CMAKE_SOURCE_DIR}/3rdparty/sysroot-${BUILD_PLATFORM})

set(3RDPARTY_INSTALL ${SYSROOT})

add_subdirectory(3rdparty)

include_directories(
    ${SYSROOT}/include
)
link_directories(
    ${SYSROOT}/lib
)

if(EXISTS ${SYSROOT})
    option(ENABLE_GRIM_BULLDOZER "Enable Grim Bulldozer" OFF)
    if(ENABLE_GRIM_BULLDOZER)
        add_subdirectory(GrimBulldozer)
    endif()
endif()

