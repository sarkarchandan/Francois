#ifndef MATRIXCOMPONENTS_H
#define MATRIXCOMPONENTS_H

#include <type_traits>
#include <initializer_list>
#include "MatrixElementProtocol.hpp"

namespace algebra
{
  template<typename RealNumericValueType>
  struct ElementSequence
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
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
    typename std::vector<RealNumericValueType>::iterator begin() const
    {
      return m_ElementSequence -> begin();
    }
    typename std::vector<RealNumericValueType>::iterator end() const
    {
      return m_ElementSequence -> end();
    }
    ElementSequence(const ElementSequence& _elementSequence)
    {
      m_ElementSequence = std::make_unique<std::vector<RealNumericValueType>>(_elementSequence.Size());
      std::for_each(_elementSequence.begin(),_elementSequence.end(),[&](const RealNumericValueType& _element){
        m_ElementSequence -> emplace_back(_element);
      });
    }
    ~ElementSequence(){}

    #pragma mark Public accessors and member functions
    public:
    const size_t Size() const { return m_ElementSequence -> size(); }
    const RealNumericValueType& operator[](const size_t& _index) const
    {
      return m_ElementSequence -> operator[](_index);
    }
  };
    
  template<typename RealNumericValueType>
  struct Row: public ElementSequence<RealNumericValueType>
  { 
    static_assert(std::is_same<RealNumericValueType,int>::value || 
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
    Row(const Row<RealNumericValueType>& _row)
    :ElementSequence<RealNumericValueType>(_row){}
    ~Row(){}
    };
    
  template<typename RealNumericValueType>
  struct Column: public ElementSequence<RealNumericValueType>
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
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
} // algebra


#endif //MATRIXCOMPONENTS_H