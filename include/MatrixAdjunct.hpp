#ifndef HELPER_H
#define HELPER_H

#include "Matrix.hpp"
#include "MatrixComponents.hpp"

template<typename PrintableType>
std::ostream& operator <<(std::ostream& stream, const std::vector<PrintableType> _printableVector)
{
  std::for_each(_printableVector.begin(),_printableVector.end(),[&](const PrintableType& value)
  {
    stream << value << " ";
    });
  return stream;
}

template<typename ComparableType>
bool operator ==(const algebra::ElementSequence<ComparableType>& _lhs, const typename algebra::ElementSequence<ComparableType>& _rhs)
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

template<typename ComparableType>
bool operator !=(const algebra::ElementSequence<ComparableType>& _lhs, const algebra::ElementSequence<ComparableType>& _rhs)
{
  return !(_lhs == _rhs);
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

#endif //HELPER_H