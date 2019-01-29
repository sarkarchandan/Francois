cmake_minimum_required(VERSION 3.1...3.13)
if(${CMAKE_VERSION} VERSION_LESS 3.13)
  cmake_policy(VERSION  ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(FrancoisTestSuite VERSION 1.0 DESCRIPTION "Francois test suite" LANGUAGES CXX)

mark_as_advanced(
  BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
  gmock_build_tests gmock_build_samples gtest_build_tests
  gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

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

PACKAGE_ADD_TEST(algebra_Matrix_SanityTests algebra_Matrix_SanityTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_AnalyticalTests algebra_Matrix_AnalyticalTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_OperationsTests algebra_Matrix_OperationsTests.cpp)
PACKAGE_ADD_TEST(algebra_Matrix_UtilityTests algebra_Matrix_UtilityTests.cpp)

PACKAGE_ADD_TEST(algebra_Determinant_SanityTests algebra_Determinant_SanityTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_AnalyticalTests algebra_Determinant_AnalyticalTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_OperationsTests algebra_Determinant_OperationsTests.cpp)
PACKAGE_ADD_TEST(algebra_Determinant_UtilityTests algebra_Determinant_UtilityTests.cpp)
