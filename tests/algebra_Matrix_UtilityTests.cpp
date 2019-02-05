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
  const algebra::Matrix<int> testableMappedMatrix1 = testableMatrix1.Map([&](const int& _element){
    return _element * _element;
  });
  const algebra::Matrix<int> expectedMatrix1 = {
    {1,4,9,16},
    {25,36,49,64},
    {81,100,121,144}
  };
  ASSERT_TRUE(testableMappedMatrix1 == expectedMatrix1);

  const algebra::Matrix<double> testableMatrix2 = {
    {1.2,3.4,5.6},
    {7.8,9.10,11.12},
    {13.14,15.16,17.18}
  };
  const algebra::Matrix<double> testableMappedMatrix2 = testableMatrix2.Map([&](const double& _element) {
    return std::sqrt(_element);
  });
  const algebra::Matrix<double> expectedMatrix2 = {
    {std::sqrt(1.2),std::sqrt(3.4),std::sqrt(5.6)},
    {std::sqrt(7.8),std::sqrt(9.10),std::sqrt(11.12)},
    {std::sqrt(13.14),std::sqrt(15.16),std::sqrt(17.18)}
  };
  ASSERT_TRUE(testableMappedMatrix2 == expectedMatrix2);

  const algebra::Matrix<int> testableMatrix3 = {
    {1,2,4,0},
    {3,3,0,1},
    {6,2,8,1},
    {2,7,0,5}
  };
  const algebra::Matrix<int> testableNegativeMatrix3 = testableMatrix3.Map([&](const int& _element){
    return -_element;
  });
  const algebra::Matrix<int> expectedNegativeMatrix3 = {
    {-1,-2,-4,0},
    {-3,-3,0,-1},
    {-6,-2,-8,-1},
    {-2,-7,0,-5}
  };
  ASSERT_TRUE(testableNegativeMatrix3 == expectedNegativeMatrix3);
}

TEST(MatrixUtilityTests, canUnwrapMatrixToArray)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const size_t expectedLength1 = givenMatrix1.Order().first * givenMatrix1.Order().second;
  int *outcomeArray1 = new int[expectedLength1];
  algebra::MatrixToArray(givenMatrix1,algebra::ExpansionType::E_AlongRow,outcomeArray1);
  const int expectedArray1[] = {1,2,3,4,5,6,7,8,9};
  for(size_t _index = 0; _index < expectedLength1; _index+= 1)
  {
    ASSERT_EQ(*(expectedArray1 + _index),*(outcomeArray1 + _index));
  }
  delete []outcomeArray1;

  const algebra::Matrix<int> givenMatrix2 = {
    {1,2,3,4,5,6},
    {7,8,9,10,11,12},
    {13,14,15,16,17,18}
  };
  const size_t expectedLength2 = givenMatrix2.Order().first * givenMatrix2.Order().second;
  int *outcomeArray2 = new int[expectedLength2];
  algebra::MatrixToArray(givenMatrix2,algebra::ExpansionType::E_AlongColumn,outcomeArray2);
  const int expectedArray2[] = {1,7,13,2,8,14,3,9,15,4,10,16,5,11,17,6,12,18};
  for(size_t _index = 0; _index < expectedLength2; _index += 1)
  {
    ASSERT_EQ(*(expectedArray2 + _index),*(outcomeArray2 + _index));
  }
  delete []outcomeArray2;

  const algebra::Matrix<double> givenMatrix3 = {
    {3.7,9.3,4.3,6.6},
    {9.3,1.2,1.2,4.3},
    {5.1,3.1,1.1,9.3},
    {2.3,5.1,9.3,3.7}
  };
  const size_t expectedLength3 = givenMatrix3.Order().first * givenMatrix3.Order().second;
  double *outcomeArray3 = new double[expectedLength3];
  algebra::MatrixToArray(givenMatrix3,algebra::ExpansionType::E_AlongColumn,outcomeArray3);
  const double expectedArray3[] = {3.7,9.3,5.1,2.3,9.3,1.2,3.1,5.1,4.3,1.2,1.1,9.3,6.6,4.3,9.3,3.7};
  for(size_t _index = 0; _index < expectedLength3; _index+= 1)
  {
    ASSERT_DOUBLE_EQ(*(expectedArray3 + _index),*(outcomeArray3 + _index));
  }
  delete []outcomeArray3;
}

