#ifndef MATRIX_SANITY
#define MATRIX_SANITY

#include "Matrix.hpp"

void Demo_Init()
{
  /*
  * A simple matrix with real number elements can be initialized like below using the std::initializer_list. A matrix can also be initialized using a nested vector like this std::vector<std::vector<T>>. Later on two other options to initialize a matrix are demonstrated using vector of algebra::Row<T> amd algebra::Column<T> datatypes.
  * algebra::Matrix<T> uses a zero-based indexing and one can subscript matrices using (<row_index>,<column_index>) parenthesis operator in order to read or update individual elements.
  */
  std::cout << "**Initialization of a simple matrices and subscripting**" << "\n";
  algebra::Matrix<int> matrix1 = {
    {1,2,3,4,5},
    {4,5,6,3,2},
    {9,5,8,1,4}
  };
  algebra::Matrix<double> matrix2 = {
    {3.5,1.9},
    {1.2,6.2},
    {1.56,3.7}
  };

  std::cout << "An integer matrix of order: " << "(" << matrix1.Order().first << "," << matrix1.Order().second << ")" << matrix1;
  
  std::cout << "The element at the (0,3) position of this integer matrix is: " << matrix1(0,3) << "\n";
  std::cout << "The element at the (1,1) position of this integer matrix is: " << matrix1(1,1) << "\n";
  std::cout << "The element at the (2,2) position of this integer matrix is: " << matrix1(2,2) << "\n";
  std::cout << "Updating the elements of (0,3) , (1,1) and (2,2) positions with 10,11 and 12 respectively " << "\n";
  matrix1(0,3) = 10;
  matrix1(1,1) = 11;
  matrix1(2,2) = 12;
  std::cout << "Now the integer matrix is changed to: " << matrix1;
  

  std::cout << "\n";
  std::cout << "A double matrix of order: " << "(" << matrix2.Order().first << "," << matrix2.Order().second << ")" << matrix2;
  std::cout << "The element at the (0,1) position of this double matrix is: " << matrix2(0,1) << "\n";
  std::cout << "The element at the (1,0) position of this double matrix is: " << matrix2(1,0) << "\n";
  std::cout << "The element at the (2,1) position of this double matrix is: " << matrix2(2,1) << "\n";
  std::cout << "Updating the elements of (0,1) , (1,0) and (2,1) positions with 10.11, 11.12 and 12.13 respectively " << "\n";
  matrix2(0,1) = 10.11;
  matrix2(1,0) = 11.12;
  matrix2(2,1) = 12.13;
  std::cout << "Now the double matrix is changed to: " << matrix2;
}

void Demo_Components_AlternateInit()
{
  /*
  * Rows and columns of a matrix can be separately accessed with vectors of algebra::Row<T> and algebra::Column<T> datatype. One can construct rows or columns individually and initialize a matrix with rows or columns. Matrix initialized in this way behaves alike with the matrix initialized in the earlier example.
  */
  std::cout << "**Accessing individual rows and columns of matrices and alternate initialization**" << "\n";
  const algebra::Matrix<int> matrix1 = {
    {1,2,3,4},
    {4,5,6,3},
    {9,5,8,1}
  };
  const std::vector<algebra::Row<int>> matrix1_rows = matrix1.Rows();
  const std::vector<algebra::Column<int>> matrix1_columns = matrix1.Columns();
  std::cout << "A given matrix is: " << matrix1;
  std::cout << "Rows of this matrix are given by: " << matrix1_rows << "\n";
  std::cout << "and columns are given by: " << matrix1_columns << "\n";
  std::cout << "\n";

  const algebra::Row<int> row1 = {4,3,2,1};
  const algebra::Row<int> row2 = {8,7,7,5};
  const algebra::Row<int> row3 = {3,5,7,9};
  const std::vector<algebra::Row<int>> rows = {row1,row2,row3};
  const algebra::Matrix<int> matrix_constructed_from_rows = rows;
  std::cout << "We have created rows: " << rows << "\n";
  std::cout << "The matrix constructed from these rows having order " << "(" << matrix_constructed_from_rows.Order().first << "," << matrix_constructed_from_rows.Order().second << ")" << " is:" << matrix_constructed_from_rows;

  const algebra::Column<int> column1 = {4,3,2,1};
  const algebra::Column<int> column2 = {8,7,7,5};
  const algebra::Column<int> column3 = {3,5,7,9};
  const std::vector<algebra::Column<int>> columns = {column1,column2,column3};
  const algebra::Matrix<int> matrix_constructed_from_columns = columns;
  std::cout << "We have created columns: " << columns << "\n";
  std::cout << "The matrix constructed from these columns having order " << "(" << matrix_constructed_from_columns.Order().first << "," << matrix_constructed_from_columns.Order().second << ")" << " is: " << matrix_constructed_from_columns;
}

#endif //MATRIX_SANITY