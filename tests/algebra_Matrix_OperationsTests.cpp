#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixOperationsTests, canAddTwoRows)
{
  const algebra::Row<int> givenRow1 = {1,2,3,4};
  const algebra::Row<int> givenRow2 = {5,6,7,8};
  const algebra::Row<int> sumOfIntRows = givenRow1 + givenRow2;
  const algebra::Row<int> testableRow1 = {6,8,10,12};
  ASSERT_TRUE(sumOfIntRows == testableRow1);

  const algebra::Row<double> givenRow3 = {198.43,12.87,164.76,983.1};
  const algebra::Row<double> givenRow4 = {98.123,76.12,984.12,12.98};
  const algebra::Row<double> sumOfDoubleRows = givenRow3 + givenRow4;
  const algebra::Row<double> testableRow2 = {(198.43+98.123),(12.87+76.12),(164.76+984.12),(983.1+12.98)};
  ASSERT_TRUE(sumOfDoubleRows == testableRow2);
}

TEST(MatrixOperationsTests, canAddTwoColumns)
{
  const algebra::Column<int> givenColumn1 = {1,2,3,4};
  const algebra::Column<int> givenColumn2 = {5,6,7,8};
  const algebra::Column<int> sumOfIntColumns = givenColumn1 + givenColumn2;
  const algebra::Column<int> testableColumn1 = {6,8,10,12};
  ASSERT_TRUE(sumOfIntColumns == testableColumn1);

  const algebra::Column<double> givenColumn3 = {198.43,12.87,164.76,983.1};
  const algebra::Column<double> givenColumn4 = {98.123,76.12,984.12,12.98};
  const algebra::Column<double> sumOfDoubleColumns = givenColumn3 + givenColumn4;
  const algebra::Column<double> testableColumn2 = {(198.43+98.123),(12.87+76.12),(164.76+984.12),(983.1+12.98)};
  ASSERT_TRUE(sumOfDoubleColumns == testableColumn2);
}

TEST(MatrixOperationsTests, canSubtractTwoRows)
{
  const algebra::Row<int> givenRow1 = {1,2,3,4};
  const algebra::Row<int> givenRow2 = {5,6,7,8};
  const algebra::Row<int> differenceOfTwoRows = givenRow1 - givenRow2;
  const algebra::Row<int> testableRow1 = {-4,-4,-4,-4};
  ASSERT_TRUE(differenceOfTwoRows == testableRow1);

  const algebra::Row<double> givenRow3 = {198.43,12.87,164.76,983.1};
  const algebra::Row<double> givenRow4 = {98.123,76.12,984.12,12.98};
  const algebra::Row<double> differenceOfDoubleRows = givenRow3 - givenRow4;
  const algebra::Row<double> testableRow2 = {198.43-98.123,12.87-76.12,164.76-984.12,983.1-12.98};
  ASSERT_TRUE(differenceOfDoubleRows == testableRow2);
}

TEST(MatrixOperationsTests, canSubtractTwoColumns)
{
  const algebra::Column<int> givenColumn1 = {1,2,3,4};
  const algebra::Column<int> givenColumn2 = {5,6,7,8};
  const algebra::Column<int> differenceOfTwoColumns = givenColumn1 - givenColumn2;
  const algebra::Column<int> testableColumn1 = {-4,-4,-4,-4};
  ASSERT_TRUE(differenceOfTwoColumns == testableColumn1);

  const algebra::Column<double> givenColumn3 = {198.43,12.87,164.76,983.1};
  const algebra::Column<double> givenColumn4 = {98.123,76.12,984.12,12.98};
  const algebra::Column<double> differenceOfDoubleColumns = givenColumn3 - givenColumn4;
  const algebra::Column<double> testableColumn2 = {198.43-98.123,12.87-76.12,164.76-984.12,983.1-12.98};
  ASSERT_TRUE(differenceOfDoubleColumns == testableColumn2);
}

