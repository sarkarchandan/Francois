#ifndef MATRIX_H
#define MATRIX_H

#include <type_traits>
#include <vector>
#include <exception>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <initializer_list>
#include <memory>
#include "MatrixComponents.hpp"
#include "MatrixElementProtocol.hpp"

namespace algebra
{
  template<typename RealNumericValueType>
  class Matrix
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::MatrixElementProtocol>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Private member properties
    private:
    std::unique_ptr<std::vector<std::vector<RealNumericValueType>>> m_Container;

    #pragma mark Private member functions
    private:
    bool IsValid(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list)
    {
      std::vector<size_t> _buffer(_init_list.size());
      std::transform(_init_list.begin(),_init_list.end(),_buffer.begin(),[&](const std::vector<RealNumericValueType>& _collection) {
        return _collection.size();
        });
      return std::adjacent_find(_buffer.begin(),_buffer.end(),std::not_equal_to<size_t>()) == _buffer.end();
    }

    bool IsValid(const std::vector<std::vector<RealNumericValueType>>& _vectors)
    {
      std::vector<size_t> _buffer(_vectors.size());
      std::transform(_vectors.begin(),_vectors.end(),_buffer.begin(),[&](const std::vector<RealNumericValueType>& _collection) {
        return _collection.size();
        });
      return std::adjacent_find(_buffer.begin(),_buffer.end(),std::not_equal_to<size_t>()) == _buffer.end();
    }

    #pragma mark Public constructors
    public:
    Matrix() = delete;
    Matrix(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list)
    {
      if (!(IsValid(_init_list)))
        throw std::invalid_argument("Unequal number of elements in rows");
      m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      m_Container -> reserve(_init_list.size());
      std::for_each(_init_list.begin(),_init_list.end(),[&](const std::vector<RealNumericValueType>& _element_vector) {
          m_Container -> emplace_back(_element_vector);
        });
      std::cout << "Container initialized with element type: " << typeid(RealNumericValueType).name() << "\n";
    }
    
    Matrix(const std::vector<std::vector<RealNumericValueType>>& _vectors)
    {
      if (!(IsValid(_vectors)))
        throw std::invalid_argument("Unequal number of elements in vectors");
      
      m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      m_Container -> reserve(_vectors.size());
      std::for_each(_vectors.begin(),_vectors.end(),[&](const std::vector<RealNumericValueType>& _element_vector) {
          m_Container -> emplace_back(_element_vector);
        });
      std::cout << "Container initialized with element type: " << typeid(RealNumericValueType).name() << "\n";
    }

    ~Matrix(){}
    
    Matrix(const Matrix& _matrix)
    {
      m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      m_Container -> reserve(_matrix.Order().first);
      std::vector<algebra::Row<RealNumericValueType>> _rows = _matrix.Rows();
      std::for_each(_rows.begin(),_rows.end(),[&](const algebra::Row<RealNumericValueType>& _row) {
        std::vector<RealNumericValueType> _buffer;
        _buffer.reserve(_row.Size());
        std::for_each(_row.begin(),_row.end(),[&](const RealNumericValueType& _element) {
          _buffer.emplace_back(_element);
        });
        m_Container -> emplace_back(_buffer);
      });
    }
    
    #pragma mark Public member functions and accessors
    public:
    inline std::pair<size_t,size_t> Order() const
    {
      const std::pair<size_t,size_t> _pair = std::make_pair<size_t,size_t>(m_Container -> size(),m_Container -> operator[](0).size());
      return _pair;
    }

    inline const RealNumericValueType& operator ()(const size_t& _row,const size_t& _column) const
    {
      if(_row < Order().first && _column < Order().second)
        return m_Container -> operator[](_row)[_column];
      else
        throw std::out_of_range("Out of range subscripting attempted");
    }

    const std::vector<algebra::Row<RealNumericValueType>> Rows() const
    {
      std::vector<algebra::Row<RealNumericValueType>> _rows;
      _rows.reserve(Order().first);
      std::for_each(m_Container -> begin(),m_Container -> end(),[&](const std::vector<RealNumericValueType>& _row){
        _rows.emplace_back(_row);
      });
      return _rows;
    }

