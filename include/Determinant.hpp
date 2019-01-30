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

    #pragma mark Private helper functions
    private:
    bool IsValid(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list) const override 
    {
      return MultiSequence<RealNumericValueType>::IsValid(_init_list) && _init_list.size() == _init_list.begin() -> size();
    }

    bool IsValid(const std::vector<std::vector<RealNumericValueType>>& _vectors)const override 
    {
      return MultiSequence<RealNumericValueType>::IsValid(_vectors) && _vectors.size() == _vectors.begin() -> size();
    }
    
    bool IsValid(const std::vector<algebra::Row<RealNumericValueType>>& _rows)const override
    {
      return MultiSequence<RealNumericValueType>::IsValid(_rows) && _rows.size() == _rows.begin() -> Size();
    } 

    bool IsValid(const std::vector<algebra::Column<RealNumericValueType>>& _columns)const override
    {
      return MultiSequence<RealNumericValueType>::IsValid(_columns) && _columns.size() == _columns.begin() -> Size();
    }

    #pragma mark Public constructors
    public:
    Determinant() = delete;
    Determinant(const std::initializer_list<std::vector<RealNumericValueType>>& _init_list)
    {
      if(!IsValid(_init_list))
        throw std::invalid_argument("Unequal number of elements in list");
      this -> m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      this -> m_Container -> reserve(_init_list.size());
      std::for_each(_init_list.begin(),_init_list.end(),[&](const std::vector<RealNumericValueType>& _element_vector) {
        this -> m_Container -> emplace_back(_element_vector);
      });
    }
    Determinant(const std::vector<std::vector<RealNumericValueType>>& _vectors)
    {
      if(!IsValid(_vectors))
        throw std::invalid_argument("Unequal number of elements in vectors");
      this -> m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      this -> m_Container -> reserve(_vectors.size());
      std::for_each(_vectors.begin(),_vectors.end(),[&](const std::vector<RealNumericValueType>& _element_vector) {
        this -> m_Container -> emplace_back(_element_vector);
      });
    }
    Determinant(const std::vector<algebra::Row<RealNumericValueType>>& _rows)
    {
      if(!IsValid(_rows))
        throw std::invalid_argument("Unequal number of elements in rows");
      this -> m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      this -> m_Container -> reserve(_rows.size());
      std::for_each(_rows.begin(),_rows.end(),[&](const algebra::Row<RealNumericValueType>& _row){
        std::vector<RealNumericValueType> _buffer;
        _buffer.reserve(_row.Size());
        std::transform(_row.begin(),_row.end(),std::back_inserter(_buffer),[&](const RealNumericValueType& _element){
          return _element;
        });
        this -> m_Container -> emplace_back(_buffer);
      });
    }
    Determinant(const std::vector<algebra::Column<RealNumericValueType>>& _columns)
    {
      if(!IsValid(_columns))
        throw std::invalid_argument("Unequal number of elements in columns");
      this -> m_Container = std::make_unique<std::vector<std::vector<RealNumericValueType>>>();
      this -> m_Container -> reserve(_columns[0].Size());
      for(size_t _index = 0; _index < _columns[0].Size(); _index += 1)
      {
        std::vector<RealNumericValueType> _row_buffer;
        _row_buffer.reserve(_columns.size());
        std::for_each(_columns.begin(),_columns.end(),[&](const algebra::Column<RealNumericValueType>& _column){
          _row_buffer.emplace_back(_column[_index]);
        });
        this -> m_Container -> emplace_back(_row_buffer);
      }
    }
    Determinant(const Determinant& _determinant)
    :MultiSequence<RealNumericValueType>(_determinant)
    {}
    ~Determinant(){}
    
    #pragma mark Public member functions
    // RealNumericValueType Value(); const
  };
} // algebra




#endif //DETERMINANT_H