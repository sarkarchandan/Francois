#include "gtest/gtest.h"
#include "Entity.hpp"

TEST(CanCompareTwoEntities,canCompareEntities)
{
  oop::Entity entity1("Geralt");
  oop::Entity entity2("Geralt");
  ASSERT_EQ(entity1.GetName(),entity2.GetName());
}