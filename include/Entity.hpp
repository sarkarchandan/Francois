#pragma once
#include <iostream>
namespace oop
{
  class Entity
  {
    private:
    std::string m_Name;
    public:
    Entity(const std::string& _m_Name);
    ~Entity();
    std::string GetName() const;
  };
} // oop
