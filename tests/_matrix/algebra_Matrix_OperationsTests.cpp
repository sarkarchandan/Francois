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

TEST(MatrixOperationsTests, canAddAScalarToEachElementOfRow)
{
  const algebra::Row<int> testableRow1 = {1,2,3,4};
  const algebra::Row<int> computedIntSum1 = 3 + testableRow1;
  const algebra::Row<int> expectedIntRow = {4,5,6,7};
  ASSERT_TRUE(computedIntSum1 == expectedIntRow);

  const algebra::Row<double> testableRow2 = {4.1,3.2,2.1,1.0};
  const algebra::Row<double> computedIntSum2 = testableRow2 + 1.1;
  const algebra::Row<double> expectedDoubleRow = {4.1+1.1,3.2+1.1,2.1+1.1,1.0+1.1};
  ASSERT_TRUE(computedIntSum2 == expectedDoubleRow);
}

TEST(MatrixOperationsTests, canAddAScalarToEachElementOfColumn)
{
  const algebra::Column<int> testableColumn1 = {1,2,3,4};
  const algebra::Column<int> computedIntSum1 = 3 + testableColumn1;
  const algebra::Column<int> expectedIntColumn = {4,5,6,7};
  ASSERT_TRUE(computedIntSum1 == expectedIntColumn);

  const algebra::Column<double> testableColumn2 = {4.1,3.2,2.1,1.0};
  const algebra::Column<double> computedIntSum2 = testableColumn2 + 1.1;
  const algebra::Column<double> expectedDoubleColumn = {4.1+1.1,3.2+1.1,2.1+1.1,1.0+1.1};
  ASSERT_TRUE(computedIntSum2 == expectedDoubleColumn);
}

TEST(MatrixOperationsTests, canSubtractAScalarFromEachElementOfRow)
{
  const algebra::Row<int> testableRow1 = {1,2,3,4};
  const algebra::Row<int> computedIntDifference1 = 3 - testableRow1;
  const algebra::Row<int> expectedIntRow = {3-1,3-2,3-3,3-4};
  ASSERT_TRUE(computedIntDifference1 == expectedIntRow);

  const algebra::Row<double> testableRow2 = {4.1,3.2,2.1,1.0};
  const algebra::Row<double> computedIntDifference2 = testableRow2 - 1.1;
  const algebra::Row<double> expectedDoubleRow = {4.1-1.1,3.2-1.1,2.1-1.1,1.0-1.1};
  ASSERT_TRUE(computedIntDifference2 == expectedDoubleRow);
}

TEST(MatrixOperationsTests, canSubtractAScalarFromEachElementOfColumn)
{
  const algebra::Column<int> testableColumn1 = {1,2,3,4};
  const algebra::Column<int> computedIntDifference1 = 3 - testableColumn1;
  const algebra::Column<int> expectedIntColumn = {3-1,3-2,3-3,3-4};
  ASSERT_TRUE(computedIntDifference1 == expectedIntColumn);

  const algebra::Column<double> testableColumn2 = {4.1,3.2,2.1,1.0};
  const algebra::Column<double> computedIntDifference2 = testableColumn2 - 1.1;
  const algebra::Column<double> expectedDoubleColumn = {4.1-1.1,3.2-1.1,2.1-1.1,1.0-1.1};
  ASSERT_TRUE(computedIntDifference2 == expectedDoubleColumn);
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

TEST(MatrixOperationsTests, canDetermineIfTwoMatricesAreMultipliable)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48}
  };
  const algebra::Matrix<int> testableMatrix2 = {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48}
  };
  ASSERT_FALSE(testableMatrix1.IsMultipliableWith(testableMatrix2));

  const algebra::Matrix<int> testableMatrix3 = {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48}
  };
  const algebra::Matrix<int> testableMatrix4 = {
    {4,8,12,16},
    {20,24,28,32},
    {36,40,44,48},
    {5,23,12,56}
  };
  ASSERT_TRUE(testableMatrix3.IsMultipliableWith(testableMatrix4));

  const algebra::Matrix<double> testableMatrix5 = {
    {13.76,56.12,19.87,78.12}
  };
  const algebra::Matrix<double> testableMatrix6 = {
    {78.12},
    {19.87},
    {56.12},
    {13.76}
  };
  ASSERT_TRUE(testableMatrix5.IsMultipliableWith(testableMatrix6));
}

