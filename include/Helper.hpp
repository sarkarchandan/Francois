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
bool operator ==(const typename algebra::Matrix<ComparableType>::Row& _lhs, const std::vector<ComparableType>& _rhs)
{
  if(_lhs.Size() != _rhs.size())
    return false;
  for(size_t index = 0; index < _lhs.size(); index += 1)
  {
    if(_lhs[index] != _rhs[index])
      return false;
  }
  return true;
}

template<typename ComparableType>
bool operator ==(const typename algebra::Row<ComparableType>& lhs, const typename algebra::Row<ComparableType>& rhs)
{
  //TODO
  return true;
}

#endif //HELPER_H