cmake_minimum_required(VERSION 3.1...3.12)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(Francois VERSION 1.0 DESCRIPTION "Library for linear algebra" LANGUAGES CXX)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Entity.cpp)

add_library(libEntity STATIC ${SOURCES})
target_include_directories(libEntity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest)

option(PACKAGE_TEST "Build for tets" ON)
if(PACKAGE_TEST)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()