    const std::vector<algebra::Column<RealNumericValueType>> Columns() const
    {
      std::vector<algebra::Column<RealNumericValueType>> _columns;
      _columns.reserve(Order().second);
      std::vector<RealNumericValueType> _columnBuffer(Order().first);

      for(size_t column_index = 0; column_index < Order().second; column_index += 1)
      {
        _columnBuffer.clear();
        for(size_t row_index = 0; row_index < Order().first; row_index += 1)
        {
          _columnBuffer.emplace_back(this -> operator()(row_index,column_index));
        }
        _columns.emplace_back(_columnBuffer);
      }
      return _columns;
    }

    inline bool IsRowMatrix() const { return Order().first == 1; }

    inline bool IsColumnMatrix() const { return Order().second == 1; }

    inline bool IsRectangularMatrix() const { return Order().first != Order().second; }
    
    inline bool IsSquareMatrix() const { return Order().first == Order().second; }

    const std::vector<RealNumericValueType> MainDiagonalElements() const
    {
      if(IsRectangularMatrix())
        throw std::logic_error("Only square matrices are having main diagonal elements");

      std::vector<size_t> _buffer(Order().first);
      std::generate(_buffer.begin(),_buffer.end(),[_index = -1]() mutable {
        return _index += 1;
      });
      std::vector<RealNumericValueType> _diagonalElements(Order().first);
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
      std::vector<RealNumericValueType> _mainDiagonalElements = MainDiagonalElements();
      return std::adjacent_find(_mainDiagonalElements.begin(),_mainDiagonalElements.end(),std::not_equal_to<RealNumericValueType>()) == _mainDiagonalElements.end();
    }

    bool IsIdentityMatrix() const
    {
      if(!IsScalarMatrix())
        return false;
      std::vector<RealNumericValueType> _mainDiagonalElements = MainDiagonalElements();
      if(_mainDiagonalElements[0] != 1)
        return false;
      return std::adjacent_find(_mainDiagonalElements.begin(),_mainDiagonalElements.end(),std::not_equal_to<RealNumericValueType>()) == _mainDiagonalElements.end();
    }

    bool IsNullMatrix() const
    {
      bool _isNull = true;
      std::for_each(m_Container -> begin(),m_Container -> end(),[&](const std::vector<RealNumericValueType>& _vector){
        if(_vector[0] != 0)
          _isNull = false;
        if(!(std::adjacent_find(_vector.begin(),_vector.end(),std::not_equal_to<RealNumericValueType>()) == _vector.end()))
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

    RealNumericValueType Trace() const
    {
      if(!IsSquareMatrix())
        throw std::logic_error("Only square matrices can have trace value");

      const std::vector<RealNumericValueType> _mainDiagonalElements = MainDiagonalElements();
      const RealNumericValueType _sumOfDiagonalElements = std::accumulate(_mainDiagonalElements.begin(),_mainDiagonalElements.end(),0.0);
      return _sumOfDiagonalElements;
    }
  };

  #pragma mark Operator overloaded functions
  template<typename RealNumericValueType>
  std::ostream& operator <<(std::ostream& _stream, const algebra::Matrix<RealNumericValueType>& _matrix)
  {
    std::vector<algebra::Row<RealNumericValueType>> _rows = _matrix.Rows();
    std::for_each(_rows.begin(),_rows.end(),[&](const algebra::Row<RealNumericValueType>& _row) {
      _stream << _row << "\n";
    });
    return _stream;
  }

  template<typename RealNumericValueType>
  std::vector<RealNumericValueType> operator +(const std::vector<RealNumericValueType>& _lhs, const std::vector<RealNumericValueType>& _rhs)
  {
    std::vector<RealNumericValueType> _result(_lhs.size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),_result.begin(),[&](const RealNumericValueType& _lhs_element, const RealNumericValueType& _rhs_element) {
      return _lhs_element + _rhs_element;
    });
    return _result;
  }

  template<typename RealNumericValueType>
  std::vector<RealNumericValueType> operator -(const std::vector<RealNumericValueType>& _lhs, const std::vector<RealNumericValueType>& _rhs)
  {
    std::vector<RealNumericValueType> _result(_lhs.size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),_result.begin(),[&](const RealNumericValueType& _lhs_element, const RealNumericValueType& _rhs_element) {
      return _lhs_element - _rhs_element;
    });
    return _result;
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator +(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if (!(_lhs.Order() == _rhs.Order())) 
      throw std::invalid_argument("Matrices of separate orders can not be added");

    const std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<RealNumericValueType>> _rhs_Rows = _rhs.Rows();

    std::vector<std::vector<RealNumericValueType>> _lhs_vectors;
    _lhs_vectors.reserve(_lhs_Rows.size());
    std::for_each(_lhs_Rows.begin(),_lhs_Rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
      std::vector<RealNumericValueType> _buffer;
      _buffer.reserve(_row.Size());
      std::for_each(_row.begin(),_row.end(),[&](const RealNumericValueType& _element){
        _buffer.emplace_back(_element);
      });
      _lhs_vectors.emplace_back(_buffer);
    });

    std::vector<std::vector<RealNumericValueType>> _rhs_vectors;
    _rhs_vectors.reserve(_rhs_Rows.size());
    std::for_each(_rhs_Rows.begin(),_rhs_Rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
      std::vector<RealNumericValueType> _buffer;
      _buffer.reserve(_row.Size());
      std::for_each(_row.begin(),_row.end(),[&](const RealNumericValueType& _element){
        _buffer.emplace_back(_element);
      });
      _rhs_vectors.emplace_back(_buffer);
    });

