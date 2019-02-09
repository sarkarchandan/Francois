# Francois
#### This is a library written in C++, using STL containers and algorithms in order to provide implementations for some of the core structures of the linear algebra,  starting with the Matrix and Determinants. Relevant concepts and structures are being added. This library attempts to draw a coherence between the mathematical properties of these structures and their respective implementations in programming. At the same time, it provides some convenient methods to create, transform, and utilize these structures. It uses the _algebra_ namespace to provide implementations for all of its features. C++ static assertion is implemented in order to restrict its use only for the datatypes representing real numbers for the time being. A separate extension is being defined in order to explore more possibilities of working with custom datatypes, involving numeric computations.

#### Furthermore,  it is an interface library which uses CMake build system to build and integrate the [googletest](https://github.com/google/googletest "Googletest - Google Testing and Mocking Framework") in order to enable testing. All cases of input parameters which violate the mathematical logic behind the structures are handled with std::exception and its child types. Following are the core datatypes of the library.

## algebra::ElementSequence 
##### ElementSequence is the most fundamental structure in the algebra namespace which, represents any one dimensional sequence of real numbers. ElementSequence uses protected initializers in order to prevent users from instantiating this type. Therefore, it rather works as an internal base type which encapsulates the management and interaction with the data structure it uses behind the scene.

## algebra::Row & algebra::Column
##### Both Row and Column datatypes inherit from the ElementSequence and represent the rows and the columns of a matrix or determinant. Therefore, they independently support several convenient arithmetic operations while at the same time sharing the same data structure behind the scene. Defining these types individually makes it easier to implement several other more complex operations e.g., multiplication two matrices. Both algebra::Row and algebra::Column offer public initializers and some of the arithmetic operations they support are

```
* Addition and subtraction of two rows or columns of equal lengths from each other.
* Multiplication between a row and a column of equal length. 
* Addition of a scalar to each element of the row or column.
* Subtraction of a scalar to and from each element of the row or column.
* Multiplication of a scalar to each element of the row or column.
* Division of each element of the row or column by a scalar.
* Modular division of each element of the row or column by a scalar.
```

## algebra::MultiSequence
##### Similar to the ElementSequence, MultiSequence represents a two dimensional sequence of real numbers, manages the internal data structure. It enforces some constraints and offers some properties on the two-dimensional sequence which qualify itself as the base type of matrix and determinant. It provides access to its internal data structure in terms of collections of algebra::Row and algebra::Column as well as subscripting and defines the equality of two MultiSequence types. These features are used repeatedly further in matrix and determinant. Furthermore, it implements the mathematical concepts of elementary operations on matrices and determinants. These operations are further shared by both the child types.

## algebra::Matrix
##### Inheriting directly from the MultiSequence, matrix datatype encapsulates the classification of matrices as well as implements fundamental operations between two matrices such as 

```
* Addition and subtraction of two matrices.
* Multiplication of a matrix by a scalar.
* Multiplication of two matrices which are compatible for the operation.
* Adjoint of a matrix (possible upto order 3 for now).
* Inverse of a matrix (possible upto order 3 for now).
* Transpose of a matrix.
* Elementary Row and Column operations on a matrix.
```

##### Matrix datatype can be instantiated using the C++ construct std::initializer_list like this

```cpp
 const algebra::Matrix<int> matrix1 = {
  {1,2,4,0},
  {3,3,0,1},
  {6,2,8,1},
  {2,7,0,5}
 };
  
 //Alternate types that can be used for initialization
 std::vector<std::vector<T>> //T is type of a real number
 std::vector<algebra::Row<T>> //T is type of a real number
 std::vector<algebra::Column<T>> //T is type of a real number
 //e.g.
 const std::vector<algebra::Column<double>> columns = {{65.4,36.12,90.23,65.78},{47.1,93.15,81.32,43.98}};
 const algebra::Matrix<double> matrix2 = columns;
 //will result in matrix
  65.4  47.1
  36.12 93.15
  90.23 81.32
  65.78 43.98

```

##### Arithmetic and logical operations between two matrices could be performed like this

