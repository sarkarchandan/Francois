cmake_minimum_required(VERSION 3.1...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.13)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(Francois VERSION 1.0 DESCRIPTION "This library uses C++ STL features to  demonstrate basic operations of linear algebra" LANGUAGES CXX)
include(CTest)

if(NOT TARGET gtest OR NOT TARGET gtest_main OR NOT TARGET gmock OR NOT TARGET gmock_main)
  
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.8.1
  )
  FetchContent_GetProperties(googletest)

  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  endif()

endif()

add_library(Francois INTERFACE)
target_include_directories(Francois INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(Francois INTERFACE cxx_std_14)

add_executable(Example ${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp)
target_include_directories(Example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/example/include)
target_compile_features(Example PRIVATE cxx_std_14)
target_link_libraries(Example Francois)

option(PACKAGE_TEST "Build for tests" ON)
if(PACKAGE_TEST)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()




