#include "gtest/gtest.h"
#include "Matrix.hpp"

TEST(MatrixOrder,canDetermineCorrectMatrixOrder)
{
  algebra::Matrix<int> matrix {
    {1,2,3,4},
    {4,6,7,8},
    {9,10,11,12}
  };
  const std::pair<int,int> order = matrix.Order();
  ASSERT_EQ(order.first,3);
  ASSERT_EQ(order.second,4);
}

TEST(MatrixValidity, canDetermineIfTheMatrixIsInavalid)
{
  
}