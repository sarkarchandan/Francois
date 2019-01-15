#include "gtest/gtest.h"
#include "Matrix.hpp"
#include <memory>

TEST(MatrixSanityTests, canInstantiateMatrixWithInitializerListAndVector)
{
  const std::initializer_list<std::vector<int>> givenList1 = {
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  const std::vector<std::vector<int>> givenVectors1 = { 
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  EXPECT_NO_THROW(algebra::Matrix<int> {givenList1});
  EXPECT_NO_THROW(algebra::Matrix<int> {givenVectors1});

  const std::initializer_list<std::vector<float>> givenList2 = {
    {1.2f,3.4f,4.5f},
    {6.7f,8.9f,10.11f}
  };
  const std::vector<std::vector<float>> givenVectors2 = {
    {1.2f,3.4f,4.5f},
    {6.7f,8.9f,10.11f}
  };
  EXPECT_NO_THROW(algebra::Matrix<float> {givenList2});
  EXPECT_NO_THROW(algebra::Matrix<float> {givenVectors2});

  const std::initializer_list<std::vector<double>> givenList3 = {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7}
  };
  const std::vector<std::vector<double>> givenVectors3 = {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7}
  };
  EXPECT_NO_THROW(algebra::Matrix<double> {givenList3});
  EXPECT_NO_THROW(algebra::Matrix<double> {givenVectors3});
}

TEST(MatrixSanityTests_ExceptionTest, canDetermineIfMatrixIsInvalid)
{
  const std::initializer_list<std::vector<int>> givenList1 = {
    {1,2,3},
    {4,6,7,4},
    {9,10,11,12}
  };
  EXPECT_THROW(algebra::Matrix<int> {givenList1},std::invalid_argument);

  const std::initializer_list<std::vector<double>> givenList2 = {
    {3.5,1.9,8.1},
    {1.2,6.2},
    {1.56,3.7,2.9}
  };
  EXPECT_THROW(algebra::Matrix<double> {givenList2},std::invalid_argument);

  const std::vector<std::vector<int>> givenVector1 = {
    {1,2,3},
    {4,6,7,4},
    {9,10,11,12}
  };
  EXPECT_THROW(algebra::Matrix<int> {givenVector1},std::invalid_argument);

  const std::vector<std::vector<double>> givenVector2 = {
    {3.5,1.9,8.1},
    {1.2,6.2},
    {1.56,3.7,2.9}
  };
  EXPECT_THROW(algebra::Matrix<double>{givenVector2},std::invalid_argument);

  const std::vector<algebra::Row<int>> givenRows1 = {{1,2,3,4},{5,6,8},{9,10,11,12}};
  EXPECT_THROW(algebra::Matrix<int> {givenRows1},std::invalid_argument);

  const std::vector<algebra::Row<double>> givenRows2 = {{3.5,1.9,5.3},{1.2,6.2},{1.56,3.7,8.2},{4.7,1.8,7.4}};
  EXPECT_THROW(algebra::Matrix<double>{givenRows2},std::invalid_argument);

  const std::vector<algebra::Column<int>> givenColumns1 = {{1,2,3,4},{5,6,8},{9,10,11,12}};
  EXPECT_THROW(algebra::Matrix<int>{givenColumns1},std::invalid_argument);

  const std::vector<algebra::Column<double>> givenColumns2 = {{65.4,936.12,90.23,65.78},{47.1,93.15,43.98}};
  EXPECT_THROW(algebra::Matrix<double>{givenColumns2},std::invalid_argument);
}

TEST(MatrixSanityTests, canDetermineMatrixOrder)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const std::pair<size_t,size_t> intOrder = givenMatrix1.Order();
  ASSERT_EQ(intOrder.first,3);
  ASSERT_EQ(intOrder.second,4);

  const algebra::Matrix<double> givenMatrix2 = {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7},
    {4.7,1.8}
  };
  const std::pair<size_t,size_t> doubleOrder = givenMatrix2.Order();
  ASSERT_EQ(doubleOrder.first,4);
  ASSERT_EQ(doubleOrder.second,2);
}