TEST(MatrixOperationsTests, canMultiplyRowWithScalar)
{
  const algebra::Row<int> testableRow1 = {1,2,3,4};
  const algebra::Row<int> computedIntProduct = 3 * testableRow1;
  const algebra::Row<int> expectedIntRow = {3,6,9,12};
  ASSERT_TRUE(computedIntProduct == expectedIntRow);

  const algebra::Row<double> testableRow2 = {198.43,12.87,164.76,983.1};
  const algebra::Row<double> computedDoubleProduct = testableRow2 * 3.0;
  const algebra::Row<double> expectedDoubleRow = {198.43*3.0,12.87*3.0,164.76*3.0,983.1*3.0};
  ASSERT_TRUE(computedDoubleProduct == expectedDoubleRow);
}

TEST(MatrixOperationsTests, canMultiplyColumnWithScalar)
{
  const algebra::Column<int> testableColumn1 = {1,2,3,4};
  const algebra::Column<int> computedIntProduct = 3 * testableColumn1;
  const algebra::Column<int> expectedIntColumn = {3,6,9,12};
  ASSERT_TRUE(computedIntProduct == expectedIntColumn);

  const algebra::Column<double> testableColumn2 = {198.43,12.87,164.76,983.1};
  const algebra::Column<double> computedDoubleProduct = testableColumn2 * 3.0;
  const algebra::Column<double> expectedDoubleColumn = {198.43*3.0,12.87*3.0,164.76*3.0,983.1*3.0};
  ASSERT_TRUE(computedDoubleProduct == expectedDoubleColumn);
}

TEST(MatrixOperationsTests,canAddTwoMatrices)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  const algebra::Matrix<int> sumOfIntMatrices = givenMatrix1 + givenMatrix2;
  const algebra::Matrix<int> testableMatrix1 = {
    {14,16,18,20},
    {22,24,26,28},
    {30,32,34,36}
  };
  ASSERT_TRUE(sumOfIntMatrices == testableMatrix1);
}

TEST(MatrixOperationsTests_ExceptionTest, canThrowExceptionForAdditionOfMatricesWithDifferentOrder)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 = {
    {13,14,15},
    {17,18,19},
    {21,22,23}
  };
  EXPECT_THROW((givenMatrix1 + givenMatrix2),std::invalid_argument);
}

TEST(MatrixOperationsTests, canSubtractOneMatrixFromOther)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };

  const algebra::Matrix<int> differenceOfTwoMatrices = givenMatrix1 - givenMatrix2;
  const algebra::Matrix<int> testableMatrix1 = {
    {-12,-12,-12,-12},
    {-12,-12,-12,-12},
    {-12,-12,-12,-12}
  };
  ASSERT_TRUE(differenceOfTwoMatrices == testableMatrix1);
}

TEST(MatrixOperationsTests, canThrowExceptionForSubtractionOfMatricesWithDifferentOrder)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> givenMatrix2 = {
    {13,14,15},
    {17,18,19},
    {21,22,23}
  };
  EXPECT_THROW((givenMatrix1 - givenMatrix2),std::invalid_argument);
}

TEST(MatrixOperationsTests, canMultiplyOneMatrixWithScalar)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> matrixProduct1 = givenMatrix1 * 4;
  const algebra::Matrix<int> testableMatrix1 = {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48}
  };
  ASSERT_TRUE(matrixProduct1 == testableMatrix1);

  const algebra::Matrix<double> givenMatrix2 = {
    {1.3,1.4,1.5},
    {2.7,2.8,2.9},
    {3.1,3.2,3.3}
  };
  const algebra::Matrix<double> matrixProduct2 = 4.1 * givenMatrix2;
  const algebra::Matrix<double> testableMatrix2 = {
    {1.3 * 4.1,1.4 * 4.1,1.5 * 4.1},
    {2.7 * 4.1,2.8 * 4.1,2.9 * 4.1},
    {3.1 * 4.1,3.2 * 4.1,3.3 * 4.1}
  };
  ASSERT_TRUE(matrixProduct2 == testableMatrix2);
}

TEST(MatrixOperationsTests, canOperateOnMatrix)
{
  FAIL() << "Not Implemented";
}