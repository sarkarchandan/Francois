#include "Entity.hpp"

namespace oop
{
  Entity::Entity(const std::string& _m_Name)
  :m_Name(_m_Name)
  {
    std::cout << "Entity instance created with name: " << m_Name << std::endl;
  }
  Entity::~Entity()
  {
    std::cout << "Entity instance deallocated." << std::endl;
  }
  std::string Entity::GetName() const
  {
    return m_Name;
  }
} // oop
