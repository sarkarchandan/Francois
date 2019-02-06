#ifndef MATRIX_ANALYTICAL_H
#define MATRIX_ANALYTICAL_H

#include <iostream>
#include "Matrix.hpp"

void Demo_Classification()
{
  /*
  * Based on certain properties we can classify the matrices in certain types. This library offers convenient methods to check if a matrix is qualified to be of certain class of matrix. Efforts have been made to maintain the coherence between these methods with corresponding mathematical definitions of individual class of matrices.
  * In addition to this small demonstration the analytical testsuite of matrix datatype further illustrates some of the fundamental properties of matrices.
  */
  std::cout << "**Classification of matrices**" << "\n";
  const algebra::Matrix<int> matrix1 = {
    {5,1,4,7,8}
  };
  if(matrix1.IsRowMatrix())
    std::cout << "The matrix: " << matrix1 << "is an example of row matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int>  matrix2 = {
    {5},
    {1},
    {4},
    {7},
    {8}
  };
  if(matrix2.IsColumnMatrix())
    std::cout << "The matrix: " << matrix2 << "is an example of column matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix3 = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
  };
  if(matrix3.IsRectangularMatrix())
    std::cout << "The matrix: " << matrix3 << "is an example of rectangualr matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix4 = {
    {5,2,1},
    {7,1,3},
    {8,4,2}
  };
  if(matrix4.IsSquareMatrix())
    std::cout << "The matrix: " << matrix4 << "is an example of square matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix5 = {
    {5,0,0,0},
    {0,1,0,0},
    {0,0,2,0},
    {0,0,0,2}
  };
  if(matrix5.IsDiagonalMatrix())
    std::cout << "The matrix: " << matrix5 << "is an example of diagonal matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix6 = {
    {4,0,0,0},
    {0,4,0,0},
    {0,0,4,0},
    {0,0,0,4},
  };
  if(matrix6.IsScalarMatrix())
    std::cout << "The matrix: " << matrix6 << "is an example of scalar matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix7 = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1}
  };
  if(matrix7.IsIdentityMatrix())
    std::cout << "The matrix: " << matrix7 << "is an example of identity matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix8 = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
  if(matrix8.IsNullMatrix())
    std::cout << "The matrix: " << matrix8 << "is an example of null matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix9 = {
    {4,5,8,1},
    {0,6,7,1},
    {0,0,2,9},
    {0,0,0,8}
  };
  if(matrix9.IsUpperTriangularMatrix())
    std::cout << "The matrix: " << matrix9 << "is an upper-triangular matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix10 = {
    {4,0,0,0},
    {1,6,0,0},
    {9,6,2,0},
    {3,5,8,8}
  };
  if(matrix10.IsLowerTriangularMatrix())
    std::cout << "The matrix: " << matrix10 << "is a lower-triangular matrix." << "\n";
  std::cout << "\n";
  const algebra::Matrix<int> matrix11 = {
    {4,6,8,10},
    {3,5,7,9},
    {8,5,3,6},
    {2,0,5,1}
  };
  std::cout << "The matrix: " << matrix11 << "is a given square matrix." << "\n";
  std::cout << "The trace of this square matrix is given by: " << matrix11.Trace() << "\n";
  std::cout << "\n";
  
  const algebra::Matrix<int> matrix12 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  const algebra::Matrix<int> matrix13 = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
  if(matrix12 == matrix13)
    std::cout << "The matrix " << matrix12 << "and the matrix " << matrix13 << "are equal." << "\n";
  std::cout << "\n";

  const algebra::Matrix<int> matrix14 = {
    {1,-1,5},
    {-1,2,1},
    {5,1,3}
  };
  if(matrix14.IsSymmetricMatrix())
    std::cout << "The matrix " << matrix14 << "is an example of symmetric matrix." << "\n";
  std::cout << "\n";

  const algebra::Matrix<int> matrix15 = {
    {0,1,-1},
    {-1,0,1},
    {1,-1,0}
  };
  if(matrix15.IsSkewSymmetricMatrix())
    std::cout << "The matrix " << matrix15 << "is an example of skew-symmetric matrix." << "\n";
  std::cout << "\n";

  const algebra::Matrix<int> matrix16 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  if(matrix16.IsSingularMatrix())
    std::cout << "The matrix " << matrix16 << "is an example of the singular matrix." << "\n";
  std::cout << "\n";

  const algebra::Matrix<int> matrix17 = {
    {-3,-3,-4},
    {0,1,1},
    {4,3,4}
  };
  if(matrix17.IsInvertibleMatrix())
    std::cout << "The matrix " << matrix17 << "is an example of non-singular invertible matrix." << "\n";
  std::cout << "\n";
}


#endif //MATRIX_ANALYTICAL_H