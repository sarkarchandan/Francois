#include "Matrix_Sanity.hpp"
#include "Matrix_Analytical.hpp"
#include "Matrix_Operations.hpp"
#include "Matrix_Utility.hpp"
#include "Determinant_Sanity.hpp"
#include "Determinant_Operations.hpp"
#include "Determinant_Utility.hpp"

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

  //#2.2 Analytical perspective of determinants
  /*
  * Determinant analytical testsuite defined in the file /tests/algebra_Determinant_AnalyticalTests.cpp demonstrates six of the fundamental properties of a determinant with the help of matrices which are,
   * The value of the determinant remains unchanged if its rows and columns are interchanged.
   * If, any two rows or columns of a determinant are interchanged then the sign of the determinant changes.
   * If, any two rows or columns of a determinant are identical(i.e. all corresponding elements are same) then value of the determinant is 0.
   * If, each element of a given row or column of a determinant is multiplied by the value k then the determinant is multiplied by the value k.
   * If, the elements of a row or column of a determinant are expressed as sum of two(or more) terms, then the determinant can be expressed as sum of two or more determinants.
   * If, to each row or column of a determinant, the equi-multiples of corresponding elements of other row (or column) are added, then the value of the determinant remains the same i.e. the value of the determinant remains the same if we apply the elementary operations Row[i] -> Row[i] + k * Row[j] or Column[i] -> Column[i] + k * Column[j].
  */

  //2.3 Examples of the operations group demonstrate some of the inherent operations which are usually performed in context of the determinant.
  //2.3.1 Determinant Operations Demo - Computing the value of the determinant, finding out the minors and cofactors in a determinant by index.
  Determinant_Demo_Operations();

  //2.4 Examples of the operations group demonstrate one of the utility methods implemented in context of determinant
  //2.4.1 Determinant Operations Demo - Computing area of triangle from non-collinear 2D coordinates.
  Determinant_Demo_Utility();


  return EXIT_SUCCESS;
}