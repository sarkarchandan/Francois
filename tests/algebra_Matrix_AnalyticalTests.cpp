#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixAnalyticalTests, canDefineRowMatrix)
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

TEST(MatrixAnalyticalTests, canDefineColumnMatrix)
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

TEST(MatrixAnalyticalTests, canDefineRectangularMatrix)
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

TEST(MatrixAnalyticalTests, canDefineSquareMatrix)
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

TEST(MatrixAnalyticalTests, canDetermineMainDiagonalElements)
{
  algebra::Matrix<int> testableIntSquareMatrix {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  std::vector<int> intDiagonalElements {1,6,11,16};
  ASSERT_EQ(testableIntSquareMatrix.MainDiagonalElements(),intDiagonalElements);

  algebra::Matrix<double> testableDoubleSquareMatrix {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,165.76,983.1}
  };
  std::vector<double> doubleDiagonalElements {23.65,186.32,984.12,983.1};
  ASSERT_EQ(testableDoubleSquareMatrix.MainDiagonalElements(),doubleDiagonalElements);

  try
  {
    algebra::Matrix<int> testableIntRectangularMatrix {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
    };
    std::vector<int> diagonalElements = testableIntRectangularMatrix.MainDiagonalElements();
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
}

TEST(MatrixAnalyticalTests,canDefineDiagonalMatrix)
{
  algebra::Matrix<int> testableIntDiagonalMatrix {
    {5,0,0,0},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_TRUE(testableIntDiagonalMatrix.IsDiagonalMatrix());

  algebra::Matrix<int> testableIntSquareMatrix {
    {5,0,0,1},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_FALSE(testableIntSquareMatrix.IsDiagonalMatrix());

  algebra::Matrix<int> testableIntRectangularMatrix {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(testableIntRectangularMatrix.IsDiagonalMatrix());
}