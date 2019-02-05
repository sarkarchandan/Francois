#include "gtest/gtest.h"
#include "Determinant.hpp"
#include <memory>

TEST(DeterminantSanityTests, canInstantiateDeterminantWithInitializerListAndVector)
{
  const std::initializer_list<std::vector<int>> givenList1 = {
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  const std::vector<std::vector<int>> givenVectors1 = { 
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };

  EXPECT_NO_THROW(algebra::Determinant<int> {givenList1});
  EXPECT_NO_THROW(algebra::Determinant<int> {givenVectors1});

  const std::initializer_list<std::vector<double>> givenList2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15},
    {78.21,45.21,86.11}
  };

  const std::vector<std::vector<double>> givenVectors2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15},
    {78.21,45.21,86.11}
  };
  EXPECT_NO_THROW(algebra::Determinant<double> {givenList2});
  EXPECT_NO_THROW(algebra::Determinant<double> {givenVectors2});
}

TEST(DeterminantSanityTests, canInstantiateDeterminantsWithRowsAndColumns)
{
  const std::vector<algebra::Row<int>> giventRows1 = {{1,2,3},{4,5,6},{7,8,9}};
  const std::vector<algebra::Row<double>> givenRows2 = {{65.4,936.12,32.78},{47.1,93.15,78.15},{78.21,45.21,86.11}};
  EXPECT_NO_THROW(algebra::Determinant<int> {giventRows1});
  EXPECT_NO_THROW(algebra::Determinant<double> {givenRows2});
  
  const std::vector<algebra::Column<int>> givenColumns1 = {{1,2,3},{4,5,6},{7,8,9}};
  const std::vector<algebra::Column<double>> givenColumns2 = {{65.4,936.12,32.78},{47.1,93.15,78.15},{78.21,45.21,86.11}};
  EXPECT_NO_THROW(algebra::Determinant<int> {givenColumns1});
  EXPECT_NO_THROW(algebra::Determinant<double> {givenColumns2});
}

TEST(DeterminantSanityTests_ExceptionTest, canDetermineInvalidityForDeterminants)
{
  const std::initializer_list<std::vector<int>> givenList1 = {
    {1,2,3},
    {4,6,7}
  };
  const std::vector<std::vector<int>> givenVectors1 = { 
    {1,2,3},
    {4,6,7}
  };
  EXPECT_THROW(algebra::Determinant<int> {givenList1},std::invalid_argument);
  EXPECT_THROW(algebra::Determinant<int> {givenVectors1},std::invalid_argument);
  const std::initializer_list<std::vector<double>> givenList2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15}
  };
  const std::vector<std::vector<double>> givenVectors2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15}
  };
  EXPECT_THROW(algebra::Determinant<double> {givenList2},std::invalid_argument);
  EXPECT_THROW(algebra::Determinant<double> {givenVectors2},std::invalid_argument);

  const std::vector<algebra::Row<int>> giventRows1 = {{1,2,3},{4,5,6}};
  const std::vector<algebra::Row<double>> givenRows2 = {{65.4,936.12,32.78},{47.1,93.15,78.15}};
  EXPECT_THROW(algebra::Determinant<int> {giventRows1},std::invalid_argument);
  EXPECT_THROW(algebra::Determinant<double> {givenRows2},std::invalid_argument);
  
  const std::vector<algebra::Column<int>> givenColumns1 = {{1,2,3},{4,5,6}};
  const std::vector<algebra::Column<double>> givenColumns2 = {{65.4,936.12,32.78},{47.1,93.15,78.15}};
  EXPECT_THROW(algebra::Determinant<int> {givenColumns1},std::invalid_argument);
  EXPECT_THROW(algebra::Determinant<double> {givenColumns2},std::invalid_argument);
}

TEST(DeterminantSanityTests, canDetermineOrderOfDeterminant)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const std::pair<size_t,size_t> expectedOrder1 = std::make_pair<size_t,size_t>(3,3);
  ASSERT_TRUE(givenDeterminant1.Order() == expectedOrder1);
  const algebra::Determinant<int> givenDeterminant2 = {
    {1,2},
    {3,4}
  };
  const std::pair<size_t,size_t> expectedOrder2 = std::make_pair<size_t,size_t>(2,2);
  ASSERT_TRUE(givenDeterminant2.Order() == expectedOrder2);

  const algebra::Determinant<double> givenDeterminant3 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15},
    {78.21,45.21,86.11}
  };
  const std::pair<size_t,size_t> expectedOrder3 = std::make_pair<size_t,size_t>(3,3);
  ASSERT_TRUE(givenDeterminant3.Order() == expectedOrder3);
  const algebra::Determinant<double> givenDeterminant4 = {
    {65.4,936.12},
    {47.1,93.15}
  };
  const std::pair<size_t,size_t> expectedOrder4 = std::make_pair<size_t,size_t>(2,2);
  ASSERT_TRUE(givenDeterminant4.Order() == expectedOrder4);
}

TEST(DeterminantSanityTests, canAccessElementsOfDeterminantBySubscripting)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  ASSERT_EQ(givenDeterminant1(0,0),1);
  ASSERT_EQ(givenDeterminant1(0,2),3);
  ASSERT_EQ(givenDeterminant1(2,0),7);
  ASSERT_EQ(givenDeterminant1(2,2),9);
  ASSERT_EQ(givenDeterminant1(1,1),5);

  const algebra::Determinant<double> givenDeterminant2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15},
    {78.21,45.21,86.11}
  };

  ASSERT_DOUBLE_EQ(givenDeterminant2(0,0),65.4);
  ASSERT_DOUBLE_EQ(givenDeterminant2(0,2),32.78);
  ASSERT_DOUBLE_EQ(givenDeterminant2(2,0),78.21);
  ASSERT_DOUBLE_EQ(givenDeterminant2(2,2),86.11);
  ASSERT_DOUBLE_EQ(givenDeterminant2(1,1),93.15);
}

