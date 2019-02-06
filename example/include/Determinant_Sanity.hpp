#ifndef DETERMINANT_SANITY_H
#define DETERMINANT_SANITY_H

#include <iostream>
#include "Determinant.hpp"

void Determinant_Demo_Init()
{
  /*
  * A simple determinant with real number elements can be initialized like below using the std::initializer_list. A determinant can also be initialized using a nested vector like this std::vector<std::vector<T>>. Later on two other options to initialize a determinant are demonstrated using vector of algebra::Row<T> amd algebra::Column<T> datatypes.
  * algebra::Determinant<T> uses a zero-based indexing and one can subscript determinants using (<row_index>,<column_index>) parenthesis operator in order to read or update individual elements.
  * algebra::Determinant<T> shares the same base class with algebra::determinant<T>. Therefore, their initialization methods are quite similar having the constraint that determinants can only be constructed with the equal number of rows and columns.
  ** For the time being, Determinant and its related operations only supports upto order 3. Work is being done to improve and overcome this limitation**.
  */
 std::cout << "**Initialization of simple determinants and subscripting**" << "\n";
 algebra::Determinant<int> determinant1 = {
    {1,2,3},
    {4,5,6},
    {9,5,8}
  };
  algebra::Determinant<double> determinant2 = {
    {3.5,1.9},
    {1.2,6.2}
  };

  std::cout << "An integer determinant of order: " << "(" << determinant1.Order().first << "," << determinant1.Order().second << ")" << determinant1;
  
  std::cout << "The element at the (0,2) position of this integer determinant is: " << determinant1(0,2) << "\n";
  std::cout << "The element at the (1,1) position of this integer determinant is: " << determinant1(1,1) << "\n";
  std::cout << "The element at the (2,2) position of this integer determinant is: " << determinant1(2,2) << "\n";
  std::cout << "Updating the elements of (0,3) , (1,1) and (2,2) positions with 10,11 and 12 respectively " << "\n";
  determinant1(0,2) = 10;
  determinant1(1,1) = 11;
  determinant1(2,2) = 12;
  std::cout << "Now the integer determinant is changed to: " << determinant1;
  

  std::cout << "\n";
  std::cout << "A double determinant of order: " << "(" << determinant2.Order().first << "," << determinant2.Order().second << ")" << determinant2;
  std::cout << "The element at the (0,0) position of this double determinant is: " << determinant2(0,0) << "\n";
  std::cout << "The element at the (1,0) position of this double determinant is: " << determinant2(1,0) << "\n";
  std::cout << "The element at the (1,1) position of this double determinant is: " << determinant2(1,1) << "\n";
  std::cout << "Updating the elements of (0,1) , (1,0) and (2,1) positions with 10.11, 11.12 and 12.13 respectively " << "\n";
  determinant2(0,0) = 10.11;
  determinant2(1,0) = 11.12;
  determinant2(1,1) = 12.13;
  std::cout << "Now the double determinant is changed to: " << determinant2;
}

void Determinant_Demo_Components_AlternateInit()
{
  /*
  * Rows and columns of a determinant can be separately accessed with vectors of algebra::Row<T> and algebra::Column<T> datatype similar to matrices. One can construct rows or columns individually and initialize a determinant with rows or columns. determinant initialized in this way behaves alike with the determinant initialized in the earlier example.
  */
  std::cout << "**Accessing individual rows and columns of determinants and alternate initialization**" << "\n";
  const algebra::Determinant<int> determinant1 = {
    {1,2,3},
    {4,5,6},
    {9,5,8}
  };
  const std::vector<algebra::Row<int>> determinant1_rows = determinant1.Rows();
  const std::vector<algebra::Column<int>> determinant1_columns = determinant1.Columns();
  std::cout << "A given determinant is: " << determinant1;
  std::cout << "Rows of this determinant are given by: " << determinant1_rows << "\n";
  std::cout << "and columns are given by: " << determinant1_columns << "\n";
  std::cout << "\n";

  const algebra::Row<int> row1 = {4,3,2};
  const algebra::Row<int> row2 = {8,7,7};
  const algebra::Row<int> row3 = {3,5,7};
  const std::vector<algebra::Row<int>> rows = {row1,row2,row3};
  const algebra::Determinant<int> determinant_constructed_from_rows = rows;
  std::cout << "We have created rows: " << rows << "\n";
  std::cout << "The determinant constructed from these rows having order " << "(" << determinant_constructed_from_rows.Order().first << "," << determinant_constructed_from_rows.Order().second << ")" << " is:" << determinant_constructed_from_rows;

  const algebra::Column<int> column1 = {4,3,2};
  const algebra::Column<int> column2 = {8,7,7};
  const algebra::Column<int> column3 = {3,5,7};
  const std::vector<algebra::Column<int>> columns = {column1,column2,column3};
  const algebra::Determinant<int> determinant_constructed_from_columns = columns;
  std::cout << "We have created columns: " << columns << "\n";
  std::cout << "The determinant constructed from these columns having order " << "(" << determinant_constructed_from_columns.Order().first << "," << determinant_constructed_from_columns.Order().second << ")" << " is: " << determinant_constructed_from_columns;
}

#endif //DETERMINANT_SANITY_H