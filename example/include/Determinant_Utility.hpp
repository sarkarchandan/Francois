#ifndef DETERMINAT_UTILITY_H
#define DETERMINAT_UTILITY_H

#include <iostream>
#include "Determinant.hpp"

void Determinant_Demo_Utility()
{
  /*
  * Matrices and determinants are widely used in linear algebra. For the timebeing, this code segment demonstrates of these which is, computing the area of a triangle from the non-collinear 2D coordinates.
   * Computation of area of a triangle from the given coordinates in 2D plane
   * When three points in 2D coordinate plane are given by (x1,y1),(x2,y2) and (x3,y3) representing the coordinates of a triangle, the area of the triangle is given by 0.5*[{x1*(y2-y3)}+{x2*(y3-y1)}+{x3*(y1-y2)}]
   * The expression can be written in the form of a determinant such as
   *       |x1 y1 1|
   * 0.5 * |x2 y2 1|
   *       |x3 y3 1|
   * and computed for the absolute value.
  */
  std::cout << "**Determinant utility demonstration**" << "\n";
  const std::pair<int,int> point1 = std::make_pair<int,int>(3,8);
  const std::pair<int,int> point2 = std::make_pair<int,int>(-4,2);
  const std::pair<int,int> point3 = std::make_pair<int,int>(5,1);
  const double computedAreaOfTriangle = algebra::DeterminantUtility_AreaOfTriangle({point1,point2,point3});
  std::cout << "Given points are: " << "(" << point1.first << "," << point1.second << ")" << "\n";
  std::cout << "Given points are: " << "(" << point2.first << "," << point2.second << ")" << "\n";
  std::cout << "Given points are: " << "(" << point3.first << "," << point3.second << ")" << "\n";
  std::cout << "Computed area of the triangle derived from these three points is: " << computedAreaOfTriangle << " square units." << "\n";
}

#endif //DETERMINAT_UTILITY_H