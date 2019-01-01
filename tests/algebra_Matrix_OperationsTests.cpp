#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixOperationsTests,canAddTwoMatrices)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
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
    {21,24,26,28},
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

TEST(MatrixOperationsTests, canPerformOtherMatrixOperations)
{
  FAIL() << "Not Implemnted";
}