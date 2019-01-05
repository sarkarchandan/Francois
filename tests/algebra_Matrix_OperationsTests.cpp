#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixOperationsTests,canAddTwoMatrices)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  const algebra::Matrix<int> sumOfIntMatrices = givenMatrix1 + givenMatrix2;
  const algebra::Matrix<int> testableMatrix1 {
    {14,16,18,20},
    {22,24,26,28},
    {30,32,34,36}
  };
  ASSERT_TRUE(sumOfIntMatrices == testableMatrix1);
}

TEST(MatrixOperationsTests_ExceptionTest, canThrowExceptionForAdditionOfMatricesWithDifferentOrder)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 {
    {13,14,15},
    {17,18,19},
    {21,22,23}
  };
  EXPECT_THROW((givenMatrix1 + givenMatrix2),std::invalid_argument);
}

TEST(MatrixOperationsTests, canSubtractOneMatrixFromOther)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };

  const algebra::Matrix<int> differenceOfTwoMatrices = givenMatrix1 - givenMatrix2;
  const algebra::Matrix<int> testableMatrix1 {
    {-12,-12,-12,-12},
    {-12,-12,-12,-12},
    {-12,-12,-12,-12}
  };
  ASSERT_TRUE(differenceOfTwoMatrices == testableMatrix1);
}

TEST(MatrixOperationsTests, canThrowExceptionForSubtractionOfMatricesWithDifferentOrder)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 {
    {13,14,15},
    {17,18,19},
    {21,22,23}
  };
  EXPECT_THROW((givenMatrix1 - givenMatrix2),std::invalid_argument);
}

TEST(MatrixOperationsTests, canMultiplyOneMatrixWithScalar)
{
  const algebra::Matrix<int> givenMatrix1{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> matrixProduct1 = givenMatrix1 * 4;
  const algebra::Matrix<int> testableMatrix1  {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48}
  };
  ASSERT_TRUE(matrixProduct1 == testableMatrix1);

  const algebra::Matrix<double> givenMatrix2 {
    {1.3,1.4,1.5},
    {2.7,2.8,2.9},
    {3.1,3.2,3.3}
  };
  const algebra::Matrix<double> matrixProduct2 = 4.1 * givenMatrix2;
  const algebra::Matrix<double> testableMatrix2 {
    {1.3 * 4.1,1.4 * 4.1,1.5 * 4.1},
    {2.7 * 4.1,2.8 * 4.1,2.9 * 4.1},
    {3.1 * 4.1,3.2 * 4.1,3.3 * 4.1}
  };
  ASSERT_TRUE(matrixProduct2 == testableMatrix2);
}

TEST(MatrixOperationsTests, canMultiplyAMatrixWithAScalar)
{
  FAIL() << "Not Implemented";
}