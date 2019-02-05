#include <iostream>
#include "Matrix_Sanity.hpp"

int main(int argc, const char **argv)
{
  //#1.1 Examples of sanity group demonstrate the matrix datatype along with its core components
  //#.1 Matrix Sanity Demo - Initialization of a simple matrices and subscripting
  Demo_Init();

  //#.2 Matrix Sanity Demo - Accessing the individual rows and columns of matrices and alternate initialization methods
  Demo_Components_AlternateInit();

  return EXIT_SUCCESS;
}