#include "gtest/gtest.h"
#include "Determinant.hpp"

TEST(DeterminantAnalyticalTests, canComputeDeterminantValue)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {5}
  };
  ASSERT_TRUE(givenDeterminant1.Value() == 5);

  const algebra::Determinant<int> givenDeterminant2 = {
    {1,2},
    {3,4}
  };
  ASSERT_TRUE(givenDeterminant2.Value() == -2);

  const algebra::Determinant<int> givenDeterminant3 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  ASSERT_TRUE(givenDeterminant3.Value() == 0);
}

TEST(DeterminantAnalyticalTests, canDetermineMinorsByIndex)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {5}
  };
  ASSERT_TRUE(givenDeterminant1.Minor_ByIndex(0,0) == 5);

  const algebra::Determinant<int> givenDeterminant2 = {
    {1,2},
    {3,4}
  };
  ASSERT_TRUE(givenDeterminant2.Minor_ByIndex(0,0) == 4);
  ASSERT_TRUE(givenDeterminant2.Minor_ByIndex(0,1) == 3);
  ASSERT_TRUE(givenDeterminant2.Minor_ByIndex(1,0) == 2);
  ASSERT_TRUE(givenDeterminant2.Minor_ByIndex(1,1) == 1);

  const algebra::Determinant<int> givenDeterminant3 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  const int expectedMinor00 = (givenDeterminant3(1,1) * givenDeterminant3(2,2)) - (givenDeterminant3(2,1) * givenDeterminant3(1,2));
  const int expectedMinor01 = (givenDeterminant3(1,0) * givenDeterminant3(2,2)) - (givenDeterminant3(2,0) * givenDeterminant3(1,2));
  const int expectedMinor02 = (givenDeterminant3(1,0) * givenDeterminant3(2,1)) - (givenDeterminant3(2,0) * givenDeterminant3(1,1));
  const int expectedMinor10 = (givenDeterminant3(0,1) * givenDeterminant3(2,2)) - (givenDeterminant3(2,1) * givenDeterminant3(0,2));
  const int expectedMinor11 = (givenDeterminant3(0,0) * givenDeterminant3(2,2)) - (givenDeterminant3(2,0) * givenDeterminant3(0,2));
  const int expectedMinor12 = (givenDeterminant3(0,0) * givenDeterminant3(2,1)) - (givenDeterminant3(2,0) * givenDeterminant3(0,1));
  const int expectedMinor20 = (givenDeterminant3(0,1) * givenDeterminant3(1,2)) - (givenDeterminant3(1,1) * givenDeterminant3(0,2));
  const int expectedMinor21 = (givenDeterminant3(0,0) * givenDeterminant3(1,2)) - (givenDeterminant3(1,0) * givenDeterminant3(0,2));
  const int expectedMinor22 = (givenDeterminant3(0,0) * givenDeterminant3(1,1)) - (givenDeterminant3(1,0) * givenDeterminant3(0,1));

  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(0,0) == expectedMinor00);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(0,1) == expectedMinor01);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(0,2) == expectedMinor02);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(1,0) == expectedMinor10);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(1,1) == expectedMinor11);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(1,2) == expectedMinor12);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(2,0) == expectedMinor20);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(2,1) == expectedMinor21);
  ASSERT_TRUE(givenDeterminant3.Minor_ByIndex(2,2) == expectedMinor22);
}

TEST(DeterminantAnalyticalTests, canDetermineCoFactorsByIndex)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {5}
  };
  ASSERT_TRUE(givenDeterminant1.CoFactor_ByIndex(0,0) == 5);

  const algebra::Determinant<int> givenDeterminant2 = {
    {1,2},
    {3,4}
  };
  ASSERT_TRUE(givenDeterminant2.CoFactor_ByIndex(0,0) == 4);
  ASSERT_TRUE(givenDeterminant2.CoFactor_ByIndex(0,1) == -3);
  ASSERT_TRUE(givenDeterminant2.CoFactor_ByIndex(1,0) == -2);
  ASSERT_TRUE(givenDeterminant2.CoFactor_ByIndex(1,1) == 1);

  const algebra::Determinant<int> givenDeterminant3 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  const int expectedCoFactor00 = (givenDeterminant3(1,1) * givenDeterminant3(2,2)) - (givenDeterminant3(2,1) * givenDeterminant3(1,2));
  const int expectedCoFactor01 = -((givenDeterminant3(1,0) * givenDeterminant3(2,2)) - (givenDeterminant3(2,0) * givenDeterminant3(1,2)));
  const int expectedCoFactor02 = (givenDeterminant3(1,0) * givenDeterminant3(2,1)) - (givenDeterminant3(2,0) * givenDeterminant3(1,1));
  const int expectedCoFactor10 = -((givenDeterminant3(0,1) * givenDeterminant3(2,2)) - (givenDeterminant3(2,1) * givenDeterminant3(0,2)));
  const int expectedCoFactor11 = (givenDeterminant3(0,0) * givenDeterminant3(2,2)) - (givenDeterminant3(2,0) * givenDeterminant3(0,2));
  const int expectedCoFactor12 = -((givenDeterminant3(0,0) * givenDeterminant3(2,1)) - (givenDeterminant3(2,0) * givenDeterminant3(0,1)));
  const int expectedCoFactor20 = (givenDeterminant3(0,1) * givenDeterminant3(1,2)) - (givenDeterminant3(1,1) * givenDeterminant3(0,2));
  const int expectedCoFactor21 = -((givenDeterminant3(0,0) * givenDeterminant3(1,2)) - (givenDeterminant3(1,0) * givenDeterminant3(0,2)));
  const int expectedCoFactor22 = (givenDeterminant3(0,0) * givenDeterminant3(1,1)) - (givenDeterminant3(1,0) * givenDeterminant3(0,1));

  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(0,0) == expectedCoFactor00);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(0,1) == expectedCoFactor01);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(0,2) == expectedCoFactor02);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(1,0) == expectedCoFactor10);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(1,1) == expectedCoFactor11);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(1,2) == expectedCoFactor12);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(2,0) == expectedCoFactor20);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(2,1) == expectedCoFactor21);
  ASSERT_TRUE(givenDeterminant3.CoFactor_ByIndex(2,2) == expectedCoFactor22);
}

TEST(DeterminantAnalyticalTests_ExceptionTest,canNotComputeMinorsAndCoFactorsForOrderBeyondThree)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4}
  };
  EXPECT_THROW(givenDeterminant1.Minor_ByIndex(0,0),std::runtime_error);
  EXPECT_THROW(givenDeterminant1.CoFactor_ByIndex(0,0),std::runtime_error);
}