TEST(MatrixOperationsTests, canMultiplyTwoMatrices)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> testableMatrix2 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  const algebra::Matrix<int> testableProductMatrix1 = testableMatrix1 * testableMatrix2;
  const algebra::Matrix<int> expectedProductMatrix1 = {
    {(1*1)+(2*5)+(3*9)+(4*13),(1*2)+(2*6)+(3*10)+(4*14),(1*3)+(2*7)+(3*11)+(4*15),(1*4)+(2*8)+(3*12)+(4*16)},
    {(5*1)+(6*5)+(7*9)+(8*13),(5*2)+(6*6)+(7*10)+(8*14),(5*3)+(6*7)+(7*11)+(8*15),(5*4)+(6*8)+(7*12)+(8*16)},
    {(9*1)+(10*5)+(11*9)+(12*13),(9*2)+(10*6)+(11*10)+(12*14),(9*3)+(10*7)+(11*11)+(12*15),(9*4)+(10*8)+(11*12)+(12*16)}
  };
  ASSERT_TRUE(testableProductMatrix1 == expectedProductMatrix1);

  const algebra::Matrix<double> testableMatrix3 = {
    {1.3,1.4,1.5},
    {2.7,2.8,2.9},
    {3.1,3.2,3.3}
  };
  const algebra::Matrix<double> testableMatrix4 = {
    {3.1,3.2,3.3},
    {2.7,2.8,2.9},
    {1.3,1.4,1.5}
  };
  const algebra::Matrix<double> testableProductMatrix2 = testableMatrix3 * testableMatrix4;
  const algebra::Matrix<double> expectedProductMatrix2 = {
    {(1.3*3.1)+(1.4*2.7)+(1.5*1.3),(1.3*3.2)+(1.4*2.8)+(1.5*1.4),(1.3*3.3)+(1.4*2.9)+(1.5*1.5)},
    {(2.7*3.1)+(2.8*2.7)+(2.9*1.3),(2.7*3.2)+(2.8*2.8)+(2.9*1.4),(2.7*3.3)+(2.8*2.9)+(2.9*1.5)},
    {(3.1*3.1)+(3.2*2.7)+(3.3*1.3),(3.1*3.2)+(3.2*2.8)+(3.3*1.4),(3.1*3.3)+(3.2*2.9)+(3.3*1.5)}
  };
  ASSERT_TRUE(testableProductMatrix2 == expectedProductMatrix2);

  const algebra::Matrix<double> testableMatrix5 = {
    {13.76,56.12,19.87,78.12}
  };
  const algebra::Matrix<double> testableMatrix6 = {
    {78.12},
    {19.87},
    {56.12},
    {13.76}
  };
  const algebra::Matrix<double> testableProductMatrix3 = testableMatrix5 * testableMatrix6;
  const algebra::Matrix<double> expectedProductMatrix3 = {
    {(13.76*78.12)+(56.12*19.87)+(19.87*56.12)+(78.12*13.76)}
  };
  ASSERT_TRUE(testableProductMatrix3 == expectedProductMatrix3);
}

TEST(MatrixOperationsTests_ExceptionTest, canDetermineInvalidMultiplicationAttempts)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> testableMatrix2 = {
    {1,2,3,13},
    {5,6,7,14},
    {9,10,11,15}
  };
  EXPECT_THROW(testableMatrix1 * testableMatrix2,std::logic_error);

  const algebra::Matrix<double> testableMatrix3 = {
    {1.3,1.4,1.5},
    {2.7,2.8,2.9}
  };
  const algebra::Matrix<double> testableMatrix4 = {
    {3.1,3.2,3.3},
    {2.7,2.8,2.9},
    {1.3,1.4,1.5},
    {2.7,2.8,2.9}
  };
  EXPECT_THROW(testableMatrix3 * testableMatrix4,std::logic_error);

  const algebra::Matrix<double> testableMatrix5 = {
    {13.76,56.12,19.87,78.12}
  };
  const algebra::Matrix<double> testableMatrix6 = {
    {78.12,19.87,56.12,13.76}
  };
  EXPECT_THROW(testableMatrix5 * testableMatrix6,std::logic_error);

  const algebra::Matrix<double> testableMatrix7 = {
    {78.12},
    {19.87},
    {56.12},
    {13.76}
  };
  const algebra::Matrix<double> testableMatrix8 = {
    {13.76},
    {56.12},
    {19.87},
    {78.12}
  };
  EXPECT_THROW(testableMatrix7 * testableMatrix8,std::logic_error);
}

TEST(MatrixOperationsTests, canDetermineTransposeOfMatrix)
{
  const algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> testableTransposeMatrix1 = testableMatrix1.Transpose();
  const algebra::Matrix<int> expectedTransposeMatrix1 = {
    {1,5,9},
    {2,6,10},
    {3,7,11},
    {4,8,12}
  };
  const algebra::Matrix<double> testableMatrix2 = {
    {3.1,3.2,3.3},
    {2.7,2.8,2.9},
    {1.3,1.4,1.5},
    {2.7,2.8,2.9}
  };
  const algebra::Matrix<double> testableTransposeMatrix2 = testableMatrix2.Transpose();
  const algebra::Matrix<double> expectedTransposeMatrix2 = {
    {3.1,2.7,1.3,2.7},
    {3.2,2.8,1.4,2.8},
    {3.3,2.9,1.5,2.9}
  };
  ASSERT_TRUE(testableTransposeMatrix2 == expectedTransposeMatrix2);

  const algebra::Matrix<int> testableMatrix3 = {
    {1,2,3,4,5}
  };
  const algebra::Matrix<int> testableTransposeMatrix3 = testableMatrix3.Transpose();
  const algebra::Matrix<int> expectedTransposeMatrix3 = {
    {1},
    {2},
    {3},
    {4},
    {5}
  };
  ASSERT_TRUE(testableTransposeMatrix3 == expectedTransposeMatrix3);

  const algebra::Matrix<double> testableMatrix4 = {
    {1.2},
    {2.3},
    {3.4},
    {4.5},
    {5.6}
  };
  const algebra::Matrix<double> testableTransposeMatrix4 = testableMatrix4.Transpose();
  const algebra::Matrix<double> expectedTransposeMatrix4 = {
    {1.2,2.3,3.4,4.5,5.6}
  };
  ASSERT_TRUE(testableTransposeMatrix4 == expectedTransposeMatrix4);
}

