#include "gtest/gtest.h"
#include "Matrix.hpp"
#include "Helper.hpp"

TEST(MatrixSanityTests, canDetermineMatrixValidity)
{
  try
  {
    algebra::Matrix<int> givenMatrix1 {
      {1,2,3},
      {4,6,7},
      {9,10,11}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() == nullptr);
  }
  try
  {
    algebra::Matrix<double> givenMatrix2 {
      {3.5,1.9},
      {1.2,6.2},
      {1.56,3.7}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() == nullptr);
  }
}

TEST(MatrixSanityTests, canDetermineIfMatrixIsInvalid)
{
  try
  {
    algebra::Matrix<int> givenStructure1 {
      {1,2,3},
      {4,6,7,4},
      {9,10,11,12}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
  try
  {
    algebra::Matrix<double> givenStructure2 {
      {3.5,1.9,8.1},
      {1.2,6.2},
      {1.56,3.7,2.9}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
}

TEST(MatrixSanityTests, canDetermineMatrixOrder)
{
  algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const std::pair<size_t,size_t> intOrder = givenMatrix1.Order();
  ASSERT_EQ(intOrder.first,3);
  ASSERT_EQ(intOrder.second,4);

  algebra::Matrix<double> givenMatrix2 {
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
  algebra::Matrix<int> givenMatrix1 {
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

  algebra::Matrix<double> givenMatrix2 {
    {65.4,936.12},
    {47.1,93.15},
    {78.21,45.21},
    {90.23,81.23}
  };
  ASSERT_EQ(givenMatrix2(0,0),65.4);
  ASSERT_EQ(givenMatrix2(0,1),936.12);
  ASSERT_EQ(givenMatrix2(1,0),47.1);
  ASSERT_EQ(givenMatrix2(1,1),93.15);
  ASSERT_EQ(givenMatrix2(2,0),78.21);
  ASSERT_EQ(givenMatrix2(2,1),45.21);
  ASSERT_EQ(givenMatrix2(3,0),90.23);
  ASSERT_EQ(givenMatrix2(3,1),81.23);
}

TEST(MatrixSanityTests, canDetermineOutOfRangeSubscriptingAttempts)
{
  try
  {
    algebra::Matrix<int> givenMatrix1 {
      {1,2,3,4},
      {4,6,7,8},
      {9,10,11,12}
    };
    const int element = givenMatrix1(3,3);
  }
  catch(const std::exception& e)
  {
    ASSERT_TRUE(e.what() != nullptr);
  }
}

TEST(MatrixSanityTests,canDetermineRowsAndColumnsSeparately)
{
  algebra::Matrix<int> givenMatrix1 {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  
  const std::vector<algebra::Row<int>> rows = givenMatrix1.Rows();
  ASSERT_EQ(rows.size(),3);
  algebra::Row<int> testableRow0({1,2,3,4});
  algebra::Row<int> testableRow1({4,6,7,8});
  algebra::Row<int> testableRow2({9,10,11,12});
  ASSERT_TRUE(rows[0] == testableRow0);
  ASSERT_TRUE(rows[1] == testableRow1);
  ASSERT_TRUE(rows[2] == testableRow2);

  const std::vector<algebra::Column<int>> columns = givenMatrix1.Columns();
  ASSERT_EQ(columns.size(),4);
  algebra::Column<int> testableColumn0({1,4,9});
  algebra::Column<int> testableColumn1({2,6,10});
  algebra::Column<int> testableColumn2({3,7,11});
  algebra::Column<int> testableColumn3({4,8,12});
  ASSERT_TRUE(columns[0] == testableColumn0);
  ASSERT_TRUE(columns[1] == testableColumn1);
  ASSERT_TRUE(columns[2] == testableColumn2);
  ASSERT_TRUE(columns[3] == testableColumn3);
}