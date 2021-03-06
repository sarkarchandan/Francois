cmake_minimum_required(VERSION 3.1...3.13)
if(${CMAKE_VERSION} VERSION_LESS 3.13)
  cmake_policy(VERSION  ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(FrancoisTestSuite VERSION 1.0 DESCRIPTION "A test suite to test features that Francois library offers" LANGUAGES CXX)

target_compile_features(gtest PUBLIC cxx_std_11)
target_compile_features(gtest_main PUBLIC cxx_std_11)
target_compile_features(gmock PUBLIC cxx_std_11)
target_compile_features(gmock_main PUBLIC cxx_std_11)

macro(PACKAGE_ADD_TEST TEST_NAME)
  add_executable(${TEST_NAME} ${ARGN})
  target_include_directories(${TEST_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
  target_link_libraries(${TEST_NAME} Francois)
  target_link_libraries(${TEST_NAME} gtest gmock gtest_main)
  add_test(${TEST_NAME} ${TEST_NAME})
  set_target_properties(${TEST_NAME} PROPERTIES FOLDER tests)
endmacro()

#Matrix test suite
PACKAGE_ADD_TEST(algebra_Matrix_SanityTests _matrix/algebra_Matrix_SanityTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_AnalyticalTests _matrix/algebra_Matrix_AnalyticalTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_OperationsTests _matrix/algebra_Matrix_OperationsTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_UtilityTests _matrix/algebra_Matrix_UtilityTests.cpp)

#Determinant test suite
PACKAGE_ADD_TEST(algebra_Determinant_SanityTests _determinant/algebra_Determinant_SanityTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_AnalyticalTests _determinant/algebra_Determinant_AnalyticalTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_OperationsTests _determinant/algebra_Determinant_OperationsTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_UtilityTests _determinant/algebra_Determinant_UtilityTests.cpp)
