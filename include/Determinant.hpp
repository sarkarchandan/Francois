#ifndef DETERMINANT_H
#define DETERMINANT_H

#include "MultiSequence.hpp"

namespace algebra
{
  template<typename RealNumericValueType>
  class Determinant: public MultiSequence<RealNumericValueType>
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,long>::value ||
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value ||
    std::is_same<RealNumericValueType,algebra::ElementProtocol>::value,"Container can accept only integers or double data type for now.");

    #pragma mark Public constructors
    public:
    Determinant() = delete;
    Determinant(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list)
    :MultiSequence<RealNumericValueType>(_init_list)
    {}
    Determinant(const std::vector<std::vector<RealNumericValueType>>& _vectors)
    :MultiSequence<RealNumericValueType>(_vectors)
    {}
    Determinant(const std::vector<algebra::Row<RealNumericValueType>>& _rows)
    :MultiSequence<RealNumericValueType>(_rows)
    {}
    Determinant(const std::vector<algebra::Column<RealNumericValueType>>& _columns)
    :MultiSequence<RealNumericValueType>(_columns)
    {}
    Determinant(const Determinant& _determinant)
    :MultiSequence<RealNumericValueType>(_determinant)
    {}
    ~Determinant(){}
    
    #pragma mark Public member functions


  };
} // algebra




#endif //DETERMINANT_H