TEST(MatrixSanityTests, canAccessElementsBySubscripting)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_EQ(givenMatrix1(0,0),1);
  ASSERT_EQ(givenMatrix1(1,1),6);
  ASSERT_EQ(givenMatrix1(2,2),11);
  ASSERT_EQ(givenMatrix1(0,3),4);
  ASSERT_EQ(givenMatrix1(1,3),8);
  ASSERT_EQ(givenMatrix1(2,3),12);

  const algebra::Matrix<double> givenMatrix2 = {
    {65.4,936.12},
    {47.1,93.15},
    {78.21,45.21},
    {90.23,81.23}
  };
  ASSERT_DOUBLE_EQ(givenMatrix2(0,0),65.4);
  ASSERT_DOUBLE_EQ(givenMatrix2(0,1),936.12);
  ASSERT_DOUBLE_EQ(givenMatrix2(1,0),47.1);
  ASSERT_DOUBLE_EQ(givenMatrix2(1,1),93.15);
  ASSERT_DOUBLE_EQ(givenMatrix2(2,0),78.21);
  ASSERT_DOUBLE_EQ(givenMatrix2(2,1),45.21);
  ASSERT_DOUBLE_EQ(givenMatrix2(3,0),90.23);
  ASSERT_DOUBLE_EQ(givenMatrix2(3,1),81.23);
}

TEST(MatrixSanityTests, canUpdateElementsOfMatrixBySubscripting)
{
  algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  givenMatrix1(1,1) = 12;
  givenMatrix1(0,3) = 23;
  givenMatrix1(2,2) = 66;
  const algebra::Matrix<int> expectedMatrix1 = {
    {1,2,3,23},
    {4,12,7,8},
    {9,10,66,12}
  };

  algebra::Matrix<double> givenMatrix2 = {
    {65.4,936.12},
    {47.1,93.15},
    {78.21,45.21},
    {90.23,81.23}
  };
  givenMatrix2(1,1) = 15.93;
  givenMatrix2(2,0) = 21.78;
  givenMatrix2(3,1) = 23.81;
  const algebra::Matrix<double> expectedMatrix2 = {
    {65.4,936.12},
    {47.1,15.93},
    {21.78,45.21},
    {90.23,23.81}
  };
  ASSERT_TRUE(givenMatrix2 == expectedMatrix2);
}

TEST(MatrixSanityTests_ExceptionTest, canDetermineOutOfRangeSubscriptingAttempts)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  EXPECT_THROW(givenMatrix1(3,3),std::out_of_range);
  
  const algebra::Matrix<double> givenMatrix2 = {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7},
    {4.7,1.8}
  };
  EXPECT_THROW(givenMatrix2(3,2),std::out_of_range);
}

TEST(MatrixSanityTests,canDetermineRowsAndColumnsSeparately)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  
  const std::vector<algebra::Row<int>> rows = givenMatrix1.Rows();
  ASSERT_EQ(rows.size(),3);
  const algebra::Row<int> testableRow0 {1,2,3,4};
  const algebra::Row<int> testableRow1 {4,6,7,8};
  const algebra::Row<int> testableRow2 {9,10,11,12};

  ASSERT_TRUE(rows[0] == testableRow0);
  ASSERT_TRUE(rows[1] == testableRow1);
  ASSERT_TRUE(rows[2] == testableRow2);

  const std::vector<algebra::Column<int>> columns = givenMatrix1.Columns();
  ASSERT_EQ(columns.size(),4);
  const algebra::Column<int> testableColumn0 {1,4,9};
  const algebra::Column<int> testableColumn1 {2,6,10};
  const algebra::Column<int> testableColumn2 {3,7,11};
  const algebra::Column<int> testableColumn3 {4,8,12};
  
  ASSERT_TRUE(columns[0] == testableColumn0);
  ASSERT_TRUE(columns[1] == testableColumn1);
  ASSERT_TRUE(columns[2] == testableColumn2);
  ASSERT_TRUE(columns[3] == testableColumn3);
}

TEST(MatrixSanityTests, canUpdateIndividualElementOfRow)
{
  algebra::Row<int> testableRow1 = {1,2,3,4,5,6};
  testableRow1[1] = 12;
  testableRow1[3] = 11;
  const algebra::Row<int> expectedRow1 = {1,12,3,11,5,6};
  ASSERT_TRUE(testableRow1 == expectedRow1);

  algebra::Row<double> testableRow2 = {1.3,1.4,1.5,1.6};
  testableRow2[1] = 4.45;
  testableRow2[2] = 87.34;
  const algebra::Row<double> expectedRow2 = {1.3,4.45,87.34,1.6};
  ASSERT_TRUE(testableRow2 == expectedRow2);
}

