#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixAnalyticalTests, canDefineRowMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {5,1,4,7,8}
  };
  ASSERT_TRUE(givenMatrix1.IsRowMatrix());

  algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(givenMatrix2.IsRowMatrix());
}

TEST(MatrixAnalyticalTests, canDefineColumnMatrix)
{
  algebra::Matrix<int>  givenMatrix1 {
    {5},
    {1},
    {4},
    {7},
    {8}
  };
  ASSERT_TRUE(givenMatrix1.IsColumnMatrix());

  algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(givenMatrix2.IsColumnMatrix());
}

TEST(MatrixAnalyticalTests, canDefineRectangularMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_TRUE(givenMatrix1.IsRectangularMatrix());

  algebra::Matrix<int> givenMatrix2 {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_FALSE(givenMatrix2.IsRectangularMatrix());
}

TEST(MatrixAnalyticalTests, canDefineSquareMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_TRUE(givenMatrix1.IsSquareMatrix());

  algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(givenMatrix2.IsSquareMatrix());
}

TEST(MatrixAnalyticalTests, canDetermineMainDiagonalElements)
{
  algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  std::vector<int> intDiagonalElements {1,6,11,16};
  ASSERT_EQ(givenMatrix1.MainDiagonalElements(),intDiagonalElements);

  algebra::Matrix<double> givenMatrix2 {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,165.76,983.1}
  };
  std::vector<double> doubleDiagonalElements {23.65,186.32,984.12,983.1};
  ASSERT_EQ(givenMatrix2.MainDiagonalElements(),doubleDiagonalElements);

  try
  {
    algebra::Matrix<int> givenMatrix3 {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
    };
    std::vector<int> diagonalElements = givenMatrix3.MainDiagonalElements();
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
}

TEST(MatrixAnalyticalTests,canDefineDiagonalMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {5,0,0,0},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_TRUE(givenMatrix1.IsDiagonalMatrix());

  algebra::Matrix<int> givenMatrix2 {
    {5,0,0,1},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_FALSE(givenMatrix2.IsDiagonalMatrix());

  algebra::Matrix<int> givenMatrix3 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(givenMatrix3.IsDiagonalMatrix());
}

TEST(MatrixAnalyticalTests,canDefineScalarMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {4,0,0,0},
    {0,4,0,0},
    {0,0,4,0},
    {0,0,0,4},
  };
  ASSERT_TRUE(givenMatrix1.IsScalarMatrix());

  algebra::Matrix<double> givenMatrix2 {
    {67.43,0,0,0},
    {0,67.43,0,0},
    {0,0,67.43,0},
    {0,0,0,67.43}
  };
  ASSERT_TRUE(givenMatrix2.IsScalarMatrix());

  algebra::Matrix<int> givenMatrix3 {
    {4,0,0,0},
    {0,4,0,0},
    {0,0,1,0},
    {0,0,0,4},
  };
  ASSERT_FALSE(givenMatrix3.IsScalarMatrix());
}

TEST(MatrixAnalyticalTests,canDefineIdentityMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
  };
  ASSERT_TRUE(givenMatrix1.IsIdentityMatrix());
  algebra::Matrix<int> givenMatrix2 {
    {1,0,0,1},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
  };
  ASSERT_FALSE(givenMatrix2.IsIdentityMatrix());
  algebra::Matrix<int> givenMatrix3 {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,1}
  };
  ASSERT_FALSE(givenMatrix3.IsIdentityMatrix());
}

TEST(MatrixAnalyticalTests,canDefineNullMatrix)
{
  algebra::Matrix<int> givenMatrix1 {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  ASSERT_TRUE(givenMatrix1.IsNullMatrix());
  algebra::Matrix<int> givenMatrix2 {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  ASSERT_TRUE(givenMatrix2.IsNullMatrix());
  algebra::Matrix<int> givenMatrix3 {
    {0,0,0,0},
    {0,0,0,2},
    {0,0,0,0}
  };
  ASSERT_FALSE(givenMatrix3.IsNullMatrix());
}