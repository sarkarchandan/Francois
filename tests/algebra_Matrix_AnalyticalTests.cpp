#include "gtest/gtest.h"
#include "Matrix.hpp"
#include "Helper.hpp"

TEST(MatrixAnalyticalTests, canDefineRowMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {5,1,4,7,8}
  };
  ASSERT_TRUE(givenMatrix1.IsRowMatrix());

  const algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(givenMatrix2.IsRowMatrix());
}

TEST(MatrixAnalyticalTests, canDefineColumnMatrix)
{
  const algebra::Matrix<int>  givenMatrix1 {
    {5},
    {1},
    {4},
    {7},
    {8}
  };
  ASSERT_TRUE(givenMatrix1.IsColumnMatrix());

  const algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_FALSE(givenMatrix2.IsColumnMatrix());
}

TEST(MatrixAnalyticalTests, canDefineRectangularMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_TRUE(givenMatrix1.IsRectangularMatrix());

  const algebra::Matrix<int> givenMatrix2 {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_FALSE(givenMatrix2.IsRectangularMatrix());
}

TEST(MatrixAnalyticalTests, canDefineSquareMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  ASSERT_TRUE(givenMatrix1.IsSquareMatrix());

  const algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(givenMatrix2.IsSquareMatrix());
}

TEST(MatrixAnalyticalTests, canDetermineMainDiagonalElements)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  const std::vector<int> intDiagonalElements {1,6,11,16};
  ASSERT_EQ(givenMatrix1.MainDiagonalElements(),intDiagonalElements);

  const algebra::Matrix<double> givenMatrix2 {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,165.76,983.1}
  };
  const std::vector<double> doubleDiagonalElements {23.65,186.32,984.12,983.1};
  ASSERT_EQ(givenMatrix2.MainDiagonalElements(),doubleDiagonalElements);
  
  #pragma mark TODO: Refactor with ASSERT_EXIT and ASSERT_DEATH
  try
  {
    const algebra::Matrix<int> givenMatrix3 {
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
  const algebra::Matrix<int> givenMatrix1 {
    {5,0,0,0},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_TRUE(givenMatrix1.IsDiagonalMatrix());

  const algebra::Matrix<int> givenMatrix2 {
    {5,0,0,1},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  ASSERT_FALSE(givenMatrix2.IsDiagonalMatrix());

  const algebra::Matrix<int> givenMatrix3 {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  ASSERT_FALSE(givenMatrix3.IsDiagonalMatrix());
}

TEST(MatrixAnalyticalTests,canDefineScalarMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {4,0,0,0},
    {0,4,0,0},
    {0,0,4,0},
    {0,0,0,4},
  };
  ASSERT_TRUE(givenMatrix1.IsScalarMatrix());

  const algebra::Matrix<double> givenMatrix2 {
    {67.43,0,0,0},
    {0,67.43,0,0},
    {0,0,67.43,0},
    {0,0,0,67.43}
  };
  ASSERT_TRUE(givenMatrix2.IsScalarMatrix());

  const algebra::Matrix<int> givenMatrix3 {
    {4,0,0,0},
    {0,4,0,0},
    {0,0,1,0},
    {0,0,0,4},
  };
  ASSERT_FALSE(givenMatrix3.IsScalarMatrix());
}

TEST(MatrixAnalyticalTests,canDefineIdentityMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
  };
  ASSERT_TRUE(givenMatrix1.IsIdentityMatrix());
  const algebra::Matrix<int> givenMatrix2 {
    {1,0,0,1},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
  };
  ASSERT_FALSE(givenMatrix2.IsIdentityMatrix());
  const algebra::Matrix<int> givenMatrix3 {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,1}
  };
  ASSERT_FALSE(givenMatrix3.IsIdentityMatrix());
}

TEST(MatrixAnalyticalTests,canDefineNullMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  ASSERT_TRUE(givenMatrix1.IsNullMatrix());
  const algebra::Matrix<int> givenMatrix2 {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  ASSERT_TRUE(givenMatrix2.IsNullMatrix());
  const algebra::Matrix<int> givenMatrix3 {
    {0,0,0,0},
    {0,0,0,2},
    {0,0,0,0}
  };
  ASSERT_FALSE(givenMatrix3.IsNullMatrix());
}

TEST(MatrixAnalyticalTests,canDefineUppertriangularMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {4,5,8,1},
    {0,6,7,1},
    {0,0,2,9},
    {0,0,0,8}
  };
  ASSERT_TRUE(givenMatrix1.IsUpperTriangularMatrix());

  const algebra::Matrix<double> givenMatrix2 {
    {98.1,50.32,98.1,16.43},
    {0,61.09,7,23.54},
    {0,0,98.1,12.09},
    {0,0,0,90.1}
  };
  ASSERT_TRUE(givenMatrix2.IsUpperTriangularMatrix());

  const algebra::Matrix<int> givenMatrix3 {
    {4,5,8,1},
    {0,6,7,1},
    {0,0,2,9},
    {1,0,0,8}
  };
  ASSERT_FALSE(givenMatrix3.IsUpperTriangularMatrix());

  const algebra::Matrix<int> givenMatrix4 {
    {4,5,8,1,5},
    {0,6,7,1,8},
    {0,0,2,9,9},
    {0,0,0,8,1}
  };
  ASSERT_FALSE(givenMatrix4.IsUpperTriangularMatrix());
}

TEST(MatrixAnalyticalTests,canDefineLowerTriangularMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {4,0,0,0},
    {1,6,0,0},
    {9,6,2,0},
    {3,5,8,8}
  };
  ASSERT_TRUE(givenMatrix1.IsLowerTriangularMatrix());

  const algebra::Matrix<double> givenMatrix2 {
    {98.1,0,0,0},
    {54.12,61.09,0,0},
    {87.13,54.89,98.1,0},
    {123.5,89.67,87.12,90.1}
  };
  ASSERT_TRUE(givenMatrix2.IsLowerTriangularMatrix());

  const algebra::Matrix<int> givenMatrix3 {
    {4,0,0,1},
    {6,6,0,0},
    {1,9,2,0},
    {8,4,2,8}
  };
  ASSERT_FALSE(givenMatrix3.IsLowerTriangularMatrix());

  const algebra::Matrix<int> givenMatrix4 {
    {4,5,8,1,5},
    {0,6,7,1,8},
    {0,0,2,9,9},
    {0,0,0,8,1}
  };
  ASSERT_FALSE(givenMatrix4.IsLowerTriangularMatrix());
}

