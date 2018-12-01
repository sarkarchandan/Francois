#ifndef MATRIX_H
#define MATRIX_H

#include <type_traits>
#include <vector>
#include <exception>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include "MatrixComponents.hpp"
#include <initializer_list>

namespace algebra
{
  template<typename RealNumericValuedType>
  class Matrix
  {
    static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Private member properties
    private:
    std::vector<std::vector<RealNumericValuedType>> m_Container;

    #pragma mark Private member functions
    private:
    bool IsValid(const std::initializer_list<std::vector<RealNumericValuedType>>& _init_list)
    {
      std::vector<size_t> _buffer(_init_list.size());
      std::transform(_init_list.begin(),_init_list.end(),_buffer.begin(),[](const std::vector<RealNumericValuedType>& _collection) {
        return _collection.size();
        });
      return std::adjacent_find(_buffer.begin(),_buffer.end(),std::not_equal_to<size_t>()) == _buffer.end();
    }

    #pragma mark Public constructors
    public:
    Matrix() = delete;
    Matrix(const std::initializer_list<std::vector<RealNumericValuedType>>& _init_list)
    {
      if(IsValid(_init_list))
      {
        m_Container.reserve(_init_list.size());
        std::for_each(_init_list.begin(),_init_list.end(),[&](const std::vector<RealNumericValuedType>& _element_vector) {
          m_Container.emplace_back(_element_vector);
        });
        std::cout << "Container initialized with element type: " << typeid(RealNumericValuedType).name() << std::endl;
      }
      else 
      {
        throw std::invalid_argument("Unequal number of elements in rows");
      }
    }
    ~Matrix(){}
    
    #pragma mark Public member functions and accessors
    public:
    inline std::pair<size_t,size_t> Order() const
    {
      const std::pair<size_t,size_t> _pair = std::make_pair<size_t,size_t>(m_Container.size(),m_Container[0].size());
      return _pair;
    }

    inline const RealNumericValuedType& operator ()(const unsigned long& _row,const unsigned long& _column) const
    {
      if(_row < Order().first && _column < Order().second)
        return m_Container[_row][_column];
      else
        throw std::out_of_range("Out of range subscripting attempted");
    }

    const std::vector<algebra::Row<RealNumericValuedType>> Rows() const
    {
      std::vector<algebra::Row<RealNumericValuedType>> _rows;
      _rows.reserve(Order().first);
      std::for_each(m_Container.begin(),m_Container.end(),[&](const std::vector<RealNumericValuedType>& _row){
        _rows.emplace_back(_row);
      });
      return _rows;
    }

    const std::vector<algebra::Column<RealNumericValuedType>> Columns() const
    {
      std::vector<algebra::Column<RealNumericValuedType>> _columns;
      _columns.reserve(Order().second);
      std::vector<RealNumericValuedType> _columnBuffer(Order().first);

      for(size_t column_index = 0; column_index < Order().second; column_index += 1)
      {
        _columnBuffer.clear();
        for(size_t row_index = 0; row_index < Order().first; row_index += 1)
        {
          _columnBuffer.emplace_back(m_Container[row_index][column_index]);
        }
        _columns.emplace_back(_columnBuffer);
      }
      return _columns;
    }

    inline bool IsRowMatrix() const { return Order().first == 1; }

    inline bool IsColumnMatrix() const { return Order().second == 1; }

    inline bool IsRectangularMatrix() const { return Order().first != Order().second; }
    
    inline bool IsSquareMatrix() const { return Order().first == Order().second; }

    const std::vector<RealNumericValuedType> MainDiagonalElements() const
    {
      if(IsRectangularMatrix())
        throw std::invalid_argument("Only square matrices are having main diagonal elements");

      std::vector<size_t> _buffer(Order().first);
      std::generate(_buffer.begin(),_buffer.end(),[_index = -1]() mutable {
        return _index += 1;
      });
      std::vector<RealNumericValuedType> _diagonalElements(Order().first);
      std::transform(_buffer.begin(),_buffer.end(),_diagonalElements.begin(),[&](const size_t& _index){
        return operator()(_index,_index);
      });
      return _diagonalElements;
    }

    bool IsDiagonalMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      for(size_t row_index = 0; row_index < Order().first; row_index += 1)
      {
        if(operator()(row_index,row_index) == 0)
          return false;
        
        for(size_t column_index = row_index + 1; column_index < Order().second; column_index += 1)
        {
          if(operator()(row_index,column_index) != 0)
            return false;
          if(operator()(column_index,row_index) != 0) 
            return false;
        }
      }
      return true;
    }

    bool IsScalarMatrix() const
    {
      if(!IsDiagonalMatrix())
        return false;
      std::vector<RealNumericValuedType> _mainDiagonalElements = MainDiagonalElements();
      return std::adjacent_find(_mainDiagonalElements.begin(),_mainDiagonalElements.end(),std::not_equal_to<RealNumericValuedType>()) == _mainDiagonalElements.end();
    }

    bool IsIdentityMatrix() const
    {
      if(!IsScalarMatrix())
        return false;
      std::vector<RealNumericValuedType> _mainDiagonalElements = MainDiagonalElements();
      if(_mainDiagonalElements[0] != 1)
        return false;
      return std::adjacent_find(_mainDiagonalElements.begin(),_mainDiagonalElements.end(),std::not_equal_to<RealNumericValuedType>()) == _mainDiagonalElements.end();
    }

    bool IsNullMatrix() const
    {
      bool _isNull = true;
      std::for_each(m_Container.begin(),m_Container.end(),[&](const std::vector<RealNumericValuedType>& _vector){
        if(_vector[0] != 0)
          _isNull = false;
        if(!(std::adjacent_find(_vector.begin(),_vector.end(),std::not_equal_to<RealNumericValuedType>()) == _vector.end()))
          _isNull = false;
      });
      return _isNull;
    }

    bool IsUpperTriangularMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      for(size_t row_index = 0; row_index < Order().first; row_index += 1)
      {
        if(operator()(row_index,row_index) == 0)
          return false;
        
        for(size_t column_index = row_index + 1; column_index < Order().second; column_index += 1)
        {
          if(operator()(row_index,column_index) == 0)
            return false;
          if(operator()(column_index,row_index) != 0) 
            return false;
        }
      }
      return true;
    }

    bool IsLowerTriangularMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      for(size_t row_index = 0; row_index < Order().first; row_index += 1)
      {
        if(operator()(row_index,row_index) == 0)
          return false;
        
        for(size_t column_index = row_index + 1; column_index < Order().second; column_index += 1)
        {
          if(operator()(row_index,column_index) != 0)
            return false;
          if(operator()(column_index,row_index) == 0) 
            return false;
        }
      }
      return true;
    }

    bool IsTriangularMatrix() const
    {
      return IsUpperTriangularMatrix() || IsLowerTriangularMatrix();
    }
  };
} // algebra

#endif //MATRIX_H
