#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixValidity, canDetermineIfMatrixIsValid)
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

TEST(MatrixInValidity, canDetermineIfMatrixIsInavalid)
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

TEST(MatrixOrder,canDetermineCorrectOrderofMatrix)
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