TEST(MatrixAnalyticalTests,canDefineTriangularMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {4,5,8,1},
    {0,6,7,1},
    {0,0,2,9},
    {0,0,0,8}
  };
  ASSERT_TRUE(givenMatrix1.IsTriangularMatrix());

  const algebra::Matrix<double> givenMatrix2 {
    {98.1,50.32,98.1,16.43},
    {0,61.09,7,23.54},
    {0,0,98.1,12.09},
    {0,0,0,90.1}
  };
  ASSERT_TRUE(givenMatrix2.IsTriangularMatrix());

  const algebra::Matrix<int> givenMatrix3 {
    {4,0,0,0},
    {1,6,0,0},
    {9,6,2,0},
    {3,5,8,8}
  };
  ASSERT_TRUE(givenMatrix3.IsTriangularMatrix());

  const algebra::Matrix<double> givenMatrix4 {
    {98.1,0,0,0},
    {54.12,61.09,0,0},
    {87.13,54.89,98.1,0},
    {123.5,89.67,87.12,90.1}
  };
  ASSERT_TRUE(givenMatrix4.IsTriangularMatrix());
  
  const algebra::Matrix<int> givenMatrix5 {
    {1,2,0,0},
    {9,6,4,1},
    {4,1,6,1},
    {0,0,3,4}
  };
  ASSERT_FALSE(givenMatrix5.IsTriangularMatrix());
}

TEST(MatrixAnalyticalTests,canDetermineTraceOfSquareMatrix)
{
  const algebra::Matrix<int> givenMatrix1 {
    {4,6,8,10},
    {3,5,7,9},
    {8,5,3,6},
    {2,0,5,1}
  };
  const int matrix1_Trace = givenMatrix1.Trace();
  const int expected_Matrix1_Trace = (4+5+3+1);
  ASSERT_EQ(matrix1_Trace,expected_Matrix1_Trace);

  const algebra::Matrix<double> givenMatrix2 {
    {56.12,0,78.92,19.23},
    {97.12,42.18,29.4,18.98},
    {89.43,12.98,76.12,78.19},
    {0,74.89,86.12,19.56}
  };
  const double matrix2_Trace = givenMatrix2.Trace();
  const double expected_Matrix2_Trace = (56.12+42.18+76.12+19.56);
  ASSERT_DOUBLE_EQ(matrix2_Trace,expected_Matrix2_Trace);

  #pragma mark TODO: Refactor with ASSERT_EXIT and ASSERT_DEATH
  const algebra::Matrix<int> givenMatrix3 {
    {1,2,3,4},
    {5,6,7,8},
    {9,8,5,1}
  };
  try
  {
    const int matrix3_Trace = givenMatrix3.Trace();
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
}

TEST(MatrixAnalyticalTests,canDefineEqualityOfMatrices)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  const algebra::Matrix<int> givenMatrix2 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  const algebra::Matrix<int> givenMatrix3 {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,13,12},
    {13,14,15,16}
  };
  ASSERT_TRUE(givenMatrix1 == givenMatrix2);
  ASSERT_TRUE(givenMatrix1 != givenMatrix3);

  const algebra::Matrix<double> givenMatrix4 {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,165.76,983.1}
  };
  const algebra::Matrix<double> givenMatrix5 {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,165.76,983.1}
  };
  const algebra::Matrix<double> givenMatrix6 {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,164.76,983.1}
  };
  ASSERT_TRUE(givenMatrix4 == givenMatrix5);
  ASSERT_TRUE(givenMatrix4 != givenMatrix6);
}
