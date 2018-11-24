#ifndef MATRIXCOMPONENTS_H
#define MATRIXCOMPONENTS_H

#include <iostream>

namespace algebra
{
  template<typename RealNumericValuedType>
  struct Elements
  {
    static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");
    
    #pragma mark Protected member properties to be accessed only by child classes 
    protected:
    std::vector<RealNumericValuedType> m_Elements; 

    #pragma mark Protected member functions to be accessed only by child classes
    protected:
    Elements();
    Elements(const std::vector<RealNumericValuedType>& _m_Elements)
    {
      m_Elements.reserve(_m_Elements.size());
      std::for_each(_m_Elements.begin(),_m_Elements.end(),[&](const RealNumericValuedType& _element){
          m_Elements.emplace_back(_element);
        });
      }
      ~Elements(){}

      #pragma mark Public accessors and member functions
      public:
      const size_t Size() const { return m_Elements.size(); }
      const RealNumericValuedType& operator[](const unsigned long& _index) const
      {
        return m_Elements[_index];
      }
    };
    
    template<typename RealNumericValuedType>
    struct Row: public Elements<RealNumericValuedType>
    { 
      static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Row():Elements<RealNumericValuedType>(){}
      Row(const std::vector<RealNumericValuedType>& _row_Elements)
      :Elements<RealNumericValuedType>(_row_Elements){}
      ~Row(){}

      #pragma mark Public accessors and member functions 
      // public:
      //TODO: Troubleshoot why the overload is not working
      // bool operator ==(const Row<RealNumericValuedType>& other)
      // {
      //   if(this -> Size() != other.size())
      //     return false;
      //   for(size_t index = 0; index < this -> Size(); index += 1)
      //   {
      //     if(this -> m_Elements[index] != other[index])
      //       return false;
      //   }
      //   return true;
      // }
    };
    
    template<typename RealNumericValuedType>
    class Column: public Elements<RealNumericValuedType>
    {
      static_assert(std::is_same<RealNumericValuedType,int>::value || std::is_same<RealNumericValuedType,double>::value,"Container can accept only integers or double data type for now.");

      #pragma mark Public constructors
      public:
      Column():Elements<RealNumericValuedType>(){}
      Column(const std::vector<RealNumericValuedType>& _column_Elements)
      :Elements<RealNumericValuedType>(_column_Elements){}
      ~Column(){}
      
    };
} // algebra


#endif //MATRIXCOMPONENTS_H