cmake_minimum_required(VERSION 3.14)
project(CScript LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== Main Library ===========
add_library(cpps
    src/String.cpp
    # src/Array.cpp       # for explicit template instantiations
    # src/Queue.cpp   	  # for explicit instantiations that are added later
)

target_include_directories(cpps PUBLIC include)
target_compile_features(cpps PUBLIC cxx_std_20)

# ========== Install rules (optional for users) ==========
install(TARGETS cpps
    EXPORT cppsTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT cppsTargets
    FILE cppsTargets.cmake
    NAMESPACE cpps::
    DESTINATION lib/cmake/cpps
)

# ========== Testing ==========
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    enable_testing()

    # Fetch GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Recursively find all test .cpp files under tests/
    file(GLOB_RECURSE TEST_SOURCES
        "tests/*/*.cpp"
        "tests/*/*/*.cpp"
    )

    foreach(TEST_SRC ${TEST_SOURCES})
        get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
        add_executable(${TEST_NAME} ${TEST_SRC})
        target_link_libraries(${TEST_NAME} PRIVATE cpps gtest_main)
        include(GoogleTest)
        gtest_discover_tests(${TEST_NAME})
    endforeach()
endif()