TEST(MatrixOperationsTests, canPerformElementaryRowOperationsOnMatrix)
{
  //#1 Row[i] <-> Row[j]
  algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix1.ElementaryRowOperation_Interchange_ByIndex(0,2);
  const algebra::Matrix<int> expectedMatrix1 = {
    {9,10,11,12},
    {5,6,7,8},
    {1,2,3,4}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);

  //#2 Row[i] -> k * Row[i]
  algebra::Matrix<int> testableMatrix2 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix2.ElementaryRowOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
  const algebra::Matrix<int> expectedMatrix2 = {
    {1,2,3,4},
    {20,24,28,32},
    {9,10,11,12}
  };
  ASSERT_TRUE(testableMatrix2 == expectedMatrix2);

  //#3 Row[i] -> Row[i] + k * Row[j]
  algebra::Matrix<int> testableMatrix3 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix3.ElementaryRowOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
  const algebra::Matrix<int> expectedMatrix3 = {
    {37,42,47,52},
    {5,6,7,8},
    {9,10,11,12}
  };
  ASSERT_TRUE(testableMatrix3 == expectedMatrix3);
}

TEST(MatrixOperationsTests, canPerformElementaryColumnOperationsOnMatrix)
{
  //#1 Column[i] <-> Column[j]
  algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix1.ElementaryColumnOperation_Interchange_ByIndex(0,3);

  const algebra::Matrix<int> expectedMatrix1 = {
    {4,2,3,1},
    {8,6,7,5},
    {12,10,11,9}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);

  //#2 Column[i] -> k * Column[i]
  algebra::Matrix<int> testableMatrix2 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix2.ElementaryColumnOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
  const algebra::Matrix<int> expectedMatrix2 = {
    {1,8,3,4},
    {5,24,7,8},
    {9,40,11,12}
  };
  ASSERT_TRUE(testableMatrix2 == expectedMatrix2);

  //#3 Column[i] -> Column[i] + k * Column[j]
  algebra::Matrix<int> testableMatrix3 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  testableMatrix3.ElementaryColumnOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
  const algebra::Matrix<int> expectedMatrix3 = {
    {13,2,3,4},
    {33,6,7,8},
    {53,10,11,12}
  };
  ASSERT_TRUE(testableMatrix3 == expectedMatrix3);
}

TEST(MatrixOperationsTests, canComputeAdjointMatrix)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  const algebra::Matrix<int> expectedAdjointMatrix1 = {
    {-3,6,-3},
    {6,-12,6},
    {-3,6,-3}
  };
  ASSERT_TRUE(algebra::FindAdjointMatrixFor(givenMatrix1) == expectedAdjointMatrix1);

  const algebra::Matrix<int> givenMatrix2 = {
    {1,2},
    {3,4}
  };
  const algebra::Matrix<int> expectedAdjointMatrix2 = {
    {4,-2},
    {-3,1}
  };
  ASSERT_TRUE(algebra::FindAdjointMatrixFor(givenMatrix2) == expectedAdjointMatrix2);
  const algebra::Matrix<int> givenMatrix3 = {
    {1,-1,2},
    {2,3,5},
    {-2,0,1}
  };
  const algebra::Matrix<int> expectedAdjointMatrix3 = {
    {3,1,-11},
    {-12,5,-1},
    {6,2,5}
  };
  ASSERT_TRUE(algebra::FindAdjointMatrixFor(givenMatrix3) == expectedAdjointMatrix3);
}

TEST(MatrixOperationsTests, canComputeInverseOfMatrixWithIntElements)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {2,-2},
    {4,3}
  };
  const algebra::Matrix<int> expectedInvertedMatrix1 = {
    {3,2},
    {-4,2}
  };
  ASSERT_TRUE(algebra::Invert(givenMatrix1) == expectedInvertedMatrix1);
  const algebra::Matrix<int> givenMatrix2 = {
    {1,-1,2},
    {0,2,-3},
    {3,-2,4}
  };
  const algebra::Matrix<int> expectedInvertedMatrix2 = {
    {-2,0,1},
    {9,2,-3},
    {6,1,-2}
  };
  ASSERT_TRUE(algebra::Invert(givenMatrix2) == expectedInvertedMatrix2);
  const algebra::Matrix<int> givenMatrix3 = {
    {-3,-3,-4},
    {0,1,1},
    {4,3,4}
  };
  const algebra::Matrix<int> expectedInvertedmatrix3 = {
    {1,0,1},
    {4,4,3},
    {-4,-3,-3}
  };
  ASSERT_TRUE(algebra::Invert(givenMatrix3) == expectedInvertedmatrix3);
}
