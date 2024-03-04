cmake_minimum_required(VERSION 3.12)
project(Tadah.MD)

# Guard against in-source builds
# Also, make sure user does not accidently invoke cmake .. from the source dir
# of the module in case module is added as a submodule.
get_filename_component(MODULE_TEST ${CMAKE_BINARY_DIR} NAME)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}
        OR ${MODULE_TEST} STREQUAL "MD"
        )
    message(FATAL_ERROR "
    In-source builds not allowed.
    Please make a new directory (called a build directory) and run CMake from there.
    You may need to remove CMakeCache.txt and CMakeFiles dir. ")
endif()

# check required modules are present
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../CORE")
    message("This module requires CORE module for compilation.")
    message(FATAL_ERROR "CORE module not found.")
endif()
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../MODELS")
    message("This module requires MODELS module for compilation.")
    message(FATAL_ERROR "MODELS module not found.")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB MD_SRC CONFIGURE_DEPENDS "*.cpp" "*.h" "*.hpp")

add_library(tadah.md.obj OBJECT
    ${MD_SRC}
    )

if(TADAH_ENABLE_OPENMP)
    find_package(OpenMP REQUIRED)
    target_link_libraries(tadah.md.obj PUBLIC OpenMP::OpenMP_CXX)
endif()

add_library(tadah.md STATIC $<TARGET_OBJECTS:tadah.md.obj>)

include(CTest) 
if(TADAH_BUILD_TESTS)
    add_subdirectory(tests)
endif()

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/catch2)
