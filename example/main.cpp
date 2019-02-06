#include "Matrix_Sanity.hpp"
#include "Matrix_Analytical.hpp"
#include "Matrix_Operations.hpp"
#include "Matrix_Utility.hpp"
#include "Determinant_Sanity.hpp"

int main(int argc, const char **argv)
{
  //Matrix
  //#1.1 Examples of sanity group demonstrate the matrix datatype along with its core components
  //#1.1.1 Matrix Sanity Demo - Initialization of a simple matrices and subscripting
  Matrix_Demo_Init();

  //#1.1.2 Matrix Sanity Demo - Accessing the individual rows and columns of matrices and alternate initialization methods
  Matrix_Demo_Components_AlternateInit();

  //#1.2 Examples of the analytical group demonstrate the mathematical classification of the matrix. In addition to that the respective test suite for matrix datatype throws some light on some of the fundamental properties of matrices.
  //#1.2.1 Matrix Analytical Demo - Classification of matrices
  Matrix_Demo_Classification();

  //#1.3 Examples of the operations group demonstrate the basic operations on the matrix datatype.
  //#1.3.1 Matrix Operations Demo - Arithmetic operations on matrices
  Matrix_Demo_Arithmetic_Operations();

  //#1.3.2 Matrix Operations Demo - Logical operations on matrices
  Matrix_Demo_Logical_Operations();

  //#1.4 Examples of the utility group demonstrate some of the useful utilities, provided based on matrix datatype
  //#1.4.1 Matrix Utility Demo - Convenient utilities of matrix which help is creating or transforming matrices as per needs.
  Matrix_Demo_Utilities();

  //Determinants - For the time being, Determinant and its related operations only supports upto order 3. Work is being done to improve and overcome this limitation.
  //#2.1 Examples of sanity group demonstrate the determinant datatype along with its core components
  //#2.1.1 Determinant Sanity Demo - Initialization of simple determinants and subscripting
  Determinant_Demo_Init();

  //#2.1.2 Determinant Sanity Demo - Accessing the individual rows and columns of determinants and alternate initialization methods
  Determinant_Demo_Components_AlternateInit();


  return EXIT_SUCCESS;
}