```cpp
const algebra::Matrix<int> givenMatrix1 = {
 {1,2,3,4},
 {5,6,7,8},
 {9,10,11,12}
};
const algebra::Matrix<int> givenMatrix2 = {
 {13,14,15,16},
 {17,18,19,20},
 {21,22,23,24}
};
const algebra::Matrix<int> sumOfIntMatrices = givenMatrix1 + givenMatrix2;
//will result a matrix
  14 16 18 20
  22 24 26 28
  30 32 34 36
const algebra::Matrix<int> differenceOfTwoMatrices = givenMatrix1 - givenMatrix2;
//will result in a matrix
  -12 -12 -12 -12
  -12 -12 -12 -12
  -12 -12 -12 -12
const algebra::Matrix<int> productMatrix1 = givenMatrix1 * 4;
//will result in a matrix
  4 8 12 16
  20 24 28 32
  36 40 44 48

const algebra::Matrix<int> givenMatrix3 = {
 {1,2,3,4},
 {5,6,7,8},
 {9,10,11,12}
};
const algebra::Matrix<int> givenMatrix4 = {
 {1,2,3,4},
 {5,6,7,8},
 {9,10,11,12},
 {13,14,15,16}
};
const algebra::Matrix<int> productMatrix2 = givenMatrix3 * givenMatrix4;
//will result in matrix of order (3,4)
  90 100 110 120
  202 228 254 280
  314 356 398 440
  
//If two matrics are provided which are not compatible for multiplication in terms of their respective orders an exception would be thrown with the appropriate reason.

const algebra::Matrix<int> givenMatrix5 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
const algebra::Matrix<int> transposeMatrix5 = givenMatrix5.Transpose();
//transposeMatrix5  will result in the matrix of order (4,3)
  1 5 9
  2 6 10
  3 7 11
  4 8 12

```

##### algebra::Matrix datatype also provides several operations with the help of algebra::Determinant datatype e.g., deriving adjoint and inverse of a matrix. The library incorporates a detailed test suite and an example directory which demonstrate all possible operations with an algebra::Matrix datatype.

## algebra::Determinant
##### Likewise the Matrix, algebra::Determinant datatype also inherits from the MultiSequence base type. Therefore, they share the same internal data structure and some of the properties and operations with the Matrix e.g., subscripts for elements, order and the elementary operations on rows and columns. The main reason to establish algebra::Determinant as a type of its own is to maintain the coherence with the mathematical structures. Furthermore, constructors of determinants enforce further constraints on the two-dimensional sequence compared to matrices. Determinant datatype defines some of its relevant constructs e.g., value, minors, and co-factors. These constructs, in turn, are used to define an invertible matrix and compute the inverse of a matrix. The library incorporates a detailed test suite and an example directory which demonstrate all possible operations with an algebra:: Determinant datatype.

##### For the time being the initialization of the algebra::Determinant datatype and all other related operations e.g., determining minors, co-factors, adjoint matrices, and inverse matrices are possible up to order 3 and below. Work is in progress to improve and overcome this limitation. This limitation does not apply to other operations with matrices.

##### Both algebra::Matrix and algebra::Determinant datatypes support basic row and column elementary operations like this

```cpp
//Elementary Row Operations

//#1 Row[i] <-> Row[j]
algebra::Matrix<int> givenMatrix1 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix1.ElementaryRowOperation_Interchange_ByIndex(0,2);
//givenMatrix1 is now
  9 10 11 12
  5 6 7 8
  1 2 3 4
  
//#2 Row[i] -> k * Row[i]
algebra::Matrix<int> givenMatrix2 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix2.ElementaryRowOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
//givenMatrix2 is now
  1 2 3 4
  20 24 28 32
  9 10 11 12

//#3 Row[i] -> Row[i] + k * Row[j]
algebra::Matrix<int> givenMatrix3 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix3.ElementaryRowOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
//givenMatrix3 is now
  37 42 47 52
  5 6 7 8
  9 10 11 12

//Elementary Column Operations

//#1 Column[i] <-> Column[j]
algebra::Matrix<int> givenMatrix4 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix4.ElementaryColumnOperation_Interchange_ByIndex(0,3);
//givenmatrix4 is now
  4 2 3 1
  8 6 7 5
  12 10 11 9

//#2 Column[i] -> k * Column[i]
algebra::Matrix<int> givenMatrix5 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix5.ElementaryColumnOperation_MultiplicationByNonZeroScalar_ByIndex(4,1);
//givenMatrix5 is now
  1 8 3 4
  5 24 7 8
  9 40 11 12

//#3 Column[i] -> Column[i] + k * Column[j]
algebra::Matrix<int> givenMatrix6 = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
};
givenMatrix6.ElementaryColumnOperation_AdditionOfAnotherMultipliedByScalar_ByIndex(0,4,2);
//givenMatrix6 is now
  13 2 3 4
  33 6 7 8
  53 10 11 12

```

##### All possible arithmetic and logical operations with the algebra::Matrix and algebra::Determinant datatypes are validated and documented in the integrated test suite and examples.

## Utility Methods
##### The library offers several utility methods to create and transform matrices. Some of these methods are inspired by other libraries. The utility test suite and examples directory demonstrate the use of these methods vividly. Some of these methods are given below

