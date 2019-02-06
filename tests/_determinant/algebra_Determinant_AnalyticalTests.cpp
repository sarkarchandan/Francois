#include "gtest/gtest.h"
#include "Matrix.hpp"
#include "Determinant.hpp"

//Validation for properties of determinant//

//#1 The value of the determinant remains unchanged if its rows and columns are interchanged.
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_1)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  const int computedDeterminantValue1 = givenDeterminant1.Value();
  const algebra::Matrix<int> givenTransposedMatrix1 = givenMatrix1.Transpose();
  const algebra::Determinant<int> givenTransposedDeterminant1 = givenTransposedMatrix1.Rows();
  const int computedTransposedDeterminantValue1 = givenTransposedDeterminant1.Value();
  ASSERT_EQ(computedDeterminantValue1,computedTransposedDeterminantValue1);

  const algebra::Matrix<int> givenmatrix2 = {
    {3,-4,5},
    {1,1,-2},
    {2,3,1}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  const int computedDeterminantValue2 = givenDeterminant2.Value();
  const algebra::Matrix<int> givenTransposedMatrix2 = givenmatrix2.Transpose();
  const algebra::Determinant<int> givenTransposedDeterminant2 = givenTransposedMatrix2.Rows();
  const int computedTransposedDeterminantValue2 = givenTransposedDeterminant2.Value();
  ASSERT_EQ(computedDeterminantValue2,computedTransposedDeterminantValue2);
}

//#2 If any two rows or columns of a determinant are interchanged then the sign of the determinant changes.
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_2)
{
  algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  const int computedDeterminantValue1 = givenDeterminant1.Value();
  givenMatrix1.ElementaryRowOperation_Interchange_ByIndex(0,2);
  const algebra::Determinant<int> changedDeterminant1 = givenMatrix1.Rows();
  const int computedChangedDeterminantValue1 = changedDeterminant1.Value();
  ASSERT_EQ(computedDeterminantValue1,-computedChangedDeterminantValue1);

  algebra::Matrix<int> givenmatrix2 = {
    {3,-4,5},
    {1,1,-2},
    {2,3,1}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  const int computedDeterminantValue2 = givenDeterminant2.Value();
  givenmatrix2.ElementaryColumnOperation_Interchange_ByIndex(0,2);
  const algebra::Determinant<int> changedDeterminant2 = givenmatrix2.Rows();
  const int computedChangedDeterminantValue2 = changedDeterminant2.Value();
  ASSERT_EQ(computedDeterminantValue2,-computedChangedDeterminantValue2);
}

//#3 If any two rows or columns of a determinant are identical(i.e. all corresponding elements are same) then value of the determinant is 0.
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_3)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-1,-2}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  const int computedDeterminantValue1 = givenDeterminant1.Value();
  ASSERT_EQ(computedDeterminantValue1,0);

  const algebra::Matrix<int> givenmatrix2 = {
    {3,-4,3},
    {1,1,1},
    {2,3,2}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  const int computedDeterminantValue2 = givenDeterminant2.Value();
  ASSERT_EQ(computedDeterminantValue2,0);
}

//#4 If each element of a given row or column of a determinant is multiplied by the value k then the determinant is multiplied by the value k.
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_4)
{
  algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  const int computedDeterminantValue1 = givenDeterminant1.Value();
  givenMatrix1.ElementaryRowOperation_MultiplicationByNonZeroScalar_ByIndex(4,0);
  const algebra::Determinant<int> changedDeterminant1 = givenMatrix1.Rows();
  const int computedChangedDeterminantValue1 = changedDeterminant1.Value();
  ASSERT_EQ(computedChangedDeterminantValue1,4 * computedDeterminantValue1);

  algebra::Matrix<int> givenmatrix2 = {
    {3,-4,5},
    {1,1,-2},
    {2,3,1}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  const int computedDeterminantValue2 = givenDeterminant2.Value();
  givenmatrix2.ElementaryColumnOperation_MultiplicationByNonZeroScalar_ByIndex(3,2);
  const algebra::Determinant<int> changedDeterminant2 = givenmatrix2.Rows();
  const int computedChangedDeterminantValue2 = changedDeterminant2.Value();
  ASSERT_EQ(computedChangedDeterminantValue2,3 * computedDeterminantValue2);
}

//#5 If the elements of a row or column of a determinant are expressed as sum of two(or more) terms, then the determinant can be expressed as sum of two or more determinants.
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_5)
{
  const algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  const algebra::Matrix<int> componentMatrix1_first = {
    {1,-1,-1},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> componentMatrix1_first_determinant = componentMatrix1_first.Rows();
  const algebra::Matrix<int> componentMatrix1_second = {
    {2,0,-1},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> componentMatrix1_second_determinant = componentMatrix1_second.Rows();
  ASSERT_EQ(givenDeterminant1.Value(),(componentMatrix1_first_determinant.Value() + componentMatrix1_second_determinant.Value()));

  const algebra::Matrix<int> givenmatrix2 = {
    {3,-4,5},
    {1,1,-2},
    {2,3,1}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  const algebra::Matrix<int> componentMatrix2_first = {
    {3,-4,3},
    {1,1,-1},
    {2,3,0}
  };
  const algebra::Determinant<int> componentMatrix2_first_determinant = componentMatrix2_first.Rows();
  const algebra::Matrix<int> componentMatrix2_second = {
    {3,-4,2},
    {1,1,-1},
    {2,3,1}
  };
  const algebra::Determinant<int> componentMatrix2_second_determinant = componentMatrix2_second.Rows();
  ASSERT_EQ(givenDeterminant2.Value(),(componentMatrix2_first_determinant.Value() + componentMatrix2_second_determinant.Value()));
}

//#6 If, to each row or column of a determinant, the equi-multiples of corresponding elements of other row (or column) are added, then the value of the determinant remains the same i.e. the value of the determinant remains the same if we apply the elementary operations Row[i] -> Row[i] + k * Row[j] or Column[i] -> Column[i] + k * Column[j]
TEST(DeterminantAnalyticalTests, canValidateDeterminantProperty_6)
{
  algebra::Matrix<int> givenMatrix1 = {
    {3,-1,-2},
    {0,0,-1},
    {3,-5,0}
  };
  const algebra::Determinant<int> givenDeterminant1 = givenMatrix1.Rows();
  givenMatrix1.ElementaryRowOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(2,4,0);
  const algebra::Determinant<int> changedDeterminant1 = givenMatrix1.Rows();
  ASSERT_EQ(givenDeterminant1.Value(),changedDeterminant1.Value());

  algebra::Matrix<int> givenmatrix2 = {
    {3,-4,5},
    {1,1,-2},
    {2,3,1}
  };
  const algebra::Determinant<int> givenDeterminant2 = givenmatrix2.Rows();
  givenmatrix2.ElementaryColumnOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(1,3,2);
  const algebra::Determinant<int> changedDeterminant2 = givenmatrix2.Rows();
  ASSERT_EQ(givenDeterminant2.Value(),changedDeterminant2.Value());
}