TEST(MatrixSanityTests, canUpdateIndividualElementOfColumn)
{
  algebra::Column<int> testableColumn1 = {1,2,3,4,5,6};
  testableColumn1[1] = 12;
  testableColumn1[3] = 11;
  const algebra::Column<int> expectedColumn1 = {1,12,3,11,5,6};
  ASSERT_TRUE(testableColumn1 == expectedColumn1);

  algebra::Column<double> testableColumn2 = {1.3,1.4,1.5,1.6};
  testableColumn2[1] = 4.45;
  testableColumn2[2] = 87.34;
  const algebra::Column<double> expectedColumn2 = {1.3,4.45,87.34,1.6};
  ASSERT_TRUE(testableColumn2 == expectedColumn2);
}

TEST(MatrixSanityTests,canInitializeMatrixWithRows)
{
  const std::vector<algebra::Row<int>> testableIntRows = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  const algebra::Matrix<int> testableIntMatrix = testableIntRows;
  const algebra::Matrix<int> expectedIntMatrix = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  ASSERT_TRUE(testableIntMatrix == expectedIntMatrix);
  const std::pair<size_t,size_t> expectedIntPair = std::make_pair<size_t,size_t>(3,4);
  ASSERT_TRUE(testableIntMatrix.Order() == expectedIntPair);

  const std::vector<algebra::Row<double>> testableDoubleRows = {{1.3,1.4,1.5},{2.7,2.8,2.9},{3.1,3.2,3.3}};
  const algebra::Matrix<double> testableDoubleMatrix = testableDoubleRows;
  const algebra::Matrix<double> expectedDoubleMatrix = {
    {1.3,1.4,1.5},
    {2.7,2.8,2.9},
    {3.1,3.2,3.3}
  };
  ASSERT_TRUE(testableDoubleMatrix == expectedDoubleMatrix);
  const std::pair<size_t,size_t> expectedDoublepair = std::make_pair<size_t,size_t>(3,3);
  ASSERT_TRUE(testableDoubleMatrix.Order() == expectedDoublepair);
}

TEST(MatrixSanityTests, canInitializeMatrixWithColumns)
{
  const std::vector<algebra::Column<int>> testableIntColumns = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  const algebra::Matrix<int> testableIntMatrix = testableIntColumns;
  const algebra::Matrix<int> expectedIntMatrix = {
    {1,5,9},
    {2,6,10},
    {3,7,11},
    {4,8,12}
  };
  ASSERT_TRUE(testableIntMatrix == expectedIntMatrix);
  std::pair<size_t,size_t> expectedIntPair = std::make_pair<size_t,size_t>(4,3);
  ASSERT_TRUE(testableIntMatrix.Order() == expectedIntPair);

  const std::vector<algebra::Column<double>> testableDoubleColumns = {{65.4,936.12,90.23,65.78},{47.1,93.15,81.32,43.98}};
  const algebra::Matrix<double> testableDoubleMatrix = testableDoubleColumns;
  const algebra::Matrix<double> expectedDoubleMatrix = {
    {65.4,47.1},
    {936.12,93.15},
    {90.23,81.32},
    {65.78,43.98}
  };
  ASSERT_TRUE(testableDoubleMatrix == expectedDoubleMatrix);
  std::pair<size_t,size_t> expectedDoublePair = std::make_pair<size_t,size_t>(4,2);
  ASSERT_TRUE(expectedDoubleMatrix.Order() == expectedDoublePair);
}


TEST(MatrixSanityTests, canUpdateRowWithCopyAssignmentOperator)
{
  algebra::Row<int> testableRow1 = {1,2,3,4,5};
  const algebra::Row<int> testableRow2 = {7,8,9,10,11};
  testableRow1 = testableRow2;
  const algebra::Row<int> expectedRow1 = {7,8,9,10,11};
  ASSERT_TRUE(testableRow1 == expectedRow1);

  algebra::Row<double> testableRow3 = {1.2,3.4,5.6,7.8};
  const algebra::Row<double> testableRow4 = {9.10,11.12,13.14,15.16};
  testableRow3 = testableRow4;
  const algebra::Row<double> expectedRow3 = {9.10,11.12,13.14,15.16};
  ASSERT_TRUE(testableRow3 == expectedRow3);
}