```cpp
//algebra::Zeros(<size_t>,<size_t>) can be used to create a null matrix of specified order.
const algebra::Matrix<int> null_matrix = algebra::Zeros(3,4);
//will result in a null matrix of order(3,4)
 0 0 0 0
 0 0 0 0
 0 0 0 0
 
//algebra::Ints(<size_t>,<size_t>,<int>) can be  used to create a matrix of specified order and the given integer  
const algebra::Matrix<int> custom_matrix = algebra::Ints(4,4,5);
//will result in 
 5 5 5 5
 5 5 5 5
 5 5 5 5
 5 5 5 5
 
const algebra::Matrix<int> matrix1 = {
 {1,2,3,4},
 {5,6,7,8},
 {9,10,11,12}
};

//Yields each row of the matrix in each iteration and applies the passed in function on the row. Permissible operations on algebra::Row<T> are listed above.
//Does not modify the actual matrix.

std::vector<algebra::Row<int>> modified_rows;
modified_rows.reserve(3);
matrix1.For_EachRow([&](const algebra::Row<int>& _row){
  modified_rows.emplace_back(2 * _row);
});
//std::vector modified_rows now contains {{2,4,6,8},{10,12,14,16},{18,20,22,24}}


//Yields each column of the matrix in each iteration and applies the passed in function on the column. Permissible operations on algebra::Column<T> are listed above.
//Does not modify the actual matrix.

std::vector<algebra::Column<int>> modified_columns;
modified_columns.reserve(4);
matrix1.For_EachColumn([&](const algebra::Column<int>& _column){
  modified_columns.emplace_back(_column % 2);
});
//std::vector modified_columns now contains {{1,1,1},{0,0,0},{1,1,1},{0,0,0}}


const algebra::Matrix<double> matrix2 = {
 {1.2,3.4,5.6},
 {7.8,9.10,11.12},
 {13.14,15.16,17.18}
};

//Function algebra::Matrix<T> Map(const std::function<T(const T&)>& _lambda) transforms a matrix depending on its actual datatype and passed in function where T is type of real number.
//Does not modify the actual matrix. 

const algebra::Matrix<double> sqrt_matrix = matrix2.Map([&](const double& _element) {
   return std::sqrt(_element);
});
//Matrix sqrt_matrix would look like
1.09545 1.84391 2.36643
2.79285 3.01662 3.33467
3.62491 3.89358 4.14488


//Sample utility method, implemented utilizing algebra::Determinant datatype to compute the area of a triangle represented by the non-collinear 2D coordinate points defined with std::vector<std::pair<int,int>>.

const std::pair<int,int> givenPoint1 = std::make_pair<int,int>(3,8);
const std::pair<int,int> givenPoint2 = std::make_pair<int,int>(-4,2);
const std::pair<int,int> givenPoint3 = std::make_pair<int,int>(5,1);
const double computedAreaOfTriangle = algebra::DeterminantUtility_AreaOfTriangle({givenPoint1,givenPoint2,givenPoint3});
//Yields the value 30.5
```

##### Apart from the aforementioned examples, several other utility methods are provided to wrap and unwrap an algebra::Matrix<T> from and to simpler one-dimensional sequences e.g., flat C++ array and std::vector<T>. Wrapping and unwrapping can be done along rows or along columns using enum types defined in _algebra_ namespace. Several examples of the same are tested and demonstrated in the utility test suite and examples directory.

## Installation
##### In this section, the installation of the library is described with the help of git submodule and a simple project with CMake.

```cmake
//A simple CMake project setup
src/main.cpp
build
CMakeLists.txt

//Creating the root level git repository and adding the Francois as submodule
$ git init
$ git submodule add https://github.com/sarkarchandan/Francois.git extern/Francois

//A simple CMake configuration going inside CMakeLists.txt
cmake_minimum_required(VERSION 3.1...3.13)
if(${CMAKE_VERSION} VERSION_LESS 3.13)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(Installation VERSION 1.0 DESCRIPTION "Installation of Francois" LANGUAGES CXX)

#Adding extern/Francois as subdirectory
add_subdirectory(extern/Francois)

set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Francois)

//Assuming the out of source build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make

```

## Tests
##### Francois provides a grouped and illustrative test suite. The test suite, on the other hand, works as secondary documentation of the library features. It uses the _googletest_ framework and CTest driver program to execute the tests. In this section, we describe the execution of the test suite assuming the steps described in the Installation section are performed.

```bash
$ cd build/extern/Francois/
$ make
$ ctest

```

##### This should execute the complete test suite.

## Dependencies
* CMake version 3.11
* C++14

##### The library uses CMake [FetchContent](https://cmake.org/cmake/help/v3.11/module/FetchContent.html#id1 "CMake - FetchContent Module") module in order to integrate _googletest_ framework at configuration time. FetchContent is introduced with CMake version 3.11. The library uses features from C++ standard 14 in several places.

## Authors
* Chandan Sarkar

##### I am a grad student in computer science and learning C++ programming. This library is being created as part of my educational endeavors. I welcome all feedback and suggestions to improve my work.

## License
##### MIT Opensource License










