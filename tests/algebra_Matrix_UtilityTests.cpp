#include "gtest/gtest.h"
#include "Matrix.hpp"
#include <cmath>

TEST(MatrixUtilityTests, canCreateNullMatrixWithGivenOrder)
{
  const algebra::Matrix<int> testableMatrix1 = algebra::Zeros(3,4);
  const algebra::Matrix<int> expectedMatrix1 = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);

  const algebra::Matrix<int> testableMatrix2 = algebra::Zeros(1000,1000);
  const std::pair<size_t,size_t> expectedOrder = std::make_pair<size_t,size_t>(1000,1000);
  ASSERT_TRUE(testableMatrix2.Order() == expectedOrder);
}

TEST(MatrixUtilityTests, canCreateAllOnesMatrixWithGivenOrder)
{
  const algebra::Matrix<int> testableMatrix1 = algebra::Ones(3,4);
  const algebra::Matrix<int> expectedMatrix1 = {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);

  const algebra::Matrix<int> testableMatrix2 = algebra::Ones(1000,1000);
  const std::pair<size_t,size_t> expectedOrder = std::make_pair<size_t,size_t>(1000,1000);
  ASSERT_TRUE(testableMatrix2.Order() == expectedOrder);
}

TEST(MatrixUtilityTests, canCreateMatrixWithGivenOrderAndAnInteger)
{
  const algebra::Matrix<int> testableMatrix1 = algebra::Ints(4,4,5);
  const algebra::Matrix<int> expectedMatrix1 = {
    {5,5,5,5},
    {5,5,5,5},
    {5,5,5,5},
    {5,5,5,5}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);
  const algebra::Matrix<int> testableMatrix2 = algebra::Ints(1000,1000,4);
  const std::pair<size_t,size_t> expectedOrder = std::make_pair<size_t,size_t>(1000,1000);
  ASSERT_TRUE(testableMatrix2.Order() == expectedOrder);
}


TEST(MatrixUtilityTests, canProvideAForEachFunctionForMatrixRows)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::vector<algebra::Row<int>> testableRows1;
  testableRows1.reserve(3);
  testableMatrix1.For_EachRow([&](const algebra::Row<int>& _row){
    testableRows1.emplace_back(2 * _row);
  });
  const std::vector<algebra::Row<int>> expectedRows1 = {{2,4,6,8},{10,12,14,16},{18,20,22,24}};
  ASSERT_TRUE(testableRows1 == expectedRows1);

  const algebra::Matrix<double> testableMatrix2 = {
    {1.2,3.4,5.6},
    {7.8,9.10,11.12},
    {13.14,15.16,17.18}
  };
  const algebra::Row<double> rowToBeAdded = {1.1,1.2,1.3};
  std::vector<algebra::Row<double>> testableRows2;
  testableRows2.reserve(3);
  testableMatrix2.For_EachRow([&](const algebra::Row<double>& _row){
    testableRows2.emplace_back(_row + rowToBeAdded);
  });
  std::vector<algebra::Row<double>> expectedRows2 = {{1.2+1.1,3.4+1.2,5.6+1.3},{7.8+1.1,9.10+1.2,11.12+1.3},{13.14+1.1,15.16+1.2,17.18+1.3}};
  ASSERT_TRUE(testableRows2 == expectedRows2);
}

TEST(MatrixUtilityTests, canProvideAForEachFunctionForMatrixColumns)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::vector<algebra::Column<int>> testableColumns1;
  testableColumns1.reserve(4);
  testableMatrix1.For_EachColumn([&](const algebra::Column<int>& _column){
    testableColumns1.emplace_back(_column % 2);
  });
  const std::vector<algebra::Column<int>> expectedColumns1 = {{1,1,1},{0,0,0},{1,1,1},{0,0,0}};
  ASSERT_TRUE(testableColumns1 == expectedColumns1);

  const algebra::Matrix<double> testableMatrix2 = {
    {1.2,3.4,5.6},
    {7.8,9.10,11.12},
    {13.14,15.16,17.18}
  };
  const algebra::Column<double> columnToBeSubstracted = {1.1,1.2,1.3};
  std::vector<algebra::Column<double>> testableColumns2;
  testableColumns2.reserve(3);
  testableMatrix2.For_EachColumn([&](const algebra::Column<double>& _column){
    testableColumns2.emplace_back(_column - columnToBeSubstracted);
  });
  std::vector<algebra::Column<double>> expectedColumns2 = {{1.2-1.1,7.8-1.2,13.14-1.3},{3.4-1.1,9.10-1.2,15.16-1.3},{5.6-1.1,11.12-1.2,17.18-1.3}};
  ASSERT_TRUE(testableColumns2 == expectedColumns2);
}

TEST(MatrixUtilityTests, canProvideAFunctionToMapOneMatrixToAnother)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> mappedMatrix1 = testableMatrix1.Map([&](const int& _element){
    return _element * _element;
  });
  const algebra::Matrix<int> expectedMatrix1 = {
    {1,4,9,16},
    {25,36,49,64},
    {81,100,121,144}
  };
  ASSERT_TRUE(mappedMatrix1 == expectedMatrix1);

  const algebra::Matrix<double> testableMatrix2 = {
    {1.2,3.4,5.6},
    {7.8,9.10,11.12},
    {13.14,15.16,17.18}
  };
  const algebra::Matrix<double> mappedMatrix2 = testableMatrix2.Map([&](const double& _element) {
    return std::sqrt(_element);
  });
  const algebra::Matrix<double> expectedMatrix2 = {
    {std::sqrt(1.2),std::sqrt(3.4),std::sqrt(5.6)},
    {std::sqrt(7.8),std::sqrt(9.10),std::sqrt(11.12)},
    {std::sqrt(13.14),std::sqrt(15.16),std::sqrt(17.18)}
  };
  ASSERT_TRUE(mappedMatrix2 == expectedMatrix2);
}
