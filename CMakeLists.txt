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

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(BUILD_SHARED_LIBS)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

if (BUILD_SHARED_LIBS)
  # Always full RPATH
  # use, i.e. don't skip the full RPATH for the build tree
  set(CMAKE_SKIP_BUILD_RPATH FALSE)

  # when building, don't use the install RPATH already
  # (but later on when installing)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

  # add the automatically determined parts of the RPATH
  # which point to directories outside the build tree to the install RPATH
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

  # the RPATH to be used when installing, but only if it's not a system directory
  list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
  if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
  endif("${isSystemDir}" STREQUAL "-1")
endif()

include(FetchContent)

if(DEFINED ENV{CI_COMMIT_REF_NAME})
  set(GIT_BRANCH "$ENV{CI_COMMIT_REF_NAME}")
else()
  execute_process(
    COMMAND bash -c "git status | grep origin | sed -e 's/.*origin\\///' -e 's/[^a-zA-Z].*//'" 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()
message(STATUS "${TADAH}.MD Using GIT_BRANCH:  ${GIT_BRANCH}.")

FetchContent_Declare(
    Tadah.MODELS
    GIT_REPOSITORY https://git.ecdf.ed.ac.uk/tadah/models.git
    GIT_TAG origin/${GIT_BRANCH}
)

FetchContent_MakeAvailable(Tadah.MODELS)

file(GLOB MD_SRC CONFIGURE_DEPENDS "src/*.cpp")
add_library(tadah.md ${MD_SRC})
target_link_libraries(tadah.md PUBLIC tadah.models)

target_include_directories(tadah.md PUBLIC include)
target_include_directories(tadah.md PUBLIC ${Tadah.CORE_SOURCE_DIR}/include)
target_include_directories(tadah.md PUBLIC ${Tadah.CORE_SOURCE_DIR}/external/toml11)
target_include_directories(tadah.md PUBLIC ${Tadah.MODELS_SOURCE_DIR}/include)

if(TADAH_ENABLE_OPENMP)
  find_package(OpenMP REQUIRED)
  target_link_libraries(tadah.md PUBLIC OpenMP::OpenMP_CXX)
endif()

if(TADAH_BUILD_TESTS)
  include(CTest) 
  add_subdirectory(tests)
endif()

# Installation rules
install(TARGETS tadah.md
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/
    DESTINATION include
)
