#include <iostream>
#include "Matrix_Sanity.hpp"
#include "Matrix_Analytical.hpp"
#include "Matrix_Operations.hpp"

int main(int argc, const char **argv)
{
  //#1.1 Examples of sanity group demonstrate the matrix datatype along with its core components
  //#.1 Matrix Sanity Demo - Initialization of a simple matrices and subscripting
  Demo_Init();

  //#.2 Matrix Sanity Demo - Accessing the individual rows and columns of matrices and alternate initialization methods
  Demo_Components_AlternateInit();

  //#1.2 Examples of the analytical group demonstrate the mathematical classification of the matrix. In addition to that the respective test suite for matrix datatype throws some light on some of the fundamental properties of matrices.
  //#.1 Matrix Analytical Demo - Classification of matrices
  Demo_Classification();

  //#1.3 Examples of the operations group demonstrate of the basic operations on the matrix datatype.
  //#.1 Matrix Operations Demo - Arithmetic operations on matrices
  Demo_Arithmetic_Operations();

  //#.2 Matrix Operations Demo - Logical operations on matrices
  Demo_Logical_Operations();

  return EXIT_SUCCESS;
}