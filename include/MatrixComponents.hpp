#ifndef MATRIXCOMPONENTS_H
#define MATRIXCOMPONENTS_H

#include <type_traits>

namespace algebra
{
  template<typename RealNumericValueType>
  struct ElementSequence
  {
    static_assert(std::is_same<RealNumericValueType,int>::value || 
    std::is_same<RealNumericValueType,float>::value || 
    std::is_same<RealNumericValueType,double>::value,"Container can accept only integers or double data type for now.");
    
    #pragma mark Protected member properties to be accessed only by child classes 
    protected:
    std::vector<RealNumericValueType> m_ElementSequence; 

    #pragma mark Protected member functions to be accessed only by child classes
    protected:
    //Think about how to deal with copy behaviour
    ElementSequence() = delete;
    ElementSequence(const std::vector<RealNumericValueType>& _m_ElementSequence)
    {
      m_ElementSequence.reserve(_m_ElementSequence.size());
      std::for_each(_m_ElementSequence.begin(),_m_ElementSequence.end(),[&](const RealNumericValueType& _element){
          m_ElementSequence.emplace_back(_element);
        });
      }
      ~ElementSequence(){}

      #pragma mark Public accessors and member functions
      public:
      const size_t Size() const { return m_ElementSequence.size(); }
      const RealNumericValueType& operator[](const unsigned long& _index) const
      {
        return m_ElementSequence[_index];
      }
    };
    
    template<typename RealNumericValueType>
    struct Row: public ElementSequence<RealNumericValueType>
    { 
      static_assert(std::is_same<RealNumericValueType,int>::value || 
      std::is_same<RealNumericValueType,float>::value || 
      std::is_same<RealNumericValueType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Row() = delete;
      Row(const std::vector<RealNumericValueType>& _row_ElementSequence)
      :ElementSequence<RealNumericValueType>(_row_ElementSequence){}
      ~Row(){}

      #pragma mark Public accessors and member functions 
      public:
      //TODO: Try to understand why this overload does not work.
      // bool operator ==(const Row<RealNumericValueType>& other)
      // {
      //   if(this -> Size() != other.Size())
      //     return false;
      //   for(size_t index = 0; index < this -> Size(); index += 1)
      //   {
      //     if(this -> m_ElementSequence[index] != other[index])
      //       return false;
      //   }
      //   return true;
      // }
    };
    
    template<typename RealNumericValueType>
    struct Column: public ElementSequence<RealNumericValueType>
    {
      static_assert(std::is_same<RealNumericValueType,int>::value || 
      std::is_same<RealNumericValueType,float>::value || 
      std::is_same<RealNumericValueType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Column() = delete;
      Column(const std::vector<RealNumericValueType>& _column_ElementSequence)
      :ElementSequence<RealNumericValueType>(_column_ElementSequence){}
      ~Column(){}
      
    };
} // algebra


#endif //MATRIXCOMPONENTS_H