TEST(MatrixUtilityTests, canWrapArrayToMatrix)
{
  const int givenArray1[] = {1,2,3,4,5,6,7,8,9};
  const size_t givenArrayLength1 = sizeof(givenArray1)/sizeof(int);
  const std::pair<size_t,size_t> intendedMatrixOrder1 = std::make_pair<size_t,size_t>(3,3);
  const algebra::Matrix<int> outcomeMatrix1 = algebra::ArrayToMatrix(givenArray1,givenArrayLength1,algebra::ContractionType::C_AlongRow,intendedMatrixOrder1);
  const algebra::Matrix<int> outcomeMatrix2 = algebra::ArrayToMatrix(givenArray1,givenArrayLength1,algebra::ContractionType::C_AlongColumn,intendedMatrixOrder1);
  const algebra::Matrix<int> expectedMatrix1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const algebra::Matrix<int> expectedMatrix2 = {
    {1,4,7},
    {2,5,8},
    {3,6,9}
  };
  ASSERT_TRUE(outcomeMatrix1 == expectedMatrix1);
  ASSERT_TRUE(outcomeMatrix2 == expectedMatrix2);

  const int givenArray2[] = {1,7,13,2,8,14,3,9,15,4,10,16,5,11,17,6,12,18};
  const size_t givenArrayLength2 = sizeof(givenArray2) / sizeof(int);
  const std::pair<size_t,size_t> intendedMatrixOrder2 = std::make_pair<size_t,size_t>(3,6);
  const std::pair<size_t,size_t> intendedMatrixOrder3 = std::make_pair<size_t,size_t>(6,3);
  const algebra::Matrix<int> outcomeMatrix3 = algebra::ArrayToMatrix(givenArray2,givenArrayLength2,algebra::ContractionType::C_AlongRow,intendedMatrixOrder2);
  const algebra::Matrix<int> outcomeMatrix4 = algebra::ArrayToMatrix(givenArray2,givenArrayLength2,algebra::ContractionType::C_AlongColumn,intendedMatrixOrder3);
  const algebra::Matrix<int> expectedMatrix3 = {
    {1,7,13,2,8,14},
    {3,9,15,4,10,16},
    {5,11,17,6,12,18}
  };
  const algebra::Matrix<int> expectedMatrix4 = {
    {1,3,5},
    {7,9,11},
    {13,15,17},
    {2,4,6},
    {8,10,12},
    {14,16,18}
  };
  ASSERT_TRUE(outcomeMatrix3 == expectedMatrix3);
  ASSERT_TRUE(outcomeMatrix4 == expectedMatrix4);

  const double givenArray3[] = {3.7,9.3,5.1,2.3,9.3,1.2,3.1,5.1,4.3,1.2,1.1,9.3,6.6,4.3,9.3,3.7};
  const size_t givenArrayLength3 = sizeof(givenArray3) / sizeof(double);
  const std::pair<size_t,size_t> intendedMatrixOrder4 = std::make_pair<size_t,size_t>(4,4);
  const algebra::Matrix<double> outcomeMatrix5 = algebra::ArrayToMatrix(givenArray3,givenArrayLength3,algebra::ContractionType::C_AlongRow,intendedMatrixOrder4);
  const algebra::Matrix<double> outcomeMatrix6 = algebra::ArrayToMatrix(givenArray3,givenArrayLength3,algebra::ContractionType::C_AlongColumn,intendedMatrixOrder4);
  const algebra::Matrix<double> expectedMatrix5 = {
    {3.7,9.3,5.1,2.3},
    {9.3,1.2,3.1,5.1},
    {4.3,1.2,1.1,9.3},
    {6.6,4.3,9.3,3.7}
  };
  const algebra::Matrix<double> expectedMatrix6 = {
    {3.7,9.3,4.3,6.6},
    {9.3,1.2,1.2,4.3},
    {5.1,3.1,1.1,9.3},
    {2.3,5.1,9.3,3.7}
  };
  ASSERT_TRUE(outcomeMatrix5 == expectedMatrix5);
  ASSERT_TRUE(outcomeMatrix6 == expectedMatrix6);
}

TEST(MatrixUtilityTests_ExceptionTest, canNotWrapArrayToMatrixWhenArrayLengthAndIntendedOrderAreIncompatible)
{
  const int givenArray1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  const size_t givenArrayLength1 = sizeof(givenArray1) / sizeof(int);
  const std::pair<size_t,size_t> intendedOrder1 = std::make_pair<size_t,size_t>(4,4);
  EXPECT_THROW(algebra::ArrayToMatrix(givenArray1,givenArrayLength1,algebra::ContractionType::C_AlongRow,intendedOrder1),std::length_error);
}

TEST(MatrixUtilityTests, canUnwrapMatrixToVector)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const std::vector<int> computedVector1 = algebra::MatrixToVector(givenMatrix1,algebra::ExpansionType::E_AlongRow);
  const std::vector<int> expectedVector1 = {1,2,3,4,5,6,7,8,9};
  ASSERT_TRUE(computedVector1 == expectedVector1);

  const algebra::Matrix<int> givenMatrix2 = {
    {1,2,3,4,5,6},
    {7,8,9,10,11,12},
    {13,14,15,16,17,18}
  };
  const std::vector<int> computedVector2 = algebra::MatrixToVector(givenMatrix2,algebra::ExpansionType::E_AlongColumn);
  const std::vector<int> expectedVector2 = {1,7,13,2,8,14,3,9,15,4,10,16,5,11,17,6,12,18};
  ASSERT_TRUE(computedVector2 == expectedVector2);

  const algebra::Matrix<double> givenMatrix3 = {
    {3.7,9.3,4.3,6.6},
    {9.3,1.2,1.2,4.3},
    {5.1,3.1,1.1,9.3},
    {2.3,5.1,9.3,3.7}
  };
  const std::vector<double> computedVector3 = algebra::MatrixToVector(givenMatrix3,algebra::ExpansionType::E_AlongColumn);
  const std::vector<double> expectedVector3 = {3.7,9.3,5.1,2.3,9.3,1.2,3.1,5.1,4.3,1.2,1.1,9.3,6.6,4.3,9.3,3.7};
  ASSERT_TRUE(computedVector3 == expectedVector3);
}
