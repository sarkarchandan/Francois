#ifndef MATRIXCOMPONENTS_H
#define MATRIXCOMPONENTS_H

#include <type_traits>
#include <initializer_list>
#include "MatrixElementProtocol.hpp"
#include <exception>

namespace algebra
{
  //TODO: Implement the copy assignment operator
  template<typename RealNumericValueType>
  struct ElementSequence
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::MatrixElementProtocol>::value,"Container can accept only integers or double data type for now.");
    
    #pragma mark Protected member properties to be accessed only by child classes 
    protected:
    std::unique_ptr<std::vector<RealNumericValueType>> m_ElementSequence;

    #pragma mark Protected member functions to be accessed only by child classes
    protected:
    ElementSequence(){};
    ElementSequence(const std::vector<RealNumericValueType>& _m_ElementSequence)
    {
      m_ElementSequence = std::make_unique<std::vector<RealNumericValueType>>();
      m_ElementSequence -> reserve(_m_ElementSequence.size());
      std::for_each(_m_ElementSequence.begin(),_m_ElementSequence.end(),[&](const RealNumericValueType& _element){
        m_ElementSequence -> emplace_back(_element);
      });
    }
    ElementSequence(const std::initializer_list<RealNumericValueType>& _m_ElementSequence)
    {
      m_ElementSequence = std::make_unique<std::vector<RealNumericValueType>>();
      m_ElementSequence -> reserve(_m_ElementSequence.size());
      std::for_each(_m_ElementSequence.begin(),_m_ElementSequence.end(),[&](const RealNumericValueType& _element){
        m_ElementSequence -> emplace_back(_element);
      });
    }
    
    ElementSequence(const ElementSequence& _elementSequence)
    {
      m_ElementSequence = std::make_unique<std::vector<RealNumericValueType>>();
      m_ElementSequence -> reserve(_elementSequence.Size());
      std::for_each(_elementSequence.begin(),_elementSequence.end(),[&](const RealNumericValueType& _element){
        m_ElementSequence -> emplace_back(_element);
      });
    }
    ~ElementSequence(){}

    #pragma mark Public accessors and member functions
    public:
    inline const size_t Size() const { return m_ElementSequence -> size(); }
    inline const RealNumericValueType& operator[](const size_t& _index) const
    {
      return m_ElementSequence -> operator[](_index);
    }
    inline RealNumericValueType& operator[](const size_t& _index)
    {
      return m_ElementSequence -> operator[](_index);
    }
    inline typename std::vector<RealNumericValueType>::iterator begin() const
    {
      return m_ElementSequence -> begin();
    }
    inline typename std::vector<RealNumericValueType>::iterator end() const
    {
      return m_ElementSequence -> end();
    }
    ElementSequence& operator =(const algebra::ElementSequence<RealNumericValueType>& _elementSequence)
    {
      if(this == &_elementSequence)
        return *this;
      if((Size() != _elementSequence.Size()) || _elementSequence.Size() == 0)
        throw std::length_error("Copy assignment attempted for sequence of elements of unequal sizes.");
      m_ElementSequence = std::make_unique<std::vector<RealNumericValueType>>();
      m_ElementSequence -> reserve(_elementSequence.Size());
      std::for_each(_elementSequence.begin(),_elementSequence.end(),[&](const RealNumericValueType& _element){
        m_ElementSequence -> emplace_back(_element);
      });
      return *this;
    }
  };

  #pragma mark Operator overloaded functions for ElementSequence
  template<typename RealNumericValueType>
  bool operator ==(const algebra::ElementSequence<RealNumericValueType>& _lhs, const typename algebra::ElementSequence<RealNumericValueType>& _rhs)
  {
    if(_lhs.Size() != _rhs.Size())
      return false;

    for(size_t index = 0; index < _lhs.Size(); index += 1)
    {
      if(_lhs[index] != _rhs[index])
        return false;
    }
    return true;
  }

  template<typename RealNumericValueType>
  bool operator !=(const algebra::ElementSequence<RealNumericValueType>& _lhs, const algebra::ElementSequence<RealNumericValueType>& _rhs)
  {
    return !(_lhs == _rhs);
  }

  #pragma mark Row
  template<typename RealNumericValueType>
  struct Row: public ElementSequence<RealNumericValueType>
  { 
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::MatrixElementProtocol>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Public constructors
    public:
    Row() = delete;
    Row(const std::vector<RealNumericValueType>& _row_ElementSequence)
    :ElementSequence<RealNumericValueType>(_row_ElementSequence){}
    Row(const std::initializer_list<RealNumericValueType>& _m_RowList)
    :ElementSequence<RealNumericValueType>(_m_RowList){}
    Row(const algebra::Row<RealNumericValueType>& _row)
    :ElementSequence<RealNumericValueType>(_row){}
    ~Row(){}
  };

  #pragma mark Operator overloaded functions for Row
  template<typename RealNumericValueType>
  std::ostream& operator <<(std::ostream& _stream, const algebra::Row<RealNumericValueType>& _row)
  {
    for(size_t _index = 0; _index < _row.Size(); _index += 1)
    {
      if (_index < (_row.Size() - 1)) _stream << _row[_index] << " ";
      else _stream << _row[_index];
    }
    return _stream;
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator +(const algebra::Row<RealNumericValueType>& _lhs, const algebra::Row<RealNumericValueType>& _rhs)
  {
    if(_lhs.Size() != _rhs.Size())
      throw std::invalid_argument("Two rows of unequal size can not be added");
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),std::back_inserter(_buffer),[&](const RealNumericValueType& _l_Element, const RealNumericValueType& _r_Element) {
      return _l_Element + _r_Element;
    });
    return algebra::Row<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator -(const algebra::Row<RealNumericValueType>& _lhs, const algebra::Row<RealNumericValueType>& _rhs)
  {
    if(_lhs.Size() != _rhs.Size())
      throw std::invalid_argument("Two rows of unequal size can not be added");
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),std::back_inserter(_buffer),[&](const RealNumericValueType& _l_Element, const RealNumericValueType& _r_Element) {
      return _l_Element - _r_Element;
    });
    return algebra::Row<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator *(const algebra::Row<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element * _scalar;
    });
    return algebra::Row<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator *(const RealNumericValueType& _scalar, const algebra::Row<RealNumericValueType>& _rhs)
  {
    return _rhs * _scalar;
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator /(const algebra::Row<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element / _scalar;
    });
    return algebra::Row<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Row<RealNumericValueType> operator %(const algebra::Row<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element % _scalar;
    });
    return algebra::Row<RealNumericValueType>(_buffer);
  }

  #pragma mark Column
  template<typename RealNumericValueType>
  struct Column: public ElementSequence<RealNumericValueType>
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::MatrixElementProtocol>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Public constructors
    public:
    Column() = delete;
    Column(const std::vector<RealNumericValueType>& _column_ElementSequence)
    :ElementSequence<RealNumericValueType>(_column_ElementSequence){}
    Column(const std::initializer_list<RealNumericValueType>& _mColumnList)
    :ElementSequence<RealNumericValueType>(_mColumnList){}
    Column(const Column<RealNumericValueType>& _column)
    :ElementSequence<RealNumericValueType>(_column){}
    ~Column(){}
  };

  #pragma mark Operator overloaded functions for Column
  template<typename RealNumericValueType>
  std::ostream& operator <<(std::ostream& _stream, const algebra::Column<RealNumericValueType>& _column)
  {
    for(size_t _index = 0; _index < _column.Size(); _index += 1)
    {
      if (_index < (_column.Size() - 1)) _stream << _column[_index] << " ";
      else _stream << _column[_index];
    }
    return _stream;
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator +(const algebra::Column<RealNumericValueType>& _lhs, const algebra::Column<RealNumericValueType>& _rhs)
  {
    if(_lhs.Size() != _rhs.Size())
      throw std::invalid_argument("Two columns of unequal size can not be added");
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),std::back_inserter(_buffer),[&](const RealNumericValueType& _l_Element, const RealNumericValueType& _r_Element) {
      return _l_Element + _r_Element;
    });
    return algebra::Column<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator -(const algebra::Column<RealNumericValueType>& _lhs, const algebra::Column<RealNumericValueType>& _rhs)
  {
    if(_lhs.Size() != _rhs.Size())
      throw std::invalid_argument("Two columns of unequal size can not be added");
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),_rhs.begin(),std::back_inserter(_buffer),[&](const RealNumericValueType& _l_Element, const RealNumericValueType& _r_Element) {
      return _l_Element - _r_Element;
    });
    return algebra::Column<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator *(const algebra::Column<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element * _scalar;
    });
    return algebra::Column<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator *(const RealNumericValueType& _scalar, const algebra::Column<RealNumericValueType>& _rhs)
  {
    return _rhs * _scalar;
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator /(const algebra::Column<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element / _scalar;
    });
    return algebra::Column<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  algebra::Column<RealNumericValueType> operator %(const algebra::Column<RealNumericValueType>& _lhs, const RealNumericValueType& _scalar)
  {
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs.Size());
    std::transform(_lhs.begin(),_lhs.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element) {
      return _element % _scalar;
    });
    return algebra::Column<RealNumericValueType>(_buffer);
  }

  template<typename RealNumericValueType>
  RealNumericValueType operator *(const algebra::Row<RealNumericValueType>& _lhs_row, const algebra::Column<RealNumericValueType>& _rhs_column)
  {
    if(_lhs_row.Size() == 0 || _rhs_column.Size() == 0)
      throw std::logic_error("Can not operate on row or columns having no elements.");
    else if(_lhs_row.Size() != _rhs_column.Size())
      throw std::logic_error("Can not operate on row or column of different sizes.");
    std::vector<RealNumericValueType> _buffer;
    _buffer.reserve(_lhs_row.Size());
    std::transform(_lhs_row.begin(),_lhs_row.end(),_rhs_column.begin(),std::back_inserter(_buffer),[&](const RealNumericValueType& _lhs_element, const RealNumericValueType& _rhs_element){
      return _lhs_element * _rhs_element;
    });
    const RealNumericValueType _matrix_element = std::accumulate(_buffer.begin(),_buffer.end(),0.0);
    return _matrix_element;
  } 
} // algebra


#endif //MATRIXCOMPONENTS_H