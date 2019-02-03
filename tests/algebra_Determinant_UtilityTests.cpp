#include "gtest/gtest.h"
#include "Determinant.hpp"
#include <cmath>

/*
 * Computation of area of a triangle from the given coordinates in 2D plane
 * When three points in 2D coordinate plane are given by (x1,y1),(x2,y2) and (x3,y3) representing the coordinates of a triangle, the area of the triangle is given by 0.5*[{x1*(y2-y3)}+{x2*(y3-y1)}+{x3*(y1-y2)}]
 * The expression can be written in the form of a determinant such as
 *       |x1 y1 1|
 * 0.5 * |x2 y2 1|
 *       |x3 y3 1|
 * and computed for the absolute value.
*/

TEST(DeterminantUtilityTests, canComputeAreaOfTriangle)
{
  const std::pair<int,int> givenPoint1 = std::make_pair<int,int>(3,8);
  const std::pair<int,int> givenPoint2 = std::make_pair<int,int>(-4,2);
  const std::pair<int,int> givenPoint3 = std::make_pair<int,int>(5,1);
  const double computedAreaOfTriangle1 = algebra::DeterminantUtility_AreaOfTriangle({givenPoint1,givenPoint2,givenPoint3});
  const double expectedAreaOfTriangle1 = std::fabs(
    0.5 * (
      (givenPoint1.first * (givenPoint2.second - givenPoint3.second)) +
      (givenPoint2.first * (givenPoint3.second - givenPoint1.second)) +
      (givenPoint3.first * (givenPoint1.second - givenPoint2.second))
    )
  );
  ASSERT_DOUBLE_EQ(computedAreaOfTriangle1,expectedAreaOfTriangle1);
}

TEST(DeterminantUtilityTests_ExceptionTest, canThrowIfCollinearPointsAreGivenForComputingAreaOfTriangle)
{
  const std::pair<int,int> givenPoint1 = std::make_pair<int,int>(3,7);
  const std::pair<int,int> givenPoint2 = std::make_pair<int,int>(-5,7);
  const std::pair<int,int> givenPoint3 = std::make_pair<int,int>(8,7);
  EXPECT_THROW(algebra::DeterminantUtility_AreaOfTriangle({givenPoint1,givenPoint2,givenPoint3}),std::runtime_error);
}