    std::vector<std::vector<RealNumericValueType>> _differenceOfRows(_lhs_vectors.size());
    std::transform(_lhs_vectors.begin(),_lhs_vectors.end(),_rhs_vectors.begin(),_differenceOfRows.begin(),[&](const std::vector<RealNumericValueType>& _lhs, const std::vector<RealNumericValueType>& _rhs){
      return _lhs + _rhs;
    });
    return algebra::Matrix<RealNumericValueType>(_differenceOfRows);
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator -(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if(!(_lhs.Order() == _rhs.Order()))
      throw std::invalid_argument("Matrices of separate orders can not be added");
    
    const std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<RealNumericValueType>> _rhs_Rows = _rhs.Rows();

    std::vector<std::vector<RealNumericValueType>> _lhs_vectors;
    _lhs_vectors.reserve(_lhs_Rows.size());
    std::for_each(_lhs_Rows.begin(),_lhs_Rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
      std::vector<RealNumericValueType> _buffer;
      _buffer.reserve(_row.Size());
      std::for_each(_row.begin(),_row.end(),[&](const RealNumericValueType& _element){
        _buffer.emplace_back(_element);
      });
      _lhs_vectors.emplace_back(_buffer);
    });

    std::vector<std::vector<RealNumericValueType>> _rhs_vectors;
    _rhs_vectors.reserve(_rhs_Rows.size());
    std::for_each(_rhs_Rows.begin(),_rhs_Rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
      std::vector<RealNumericValueType> _buffer;
      _buffer.reserve(_row.Size());
      std::for_each(_row.begin(),_row.end(),[&](const RealNumericValueType& _element){
        _buffer.emplace_back(_element);
      });
      _rhs_vectors.emplace_back(_buffer);
    });

    std::vector<std::vector<RealNumericValueType>> _differenceOfRows(_lhs_vectors.size());
    std::transform(_lhs_vectors.begin(),_lhs_vectors.end(),_rhs_vectors.begin(),_differenceOfRows.begin(),[&](const std::vector<RealNumericValueType>& _lhs, const std::vector<RealNumericValueType>& _rhs){
      return _lhs - _rhs;
    });
    return algebra::Matrix<RealNumericValueType>(_differenceOfRows);
  }

  template<typename ComparableType>
  bool operator ==(const algebra::Matrix<ComparableType>& _lhs, const algebra::Matrix<ComparableType>& _rhs)
  {
    if(_lhs.Order() != _rhs.Order())
      return false;

    const std::vector<algebra::Row<ComparableType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<ComparableType>> _rhs_Rows = _rhs.Rows();

    return std::equal(_lhs_Rows.begin(),_lhs_Rows.end(),_rhs_Rows.begin(),_rhs_Rows.end(),[&](const algebra::Row<ComparableType>& _lhs_Row, const algebra::Row<ComparableType>& _rhs_Row) {
      return _lhs_Row == _rhs_Row;
    });
  }

  template<typename ComparableType>
  bool operator !=(const algebra::Matrix<ComparableType>& _lhs, const algebra::Matrix<ComparableType>& _rhs)
  {
    return !(_lhs == _rhs);
  }
} // algebra

#endif //MATRIX_H
