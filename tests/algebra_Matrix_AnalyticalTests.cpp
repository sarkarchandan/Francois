#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(DefineRowMatrix, canDefineRowMatrix)
{
  algebra::Matrix<int> testableIntRowMatrix {
    {5,1,4,7,8}
  };
  ASSERT_TRUE(testableIntRowMatrix.IsRowMatrix());

  algebra::Matrix<int> testableIntMatrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(testableIntMatrix.IsRowMatrix());
}

TEST(DefineColumnMatrix, canDefineColumnMatrix)
{
  algebra::Matrix<int>  testableIntColumnMatrix {
    {5},
    {1},
    {4},
    {7},
    {8}
  };
  ASSERT_TRUE(testableIntColumnMatrix.IsColumnMatrix());

  algebra::Matrix<int> testableIntMatrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(testableIntMatrix.IsColumnMatrix());
}

TEST(DefineRectangularMatrix, canDefineRectangularMatrix)
{
  algebra::Matrix<int> testableIntRectangularMatrix {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_TRUE(testableIntRectangularMatrix.IsRectangularMatrix());

  algebra::Matrix<int> testableIntMatrix {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_FALSE(testableIntMatrix.IsRectangularMatrix());
}

TEST(DefineSquareMatrix, canDefineSquareMatrix)
{
  algebra::Matrix<int> testableIntSquareMatrix {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_TRUE(testableIntSquareMatrix.IsSquareMatrix());

  algebra::Matrix<int> testableIntMatrix {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(testableIntMatrix.IsSquareMatrix());
}