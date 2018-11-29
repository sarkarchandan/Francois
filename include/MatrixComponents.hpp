#ifndef MATRIXCOMPONENTS_H
#define MATRIXCOMPONENTS_H

#include <type_traits>

namespace algebra
{
  template<typename RealNumericValuedType>
  struct ElementSequence
  {
    static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");
    
    #pragma mark Protected member properties to be accessed only by child classes 
    protected:
    std::vector<RealNumericValuedType> m_ElementSequence; 

    #pragma mark Protected member functions to be accessed only by child classes
    protected:
    ElementSequence(); //Implementation not provided
    ElementSequence(const std::vector<RealNumericValuedType>& _m_ElementSequence)
    {
      m_ElementSequence.reserve(_m_ElementSequence.size());
      std::for_each(_m_ElementSequence.begin(),_m_ElementSequence.end(),[&](const RealNumericValuedType& _element){
          m_ElementSequence.emplace_back(_element);
        });
      }
      ~ElementSequence(){}

      #pragma mark Public accessors and member functions
      public:
      const size_t Size() const { return m_ElementSequence.size(); }
      const RealNumericValuedType& operator[](const unsigned long& _index) const
      {
        return m_ElementSequence[_index];
      }
    };
    
    template<typename RealNumericValuedType>
    struct Row: public ElementSequence<RealNumericValuedType>
    { 
      static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Row():ElementSequence<RealNumericValuedType>(){}
      Row(const std::vector<RealNumericValuedType>& _row_ElementSequence)
      :ElementSequence<RealNumericValuedType>(_row_ElementSequence){}
      ~Row(){}

      #pragma mark Public accessors and member functions 
      public:
      //TODO: Try to understand why this overload does not work.
      // bool operator ==(const Row<RealNumericValuedType>& other)
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
    
    template<typename RealNumericValuedType>
    struct Column: public ElementSequence<RealNumericValuedType>
    {
      static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Column():ElementSequence<RealNumericValuedType>(){}
      Column(const std::vector<RealNumericValuedType>& _column_ElementSequence)
      :ElementSequence<RealNumericValuedType>(_column_ElementSequence){}
      ~Column(){}
      
    };
} // algebra


#endif //MATRIXCOMPONENTS_H