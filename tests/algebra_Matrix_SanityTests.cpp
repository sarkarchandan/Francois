#include "gtest/gtest.h"
#include "Matrix.hpp"
#include <memory>

TEST(MatrixSanityTests, canInstantiateMatrixWithInitializerListAndVector)
{
  const std::initializer_list<std::vector<int>> givenList1 {
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  const std::vector<std::vector<int>> givenVectors1 { 
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  EXPECT_NO_THROW(algebra::Matrix<int> {givenList1});
  EXPECT_NO_THROW(algebra::Matrix<int> {givenVectors1});

  const std::initializer_list<std::vector<float>> givenList2 {
    {1.2f,3.4f,4.5f},
    {6.7f,8.9f,10.11f}
  };
  const std::vector<std::vector<float>> givenVectors2 {
    {1.2f,3.4f,4.5f},
    {6.7f,8.9f,10.11f}
  };
  EXPECT_NO_THROW(algebra::Matrix<float> {givenList2});
  EXPECT_NO_THROW(algebra::Matrix<float> {givenVectors2});

  const std::initializer_list<std::vector<double>> givenList3 {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7}
  };
  const std::vector<std::vector<double>> givenVectors3 {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7}
  };
  EXPECT_NO_THROW(algebra::Matrix<double> {givenList3});
  EXPECT_NO_THROW(algebra::Matrix<double> {givenVectors3});
}

TEST(MatrixSanityTests_ExceptionTest, canDetermineIfMatrixIsInvalid)
{
  const std::initializer_list<std::vector<int>> givenList1 {
    {1,2,3},
    {4,6,7,4},
    {9,10,11,12}
  };
  EXPECT_THROW(algebra::Matrix<int> {givenList1},std::invalid_argument);

  const std::initializer_list<std::vector<double>> givenList2 {
    {3.5,1.9,8.1},
    {1.2,6.2},
    {1.56,3.7,2.9}
  };
  EXPECT_THROW(algebra::Matrix<double> {givenList2},std::invalid_argument);

  const std::vector<std::vector<int>> givenVector1 {
    {1,2,3},
    {4,6,7,4},
    {9,10,11,12}
  };
  EXPECT_THROW(algebra::Matrix<int> {givenVector1},std::invalid_argument);

  const std::vector<std::vector<double>> givenVector2 {
    {3.5,1.9,8.1},
    {1.2,6.2},
    {1.56,3.7,2.9}
  };
  EXPECT_THROW(algebra::Matrix<double>{givenVector2},std::invalid_argument);

  const std::vector<algebra::Row<int>> givenRows1 {{1,2,3,4},{5,6,8},{9,10,11,12}};
  EXPECT_THROW(algebra::Matrix<int> {givenRows1},std::invalid_argument);

  const std::vector<algebra::Row<double>> givenRows2 {{3.5,1.9,5.3},{1.2,6.2},{1.56,3.7,8.2},{4.7,1.8,7.4}};
  EXPECT_THROW(algebra::Matrix<double>{givenRows2},std::invalid_argument);
}

TEST(MatrixSanityTests, canDetermineMatrixOrder)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const std::pair<size_t,size_t> intOrder = givenMatrix1.Order();
  ASSERT_EQ(intOrder.first,3);
  ASSERT_EQ(intOrder.second,4);

  const algebra::Matrix<double> givenMatrix2 {
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
  const algebra::Matrix<int> givenMatrix1 {
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

  const algebra::Matrix<double> givenMatrix2 {
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

TEST(MatrixSanityTests_ExceptionTest, canDetermineOutOfRangeSubscriptingAttempts)
{
  const algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  EXPECT_THROW(givenMatrix1(3,3),std::out_of_range);
  
  const algebra::Matrix<double> givenMatrix2 {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7},
    {4.7,1.8}
  };
  EXPECT_THROW(givenMatrix2(3,2),std::out_of_range);
}

TEST(MatrixSanityTests,canDetermineRowsAndColumnsSeparately)
{
  const algebra::Matrix<int> givenMatrix1 {
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

TEST(MatrixSanityTests,canInitializeMatrixWithRows)
{
  const std::vector<algebra::Row<int>> testableRows {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  const algebra::Matrix<int> testableIntMatrix = testableRows;
  const algebra::Matrix<int> expectedIntMatrix {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  ASSERT_TRUE(testableIntMatrix == expectedIntMatrix);
}

