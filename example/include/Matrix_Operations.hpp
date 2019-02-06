#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <iostream>
#include "Matrix.hpp"

void Matrix_Demo_Arithmetic_Operations()
{
  /*
  * This code segment demonstrate some of the fundamental arithmetic operations of matrices. These operations have several constraints that needs to be satisfied by the operand matrices. The respective tesuite vividly describes these constraints and their implications.
  */
  std::cout << "**Demonstrate some of the fundamental arithmetic operations**" << "\n";
  const algebra::Matrix<int> matrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> matrix2 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  const algebra::Matrix<int> sum = matrix1 + matrix2;
  std::cout << "Given matrix: " << matrix1;
  std::cout << "Given matrix: " << matrix2;
  std::cout << "Sum of these two matrices is: " << sum;
  std::cout << "\n";

  const algebra::Matrix<int> matrix3 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> matrix4 = {
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  const algebra::Matrix<int> difference = matrix3 - matrix4;
  std::cout << "Given matrix: " << matrix3;
  std::cout << "Given matrix: " << matrix4;
  std::cout << "Difference of these two matrices is: " << difference;
  std::cout << "\n";

  const algebra::Matrix<int> matrix5 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> scalarProduct = 4 * matrix5;
  std::cout << "Given matrix: " << matrix5;
  std::cout << "When this matrix is multipled by the scalar quantity 4 the result is: " << scalarProduct;
  std::cout << "\n";

  const algebra::Matrix<int> matrix6 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  const algebra::Matrix<int> matrix7 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  std::cout << "Given matrix: " << matrix6;
  std::cout << "Given matrix: " << matrix7;
  const algebra::Matrix<int> matrixProduct = matrix6 * matrix7;
  std::cout << "The result of multiplication of the first matrix with the second is: " << matrixProduct;
  std::cout << "\n";
}

void Matrix_Demo_Logical_Operations()
{
  /*
  * This code segment demonstrates some of the common logical operations that can be performed on matrices. This includes computing transpose of a matrix, performing elementary operations on rows or columns, finding inverse of an invertible matrix etc.. 
  ** Some of the capabilities which depends upon the algebra::Determinant<T> datatype e.g., finding adjoint matrices or inverse matrices are limited to matrices of order 3 for the time being. Work is in progress to improve and overcome these limitations.**
  * In addition to this demo the respective test suite comprehensively describes these capabilities.
  */
  std::cout << "**Demonstrate some of the fundamental logical operations**" << "\n";
  const algebra::Matrix<int> matrix1 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix1;
  std::cout << "Its transpose is given by: " << matrix1.Transpose();
  std::cout << "\n";

  algebra::Matrix<int> matrix2 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix2;
  std::cout << "Performing row elementary operations - Interchange first and third row." << "\n";
  matrix2.ElementaryRowOperation_Interchange_ByIndex(0,2);
  std::cout << "The result is: " << matrix2;
  std::cout << "\n";

  algebra::Matrix<int> matrix3 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix3;
  std::cout << "Performing row elementary operation - Multiply second row with a scalar value 4." << "\n";
  matrix3.ElementaryRowOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
  std::cout << "The result is: " << matrix3;
  std::cout << "\n";

  algebra::Matrix<int> matrix4 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix4;
  std::cout << "Performing row elementary operation - Multiply third row with 4 and add to the first row." << "\n";
  matrix4.ElementaryRowOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
  std::cout << "The result is: " << matrix4;
  std::cout << "\n";

  algebra::Matrix<int> matrix5 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix5;
  std::cout << "Performing column elementary operation - Interchange first and fourth column." << "\n";
  matrix5.ElementaryColumnOperation_Interchange_ByIndex(0,3);
  std::cout << "The result is: " << matrix5;
  std::cout << "\n";

  algebra::Matrix<int> matrix6 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix6;
  std::cout << "Performing column elementary operation - Multiply second column by 4." << "\n";
  matrix6.ElementaryColumnOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
  std::cout << "The result is: " << matrix6;
  std::cout << "\n";

  algebra::Matrix<int> matrix7 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  std::cout << "Given matrix: " << matrix7;
  std::cout << "Performing column elementary operation - Multiply third column by 4 and add to first column." << "\n";
  matrix7.ElementaryColumnOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
  std::cout << "The result is: " << matrix7;
  std::cout << "\n";

  const algebra::Matrix<int> matrix8 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const algebra::Matrix<int> adjointMatrix = algebra::FindAdjointMatrixFor(matrix8);
  std::cout << "Adjoint matrix for the matrix " << matrix8 << "is given by " << adjointMatrix;
  std::cout << "\n";

  const algebra::Matrix<int> matrix9 = {
    {1,-1,2},
    {0,2,-3},
    {3,-2,4}
  };
  const algebra::Matrix<int> invertedMatrix = algebra::Invert(matrix9);
  std::cout << "Inverse matrix of the matrix " << matrix9 << "is given by " << invertedMatrix;
  std::cout << "\n";
}

#endif //MATRIX_OPERATIONS_H