cmake_minimum_required(VERSION 3.14)
project(cpps_nullable LANGUAGES CXX)

# This library depends on some features introduced in C++20
add_library(cpps_nullable INTERFACE)
target_include_directories(cpps_nullable INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(cpps_nullable INTERFACE cxx_std_20)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing and build tests only if option ON
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
  enable_testing()
  add_executable(nullable_tests tests/NullableTest.cpp)
  target_link_libraries(nullable_tests PRIVATE cpps_nullable gtest_main)
  include(GoogleTest)
  gtest_discover_tests(nullable_tests)
endif()
