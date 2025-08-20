cmake_minimum_required(VERSION 3.16)
project(cpps
    VERSION 0.1.0
    DESCRIPTION "The C-Script Library — TypeScript Ergonomics. C++ power."
    HOMEPAGE_URL "https://github.com/BellJrDev/C-Script"
    LANGUAGES CXX
)

option(CPPS_BUILD_TESTS "Building C-Script unit tests" ON)

# --- Header-only target ---
add_library(cpps INTERFACE)
target_include_directories(cpps INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(cpps INTERFACE cxx_std_20)

# Branding in output
message(STATUS "Configuring The C-Script Library (cpps)")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ standard: C++20")

# Installation
include(GNUInstallDirs)
install(TARGETS cpps EXPORT cppsTargets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT cppsTargets
    FILE cppsConfig.cmake
    NAMESPACE cpps::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cpps
)

# Tests
if(CPPS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