TEST(DeterminantSanityTests, canUpdateElementsOfDeterminantBySubscripting)
{
  algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  givenDeterminant1(0,1) = 12;
  givenDeterminant1(1,0) = 14;
  givenDeterminant1(1,2) = 16;
  givenDeterminant1(2,1) = 18;

  const algebra::Determinant<int> expectedDeterminant1 = {
    {1,12,3},
    {14,5,16},
    {7,18,9}
  };
  ASSERT_TRUE(givenDeterminant1 == expectedDeterminant1);

  algebra::Determinant<double> givenDeterminant2 = {
    {65.4,936.12,32.78},
    {47.1,93.15,78.15},
    {78.21,45.21,86.11}
  };

  givenDeterminant2(0,1) = 12.21;
  givenDeterminant2(1,0) = 14.41;
  givenDeterminant2(1,2) = 16.61;
  givenDeterminant2(2,1) = 18.81;

  const algebra::Determinant<double> expectedDeterminant2 = {
    {65.4,12.21,32.78},
    {14.41,93.15,16.61},
    {78.21,18.81,86.11}
  };
  ASSERT_TRUE(givenDeterminant2 == expectedDeterminant2);
}

TEST(DeterminantSanityTests_ExceptionTest, canDetermineOutOfRangeSubscriptingAttempts)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  EXPECT_THROW(givenDeterminant1(3,3),std::out_of_range);

  const algebra::Determinant<double> givenDeterminant2 = {
    {3.5,1.9,4.7},
    {1.2,6.2,8.1},
    {1.56,3.7,9.1}
  };
  EXPECT_THROW(givenDeterminant2(3,2),std::out_of_range);
}

TEST(DeterminantSanityTests,canDetermineRowsAndColumnsSeparately)
{
  const algebra::Determinant<int> givenDeterminant1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  const std::vector<algebra::Row<int>> rows = givenDeterminant1.Rows();
  ASSERT_EQ(rows.size(),3);
  const algebra::Row<int> testableRow0 {1,2,3};
  const algebra::Row<int> testableRow1 {4,5,6};
  const algebra::Row<int> testableRow2 {7,8,9};

  ASSERT_TRUE(rows[0] == testableRow0);
  ASSERT_TRUE(rows[1] == testableRow1);
  ASSERT_TRUE(rows[2] == testableRow2);

  const std::vector<algebra::Column<int>> columns = givenDeterminant1.Columns();
  ASSERT_EQ(columns.size(),3);
  const algebra::Column<int> testableColumn0 {1,4,7};
  const algebra::Column<int> testableColumn1 {2,5,8};
  const algebra::Column<int> testableColumn2 {3,6,9};

  ASSERT_TRUE(columns[0] == testableColumn0);
  ASSERT_TRUE(columns[1] == testableColumn1);
  ASSERT_TRUE(columns[2] == testableColumn2);
}

TEST(DeterminantSanityTests, canUpdateDeterminantWithCopyAssignmentOperator)
{
  algebra::Determinant<int> testableDeterminant1 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  const algebra::Determinant<int> testableDeterminant2 = {
    {13,14,15},
    {16,17,18},
    {19,20,21}
  };
  testableDeterminant1 = testableDeterminant2;
  const algebra::Determinant<int> expectedDeterminant1 = {
    {13,14,15},
    {16,17,18},
    {19,20,21}
  };
  ASSERT_TRUE(testableDeterminant1 == expectedDeterminant1);

  algebra::Determinant<double> testableDeterminant3 = {
    {23.65,12.54,19.64},
    {98.12,186.32,12.87},
    {98.123,76.12,984.12}
  };

  const algebra::Determinant<double> testableDeterminant4 = {
    {65.23,54.12,54.19},
    {12.98,43.186,87.12},
    {123.98,12.76,12.984}
  };
  testableDeterminant3 = testableDeterminant4;
  const algebra::Determinant<double> expectedDeterminant3 = {
    {65.23,54.12,54.19},
    {12.98,43.186,87.12},
    {123.98,12.76,12.984}
  };
  ASSERT_TRUE(testableDeterminant3 == expectedDeterminant3);
}

TEST(DeterminantSanityTests_ExceptionTest, canDetermineCopyAssignmentAttemptsForDeterminantsOfDifferentOrder)
{
  algebra::Determinant<int> testableDeterminant1 = {
    {1,2,3},
    {4,6,7},
    {9,10,11}
  };
  const algebra::Determinant<int> testableDeterminant2 = {
    {13,14},
    {17,18}
  };
  EXPECT_THROW(testableDeterminant1 = testableDeterminant2,std::length_error);

  algebra::Determinant<double> testableDeterminant3 = {
    {23.65,12.54,19.64},
    {98.12,186.32,12.87},
    {98.123,76.12,984.12}
  };

  const algebra::Determinant<double> testableDeterminant4 = {
    {65.23,54.12},
    {12.98,43.186}
  };
  EXPECT_THROW(testableDeterminant3 = testableDeterminant4,std::length_error);
}