#include "gtest/gtest.h"
#include "Matrix.hpp"
#include "Helper.hpp"

TEST(MatrixValidity, canDetermineIfValid)
{
  try
  {
    algebra::Matrix<int> intMatrix {
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
    algebra::Matrix<double> doubleMatrix {
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

TEST(MatrixInValidity, canDetermineIfInavalid)
{
  try
  {
    algebra::Matrix<int> intMatrix {
      {1,2,3},
      {4,6,7,4},
      {9,10,11,12}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_FALSE(e.what() == nullptr);
  }
  try
  {
    algebra::Matrix<double> doubleMatrix {
      {3.5,1.9,8.1},
      {1.2,6.2},
      {1.56,3.7,2.9}
    };
  }
  catch(const std::exception& e)
  {
    ASSERT_FALSE(e.what() == nullptr);
  }
}

TEST(MatrixOrder, canDetermineOrder)
{
  algebra::Matrix<int> intMatrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const std::pair<size_t,size_t> intOrder = intMatrix.Order();
  ASSERT_EQ(intOrder.first,3);
  ASSERT_EQ(intOrder.second,4);

  algebra::Matrix<double> doubleMatrix {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7},
    {4.7,1.8}
  };
  const std::pair<size_t,size_t> doubleOrder = doubleMatrix.Order();
  ASSERT_EQ(doubleOrder.first,4);
  ASSERT_EQ(doubleOrder.second,2);
}

TEST(MatrixElementsSubscripting, canAccessElementsBySubscripting)
{
  algebra::Matrix<int> matrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  ASSERT_EQ(matrix(0,0),1);
  ASSERT_EQ(matrix(1,1),6);
  ASSERT_EQ(matrix(2,2),11);
  ASSERT_EQ(matrix(0,3),4);
  ASSERT_EQ(matrix(1,3),8);
  ASSERT_EQ(matrix(2,3),12);
}

TEST(MatrixElementsOutOfRangeSubscripting, canDetermineOutOfRangeSubscripting)
{
  try
  {
    algebra::Matrix<int> matrix {
      {1,2,3,4},
      {4,6,7,8},
      {9,10,11,12}
    };
    const int element = matrix(3,3);
  }
  catch(const std::exception& e)
  {
    ASSERT_FALSE(e.what() == nullptr);
  }
}

TEST(RowsAndColumnsAreDistinctlyAccessible,canSubscriptForRowsAndColumns)
{
  algebra::Matrix<int> matrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  
  const std::vector<algebra::Row<int>> rows = matrix.Rows();
  ASSERT_EQ(rows.size(),3);
  algebra::Row<int> testableRow0({1,2,3,4});
  algebra::Row<int> testableRow1({4,6,7,8});
  algebra::Row<int> testableRow2({9,10,11,12});
  ASSERT_TRUE(rows[0] == testableRow0);
  ASSERT_TRUE(rows[1] == testableRow1);
  ASSERT_TRUE(rows[2] == testableRow2);

  const std::vector<algebra::Column<int>> columns = matrix.Columns();
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