TEST(MatrixSanityTests, canUpdateColumnWithCopyAssignmentOperator)
{
  algebra::Column<int> testableColumn1 = {1,2,3,4,5};
  const algebra::Column<int> testableColumn2 = {7,8,9,10,11};
  testableColumn1 = testableColumn2;
  const algebra::Column<int> expectedColumn1 = {7,8,9,10,11};
  ASSERT_TRUE(testableColumn1 == expectedColumn1);

  algebra::Column<double> testableColumn3 = {1.2,3.4,5.6,7.8};
  const algebra::Column<double> testableColumn4 = {9.10,11.12,13.14,15.16};
  testableColumn3 = testableColumn4;
  const algebra::Column<double> expectedColumn3 = {9.10,11.12,13.14,15.16};
  ASSERT_TRUE(testableColumn3 == expectedColumn3);
}

TEST(MatrixSanityTests_ExceptionTest, canDetermineCopyAssignmentAttemptsForUnequalSizes)
{
  algebra::Row<int> testableRow1 = {1,2,3,4,5};
  const algebra::Row<int> testableRow2 = {7,8,9,10};
  EXPECT_THROW(testableRow1 = testableRow2,std::length_error);

  algebra::Row<double> testableRow3 = {1.2,3.4,5.6,7.8};
  const algebra::Row<double> testableRow4 = {9.10,11.12,13.14};
  EXPECT_THROW(testableRow3 = testableRow4,std::length_error);

  algebra::Column<int> testableColumn1 = {1,2,3,4};
  const algebra::Column<int> testableColumn2 = {7,8,9,10,11};
  EXPECT_THROW(testableColumn1 = testableColumn2,std::length_error);

  algebra::Column<double> testableColumn3 = {1.2,3.4,5.6};
  const algebra::Column<double> testableColumn4 = {9.10,11.12,13.14,15.16};
  EXPECT_THROW(testableColumn3 = testableColumn4,std::length_error);
}

TEST(MatrixSanityTests, canUpdateMatrixWithCopyAssignmentOperator)
{
  algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> testableMatrix2 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  testableMatrix1 = testableMatrix2;
  const algebra::Matrix<int> expectedMatrix1 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  ASSERT_TRUE(testableMatrix1 == expectedMatrix1);

  algebra::Matrix<double> testableMatrix3 = {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,164.76,983.1}
  };

  const algebra::Matrix<double> testableMatrix4 = {
    {65.23,54.12,54.19,23.17},
    {12.98,43.186,87.12,32.145},
    {123.98,12.76,12.984,98.12},
    {43.198,87.12,76.164,1.983}
  };
  testableMatrix3 = testableMatrix4;
  const algebra::Matrix<double> expectedMatrix3 = {
    {65.23,54.12,54.19,23.17},
    {12.98,43.186,87.12,32.145},
    {123.98,12.76,12.984,98.12},
    {43.198,87.12,76.164,1.983}
  };
  ASSERT_TRUE(testableMatrix3 == expectedMatrix3);
}

TEST(MatrixSanityTests_ExceptionTest, canDetermineCopyAssignmentAttemptsForMatricesOfDifferentOrder)
{
  algebra::Matrix<int> testableMatrix1 = {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> testableMatrix2 = {
    {13,14,15},
    {17,18,19},
    {21,22,23}
  };
  EXPECT_THROW(testableMatrix1 = testableMatrix2,std::length_error);

  algebra::Matrix<double> testableMatrix3 = {
    {23.65,12.54,19.64,17.23},
    {98.12,186.32,12.87,145.32},
    {98.123,76.12,984.12,12.98},
    {198.43,12.87,164.76,983.1}
  };

  const algebra::Matrix<double> testableMatrix4 = {
    {65.23,54.12,54.19,23.17},
    {12.98,43.186,87.12,32.145},
    {123.98,12.76,12.984,98.12}
  };
  EXPECT_THROW(testableMatrix3 = testableMatrix4,std::length_error);
}




