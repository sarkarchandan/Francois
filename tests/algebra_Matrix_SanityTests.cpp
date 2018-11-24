#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixValidity, canDetermineIfValid)
{
  try
  {
    algebra::Matrix<int> intMatrix {
      {1,2,3},
      {4,6,7},
      {9,10,11}};
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
      {1.56,3.7}};
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
      {9,10,11,12}};
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
      {1.56,3.7,2.9}};
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
    {9,10,11,12}};
  const std::pair<size_t,size_t> intOrder = intMatrix.Order();
  ASSERT_EQ(intOrder.first,3);
  ASSERT_EQ(intOrder.second,4);

  algebra::Matrix<double> doubleMatrix {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7},
    {4.7,1.8}};
  const std::pair<size_t,size_t> doubleOrder = doubleMatrix.Order();
  ASSERT_EQ(doubleOrder.first,4);
  ASSERT_EQ(doubleOrder.second,2);
}

TEST(MatrixElementsSubscripting, canAccessElementsBySubscripting)
{
  algebra::Matrix<int> matrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}};
  ASSERT_EQ(matrix(0,0),1);
  ASSERT_EQ(matrix(1,1),6);
  ASSERT_EQ(matrix(2,2),11);
  ASSERT_EQ(matrix(2,3),12);
}

TEST(MatrixElementsInvalidSubscripting, canDetermineInvalidSubscripting)
{
  try
  {
    algebra::Matrix<int> matrix {
      {1,2,3,4},
      {4,6,7,8},
      {9,10,11,12}};
    const int element = matrix(3,3);
  }
  catch(const std::exception& e)
  {
    ASSERT_FALSE(e.what() == nullptr);
  }
}

TEST(MatrixRowsAndColumnsAreAccessible,canSubscriptForRowsAndColumns)
{
  algebra::Matrix<int> matrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}};
  
  const std::vector<algebra::Row<int>> rows = matrix.Rows();
  ASSERT_EQ(rows.size(),3);
  ASSERT_EQ(rows[0].Size(),4);
  ASSERT_EQ(rows[1].Size(),4);
  ASSERT_EQ(rows[2].Size(),4);
  ASSERT_EQ(rows[0][0],1);
  ASSERT_EQ(rows[0][3],4);
  ASSERT_EQ(rows[1][0],4);
  ASSERT_EQ(rows[1][3],8);
  ASSERT_EQ(rows[2][0],9);
  ASSERT_EQ(rows[2][3],12);

  const std::vector<algebra::Column<int>> columns = matrix.Columns();
  ASSERT_EQ(columns.size(),4);
  ASSERT_EQ(columns[0].Size(),3);
  ASSERT_EQ(columns[1].Size(),3);
  ASSERT_EQ(columns[2].Size(),3);
  ASSERT_EQ(columns[3].Size(),3);
  ASSERT_EQ(columns[0][0],1);
  ASSERT_EQ(columns[0][1],4);
  ASSERT_EQ(columns[0][2],9);
  ASSERT_EQ(columns[1][0],2);
  ASSERT_EQ(columns[1][1],6);
  ASSERT_EQ(columns[1][2],10);
  ASSERT_EQ(columns[2][0],3);
  ASSERT_EQ(columns[2][1],7);
  ASSERT_EQ(columns[2][2],11);
  ASSERT_EQ(columns[3][0],4);
  ASSERT_EQ(columns[3][1],8);
  ASSERT_EQ(columns[3][2],12);
}