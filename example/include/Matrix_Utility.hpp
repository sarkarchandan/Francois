#ifndef MATRIX_UTILITY_H
#define MATRIX_UTILITY_H

#include <iostream>
#include "Matrix.hpp"

template<typename T>
std::ostream& operator <<(std::ostream& _stream, const std::vector<T>& _vector)
{
  _stream << "{";
  for(size_t _index = 0; _index < _vector.size(); _index += 1)
  {
    (_index < (_vector.size() - 1)) ? _stream << _vector[_index] << " " : _stream << _vector[_index];
  }
  _stream << "}";
  return _stream;
}

void Matrix_Demo_Utilities()
{
  /*
  * This code segment demonstrates some of the convenient utilities defined on the matrix datatype. These utilites provide ways to create matrices as per the need, provide ways to perform basic arithmetic operations on components like rows or columns, provide way to transform matrix elements, wrap or unwrap the matrix from or to one dimensioanl structures etc..
  */
 std::cout << "**Utilities for the matrix datatype**" << "\n";
 std::cout << "We can create a null matrix of a specified order using the algebra::Zeros(<number_of_rows>,<number_of_columns>) utility method" << "\n";
 const algebra::Matrix<int> zero_matrix = algebra::Zeros(3,4);
 std::cout << "A null matrix created with this method of order (3,4) is: " << zero_matrix;
 std::cout << "\n";

 std::cout << "Similarly we can also create a matrix having all elements being a specified integer number using the algebra::Ints(<number_of_rows>,<number_of_columns>,<specified_int_element>) utility method" << "\n";
 const algebra::Matrix<int> int_matrix = algebra::Ints(4,4,5);
 std::cout << "A square matrix of order (4) is created with all elements as 5 like this " << int_matrix;
 std::cout << "\n";

 /*
 * One might want to access each row or column 'independent of the matrix' as a whole and perform some arithmetic operations that manipulate each element of the given rows or columns. In general, some of the common arithmetic operations on individual rows or columns which are possible are
  ** Addition and subtraction of two rows or columns of equal lengths from each other
  
  * Addition of a scalar to each element of the row or column
  * Subtraction of a scalar to and from each element of the row or column
  * Multiplication of a scalar to each element of the row or column 
  * Division of each element of the row or column by a scalar
  * Modular division of each element of the row or column by a scalar
 * Two convenient functions For_EachRow and For_EachColumn, one for rows and one for columns are provided to access each row and column individually. These functions in turn takes another function as parameter and support the aformentioned arithmetic operations on the elements of row or column.
 * Important things to remember however, these functions extracts the rows or columns from the matrix. They do not modify the actual matrix. Modification of a matrix itself can be done with the elementary row and column operations.
 */
  //For instance here we are doubling each element of each row
  const algebra::Matrix<int> matrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::vector<algebra::Row<int>> manipulatedRows;
  manipulatedRows.reserve(3);
  matrix1.For_EachRow([&](const algebra::Row<int>& _row){
    manipulatedRows.emplace_back(2 * _row);
  });
  std::cout << "Given matrix: " << matrix1;
  std::cout << "Doubled rows now look like: " << manipulatedRows << "\n";
  std::cout << "\n";

  //Similarly here we are performing a modular division on each column by 2
  std::vector<algebra::Column<int>> manipulatedColumns;
  manipulatedColumns.reserve(4);
  matrix1.For_EachColumn([&](const algebra::Column<int>& _column){
    manipulatedColumns.emplace_back(_column % 2);
  });
  std::cout << "Once again the given matrix: " << matrix1;
  std::cout << "After modular division by 2 manipulated columns now look like: " << manipulatedColumns << "\n";
  std::cout << "\n";

  /*
  * While we have the functions in order to perform defined arithmetic operations on individual rows or columns one might need a convenient function to map one matrix to another matrix of the same order. There is a Map function which takes another function as parameter and apply the parameter function on each element before returning the transformed matrix.
  */
  const algebra::Matrix<int> matrix2 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> squared_matrix = matrix2.Map([&](const int& _element){
    return _element * _element;
  });
  std::cout << "Given matrix: " << matrix2;
  std::cout << "Mapped matrix having each element squared: " << squared_matrix;
  std::cout << "\n";

  const algebra::Matrix<int> matrix3 = {
    {1,2,4,0},
    {3,3,0,1},
    {6,2,8,1},
    {2,7,0,5}
  };
  const algebra::Matrix<int> negated_matrix = matrix3.Map([&](const int& _element){
    return -_element;
  });
  std::cout << "Given matrix: " << matrix3;
  std::cout << "Mapped matrix having each element negated: " << negated_matrix;
  std::cout << "\n";

  /*
  * One might need to unwrap a given matrix<T> into a one dimensional structure e.g., an array[T] or an std::vector<T> for various reasons and wrap back to matrix<T> from one dimensioanl structure. There are convenient methods to do the same. One can specify that wrapping and unwrapping should be done along row or along column.
  */
 const algebra::Matrix<int> matrix4 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  std::cout << "Given matrix: " << matrix4;
  const size_t expectedLength = matrix4.Order().first * matrix4.Order().second;
  int *outcomeArray1 = new int[expectedLength];
  int *outcomeArray2 = new int[expectedLength];
  algebra::MatrixToArray(matrix4,algebra::ExpansionType::E_AlongRow,outcomeArray1);
  algebra::MatrixToArray(matrix4,algebra::ExpansionType::E_AlongColumn,outcomeArray2);
  std::cout << "The matrix is unwrapped along row into: [";
  for(size_t _index = 0; _index < expectedLength; _index += 1)
    (_index < (expectedLength - 1)) ? std::cout << *(outcomeArray1 + _index) << " " : std::cout << *(outcomeArray1 + _index);
  std::cout << "]\n";
  std::cout << "The matrix is unwrapped along column into: [";
  for(size_t _index = 0; _index < expectedLength; _index += 1)
    (_index < (expectedLength - 1)) ? std::cout << *(outcomeArray2 + _index) << " " : std::cout << *(outcomeArray2 + _index);
  std::cout << "]\n";
  
  delete []outcomeArray1;
  delete []outcomeArray2;
  std::cout << "\n";

  const int givenArray[] = {1,7,13,2,8,14,3,9,15,4,10,16,5,11,17,6,12,18};
  const size_t givenArrayLength = sizeof(givenArray) / sizeof(int);
  std::cout << "Given array: [";
  for(size_t _index = 0; _index < givenArrayLength; _index += 1)
    (_index < (givenArrayLength - 1)) ? std::cout << *(givenArray + _index) << " " : std::cout << *(givenArray + _index);
  std::cout << "]\n";
  const std::pair<size_t,size_t> intendedMatrixOrder1 = std::make_pair<size_t,size_t>(3,6);
  const std::pair<size_t,size_t> intendedMatrixOrder2 = std::make_pair<size_t,size_t>(6,3);
  const algebra::Matrix<int> outcomeMatrix1 = algebra::ArrayToMatrix(givenArray,givenArrayLength,algebra::ContractionType::C_AlongRow,intendedMatrixOrder1);
  std::cout << "After wrapping the array to matrix along row for order (3,6) we get: " << outcomeMatrix1;
  const algebra::Matrix<int> outcomeMatrix2 = algebra::ArrayToMatrix(givenArray,givenArrayLength,algebra::ContractionType::C_AlongColumn,intendedMatrixOrder2);
  std::cout << "After wrapping the array to matrix along column for order (6,3) we get: " << outcomeMatrix2;
  std::cout << "\n";

  //Similarly one can wrap and unwrap a matrix<T> to and from std::vector<T> as well.
  const algebra::Matrix<int> matrix5 = {
    {1,2,3,4,5,6},
    {7,8,9,10,11,12},
    {13,14,15,16,17,18}
  };
  std::cout << "Given matrix: " << matrix5;
  const std::vector<int> expanded_along_row = algebra::MatrixToVector(matrix5,algebra::ExpansionType::E_AlongRow);
  const std::vector<int> expanded_along_column = algebra::MatrixToVector(matrix5,algebra::ExpansionType::E_AlongColumn);
  std::cout << "Expanded to vector along row: " << expanded_along_row << "\n";
  std::cout << "Expanded to vector along column: " << expanded_along_column << "\n";
  std::cout << "\n";

  const std::vector<int> givenVector = {1,7,13,2,8,14,3,9,15,4,10,16,5,11,17,6,12,18};
  std::cout << "Given vector: " << givenVector << "\n";
  const std::pair<size_t,size_t> intendedMatrixOrder3 = std::make_pair<size_t,size_t>(3,6);
  const std::pair<size_t,size_t> intendedMatrixOrder4 = std::make_pair<size_t,size_t>(6,3);
  const algebra::Matrix<int> outcomeMatrix3 = algebra::VectorToMatrix(givenVector,algebra::ContractionType::C_AlongRow,intendedMatrixOrder3);
  std::cout << "After wrapping the vector to matrix along row for order (3,6) we get: " << outcomeMatrix3;
  const algebra::Matrix<int> outcomeMatrix4 = algebra::VectorToMatrix(givenVector,algebra::ContractionType::C_AlongColumn,intendedMatrixOrder4);
  std::cout << "After wrapping the vector to matrix along row for order (6,3) we get: " << outcomeMatrix4;
  std::cout << "\n";
}

#endif //MATRIX_UTILITY_H