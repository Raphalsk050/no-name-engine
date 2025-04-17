#pragma once
#include <string>

using EntityID = uint32_t;
struct Entity {
  EntityID id;
  std::string name;
};