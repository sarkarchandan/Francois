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
bool operator ==(const typename algebra::ElementSequence<ComparableType>& lhs, const typename algebra::ElementSequence<ComparableType>& rhs)
{
  if(lhs.Size() != rhs.Size())
    return false;
  for(size_t index = 0; index < lhs.Size(); index += 1)
  {
    if(lhs[index] != rhs[index])
      return false;
  }
  return true;
}

#endif //HELPER_H