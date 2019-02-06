#ifndef DETERMINANT_OPERATIONS_H
#define DETERMINANT_OPERATIONS_H

#include <iostream>
#include "Determinant.hpp"

void Determinant_Demo_Operations()
{
  /*
  * This code segment demonstrates some of the operations which are performed in context of the determinant. 
  ** For the time being, Determinant and its related operations only supports upto order 3. Work is being done to improve and overcome this limitation**.
  */
  std::cout << "**Some of the operations performed in context of the determinant**" << "\n";
  const algebra::Determinant<int> determinant1 = {
    {1,-1,2},
    {0,2,-3},
    {3,-2,4}
  };
  std::cout << "Given determinant: " << determinant1;
  std::cout << "Value of this determinant is given by: " << determinant1.Value() << "\n";
  const algebra::Determinant<int> determinant2 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  std::cout << "Another determinant: " << determinant2;
  std::cout << "Value of this determinant is given by: " << determinant2.Value() << "\n";
  std::cout << "\n";
  std::cout << "Let's take the same determinant: " << determinant2;
  std::cout << "Minor for index: (0,0) in this determinant is given by : " << determinant2.Minor_ByIndex(0,0) << "\n";
  std::cout << "Minor for index: (0,1) in this determinant is given by : " << determinant2.Minor_ByIndex(0,1) << "\n";
  std::cout << "Minor for index: (0,2) in this determinant is given by : " << determinant2.Minor_ByIndex(0,2) << "\n";
  std::cout << "Minor for index: (1,0) in this determinant is given by : " << determinant2.Minor_ByIndex(1,0) << "\n";
  std::cout << "Minor for index: (1,1) in this determinant is given by : " << determinant2.Minor_ByIndex(1,1) << "\n";
  std::cout << "Minor for index: (1,2) in this determinant is given by : " << determinant2.Minor_ByIndex(1,2) << "\n";
  std::cout << "Minor for index: (2,0) in this determinant is given by : " << determinant2.Minor_ByIndex(2,0) << "\n";
  std::cout << "Minor for index: (2,1) in this determinant is given by : " << determinant2.Minor_ByIndex(2,1) << "\n";
  std::cout << "Minor for index: (2,2) in this determinant is given by : " << determinant2.Minor_ByIndex(2,2) << "\n";
  std::cout << "\n";

  std::cout << "Let's take the other determinant: " << determinant1;
  std::cout << "CoFactor for index: (0,0) is this determinant is given by: " << determinant1.CoFactor_ByIndex(0,0) << "\n";
  std::cout << "CoFactor for index: (0,1) is this determinant is given by: " << determinant1.CoFactor_ByIndex(0,1) << "\n";
  std::cout << "CoFactor for index: (0,2) is this determinant is given by: " << determinant1.CoFactor_ByIndex(0,2) << "\n";
  std::cout << "CoFactor for index: (1,0) is this determinant is given by: " << determinant1.CoFactor_ByIndex(1,0) << "\n";
  std::cout << "CoFactor for index: (1,1) is this determinant is given by: " << determinant1.CoFactor_ByIndex(1,1) << "\n";
  std::cout << "CoFactor for index: (1,2) is this determinant is given by: " << determinant1.CoFactor_ByIndex(1,2) << "\n";
  std::cout << "CoFactor for index: (2,0) is this determinant is given by: " << determinant1.CoFactor_ByIndex(2,0) << "\n";
  std::cout << "CoFactor for index: (2,1) is this determinant is given by: " << determinant1.CoFactor_ByIndex(2,1) << "\n";
  std::cout << "CoFactor for index: (2,2) is this determinant is given by: " << determinant1.CoFactor_ByIndex(2,2) << "\n";
  std::cout << "\n";
}

#endif //DETERMINANT_OPERATIONS_H