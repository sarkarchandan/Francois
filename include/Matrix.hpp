#ifndef MATRIX_H
#define MATRIX_H

#include "MultiSequence.hpp"

namespace algebra
{
  template<typename RealNumericValueType>
  class Matrix: public MultiSequence<RealNumericValueType>
  {
    static_assert(std::is_same<RealNumericValueType,int>::value ||
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value ||
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::ElementProtocol>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Public constructors
    public:
    Matrix() = delete;
    Matrix(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list)
    :MultiSequence<RealNumericValueType>(_init_list)
    {}
    Matrix(const std::vector<std::vector<RealNumericValueType>>& _vectors)
    :MultiSequence<RealNumericValueType>(_vectors)
    {}
    Matrix(const std::vector<algebra::Row<RealNumericValueType>>& _rows)
    :MultiSequence<RealNumericValueType>(_rows)
    {}
    Matrix(const std::vector<algebra::Column<RealNumericValueType>>& _columns)
    :MultiSequence<RealNumericValueType>(_columns)
    {}
    Matrix(const Matrix& _matrix)
    :MultiSequence<RealNumericValueType>(_matrix)
    {}
    ~Matrix(){}

    #pragma mark Public member functions
    public:
    inline bool IsRowMatrix() const { return this -> Order().first == 1; }

    inline bool IsColumnMatrix() const { return this -> Order().second == 1; }

    inline bool IsRectangularMatrix() const { return this -> Order().first != this -> Order().second; }

    inline bool IsSquareMatrix() const { return this -> Order().first == this -> Order().second; }

    const std::vector<RealNumericValueType> MainDiagonalElements() const
    {
      if(IsRectangularMatrix())
        throw std::logic_error("Only square matrices are having main diagonal elements");

      std::vector<size_t> _buffer(this -> Order().first);
      std::generate(_buffer.begin(),_buffer.end(),[_index = -1]() mutable {
        return _index += 1;
      });
      std::vector<RealNumericValueType> _diagonalElements(this -> Order().first);
      std::transform(_buffer.begin(),_buffer.end(),_diagonalElements.begin(),[&](const size_t& _index){
        return this -> operator()(_index,_index);
      });
      return _diagonalElements;
    }

    bool IsDiagonalMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      for(size_t row_index = 0; row_index < this -> Order().first; row_index += 1)
      {
        if(this -> operator()(row_index,row_index) == 0)
          return false;

        for(size_t column_index = row_index + 1; column_index < this -> Order().second; column_index += 1)
        {
          if(this -> operator()(row_index,column_index) != 0)
            return false;
          if(this -> operator()(column_index,row_index) != 0)
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
      std::for_each(this -> m_Container -> begin(),this -> m_Container -> end(),[&](const std::vector<RealNumericValueType>& _vector){
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
      for(size_t row_index = 0; row_index < this -> Order().first; row_index += 1)
      {
        if(this -> operator()(row_index,row_index) == 0)
          return false;

        for(size_t column_index = row_index + 1; column_index < this -> Order().second; column_index += 1)
        {
          if(this -> operator()(row_index,column_index) == 0)
            return false;
          if(this -> operator()(column_index,row_index) != 0)
            return false;
        }
      }
      return true;
    }

    bool IsLowerTriangularMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      for(size_t row_index = 0; row_index < this -> Order().first; row_index += 1)
      {
        if(this -> operator()(row_index,row_index) == 0)
          return false;

        for(size_t column_index = row_index + 1; column_index < this -> Order().second; column_index += 1)
        {
          if(this -> operator()(row_index,column_index) != 0)
            return false;
          if(this -> operator()(column_index,row_index) == 0)
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

    inline bool IsMultipliableWith(const algebra::Matrix<RealNumericValueType>& _matrix) const
    {
      return (this -> Order().second == _matrix.Order().first);
    }

    void For_EachRow(const std::function<void(const algebra::Row<RealNumericValueType>&)>& _lambda) const
    {
      std::vector<algebra::Row<RealNumericValueType>> _rows = this -> Rows();
      std::for_each(_rows.begin(),_rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
        _lambda(_row);
      });
    }

    void For_EachColumn(const std::function<void(const algebra::Column<RealNumericValueType>&)>& _lambda) const
    {
      std::vector<algebra::Column<RealNumericValueType>> _columns = this -> Columns();
      std::for_each(_columns.begin(),_columns.end(),[&](const algebra::Column<RealNumericValueType>& _column){
        _lambda(_column);
      });
    }

    Matrix<RealNumericValueType> Map(const std::function<RealNumericValueType(const RealNumericValueType&)>& _lambda) const
    {
      std::vector<std::vector<RealNumericValueType>> _mapped_Container;
      _mapped_Container.reserve(this -> Order().first);
      std::transform(this -> m_Container -> begin(), this -> m_Container -> end(),std::back_inserter(_mapped_Container),[&](const std::vector<RealNumericValueType>& _vector){
        std::vector<RealNumericValueType> _buffer;
        _buffer.reserve(this -> Order().second);
        std::transform(_vector.begin(),_vector.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element){
          return _lambda(_element);
        });
        return _buffer;
      });
      return algebra::Matrix<RealNumericValueType>(_mapped_Container);
    }

    Matrix<RealNumericValueType> Transpose() const
    {
      std::vector<algebra::Column<RealNumericValueType>> _columns;
      _columns.reserve(this -> Order().first);
      For_EachRow([&](const algebra::Row<RealNumericValueType>& _row){
        std::vector<RealNumericValueType> _buffer;
        _buffer.reserve(_row.Size());
        std::transform(_row.begin(),_row.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element){
          return _element;
        });
        _columns.emplace_back(algebra::Column<RealNumericValueType>(_buffer));
      });
      return algebra::Matrix<RealNumericValueType>(_columns);
    }

    bool IsSymmetricMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      return *this == Transpose();
    }

    bool IsSkewSymmetricMatrix() const
    {
      if(!IsSquareMatrix())
        return false;
      const algebra::Matrix<RealNumericValueType> _matrix = Transpose().Map([&](const RealNumericValueType& _element){
        return -_element;
      });
      return *this == _matrix;
    }
  };

  #pragma mark Operator overloaded functions
  template<typename RealNumericValueType>
  std::ostream& operator <<(std::ostream& _stream, const std::vector<RealNumericValueType>& _vector)
  {
    _stream << "{ ";
    std::for_each(_vector.begin(),_vector.end(),[&](const RealNumericValueType& _element){
      _stream << _element << " ";
    });
    _stream << "}";
    return _stream;
  }

  template<typename RealNumericValueType>
  std::ostream& operator <<(std::ostream& _stream, const algebra::Matrix<RealNumericValueType>& _matrix)
  {
    _stream << "\n";
    std::vector<algebra::Row<RealNumericValueType>> _rows = _matrix.Rows();
    std::for_each(_rows.begin(),_rows.end(),[&](const algebra::Row<RealNumericValueType>& _row) {
      _stream << _row << "\n";
    });
    return _stream;
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator +(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if (!(_lhs.Order() == _rhs.Order()))
      throw std::invalid_argument("Matrices of separate orders can not be added");

    const std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<RealNumericValueType>> _rhs_Rows = _rhs.Rows();

    std::vector<algebra::Row<RealNumericValueType>> _sumOfRows;
    _sumOfRows.reserve(_lhs_Rows.size());
    std::transform(_lhs_Rows.begin(),_lhs_Rows.end(),_rhs_Rows.begin(),std::back_inserter(_sumOfRows),[&](const algebra::Row<RealNumericValueType>& _lhs, const algebra::Row<RealNumericValueType>& _rhs){
      return _lhs + _rhs;
    });
    return algebra::Matrix<RealNumericValueType>(_sumOfRows);
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator -(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if(!(_lhs.Order() == _rhs.Order()))
      throw std::invalid_argument("Matrices of separate orders can not be added");

    const std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<RealNumericValueType>> _rhs_Rows = _rhs.Rows();

    std::vector<algebra::Row<RealNumericValueType>> _differenceOfRows;
    _differenceOfRows.reserve(_lhs_Rows.size());
    std::transform(_lhs_Rows.begin(),_lhs_Rows.end(),_rhs_Rows.begin(),std::back_inserter(_differenceOfRows),[&](const algebra::Row<RealNumericValueType>& _lhs, const algebra::Row<RealNumericValueType>& _rhs){
      return _lhs - _rhs;
    });
    return algebra::Matrix<RealNumericValueType>(_differenceOfRows);
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator *(const RealNumericValueType& _scalar, const algebra::Matrix<RealNumericValueType>& _matrix)
  {
    std::vector<algebra::Row<RealNumericValueType>> _matrix_Rows = _matrix.Rows();

    std::vector<algebra::Row<RealNumericValueType>> _product;
    _product.reserve(_matrix_Rows.size());
    std::transform(_matrix_Rows.begin(),_matrix_Rows.end(),std::back_inserter(_product),[&](const algebra::Row<RealNumericValueType>& _row) {
      return _scalar * _row;
    });
    return algebra::Matrix<RealNumericValueType>(_product);
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator *(const algebra::Matrix<RealNumericValueType>& _matrix, const RealNumericValueType& _scalar)
  {
    return _scalar * _matrix;
  }

  template<typename RealNumericValueType>
  algebra::Matrix<RealNumericValueType> operator *(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if(!_lhs.IsMultipliableWith(_rhs))
      throw std::invalid_argument("Argument matrices violate the criterion for multiplication.");
    std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    std::vector<algebra::Column<RealNumericValueType>> _rhs_Columns = _rhs.Columns();

    std::vector<std::vector<RealNumericValueType>> _resultant_Rows;
    _resultant_Rows.reserve(_lhs.Order().first);
    std::transform(_lhs_Rows.begin(),_lhs_Rows.end(),std::back_inserter(_resultant_Rows),[&](const algebra::Row<RealNumericValueType>& _row) {

      std::vector<RealNumericValueType> _buffer;
      _buffer.reserve(_rhs.Order().second);
      std::for_each(_rhs_Columns.begin(),_rhs_Columns.end(),[&](const algebra::Column<RealNumericValueType>& _column){
        _buffer.emplace_back(_row * _column);
      });
      return _buffer;
    });
    return algebra::Matrix<RealNumericValueType>(_resultant_Rows);
  }

  template<typename RealNumericValueType>
  bool operator ==(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    if(_lhs.Order() != _rhs.Order())
      return false;

    const std::vector<algebra::Row<RealNumericValueType>> _lhs_Rows = _lhs.Rows();
    const std::vector<algebra::Row<RealNumericValueType>> _rhs_Rows = _rhs.Rows();

    return std::equal(_lhs_Rows.begin(),_lhs_Rows.end(),_rhs_Rows.begin(),_rhs_Rows.end(),[&](const algebra::Row<RealNumericValueType>& _lhs_Row, const algebra::Row<RealNumericValueType>& _rhs_Row) {
      return _lhs_Row == _rhs_Row;
    });
  }

  template<typename RealNumericValueType>
  bool operator !=(const algebra::Matrix<RealNumericValueType>& _lhs, const algebra::Matrix<RealNumericValueType>& _rhs)
  {
    return !(_lhs == _rhs);
  }

  Matrix<int> Ints(const size_t& _row, const size_t& _column, const int& _number)
  {
    std::vector<std::vector<int>> _vectors;
    _vectors.reserve(_row);
    for(size_t _row_index = 0; _row_index < _row; _row_index += 1)
    {
      std::vector<int> _buffer(_column);
      std::generate(_buffer.begin(),_buffer.end(),[counter = _number]() {return counter;});
      _vectors.emplace_back(_buffer);
    }
    return algebra::Matrix<int>(_vectors);
  }

  Matrix<int> Zeros(const size_t& _row, const size_t& _column)
  {
    return algebra::Ints(_row,_column,0);
  }

  Matrix<int> Ones(const size_t& _row, const size_t& _column)
  {
    return algebra::Ints(_row,_column,1);
  }
} // algebra

#endif //MATRIX_H
