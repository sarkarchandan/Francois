#ifndef HELPER_H
#define HELPER_H

#include "Matrix.hpp"

template<typename PrintableType>
std::ostream& operator <<(std::ostream& stream, const std::vector<PrintableType> _printableVector)
{
  std::for_each(_printableVector.begin(),_printableVector.end(),[&](const PrintableType& value)
  {
    stream << value << " ";
    });
  return stream;
}

#endif //HELPER_H