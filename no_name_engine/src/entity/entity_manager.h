#pragma once
#include <unordered_map>
#include <vector>

#include "entity.h"

using namespace std;
class EntityHandle;

class EntityManager {
 public:
  EntityID CreateEntity(const std::string& name = "Entity") {
    EntityID id = nextID++;
    entities.emplace(id, Entity{id, name});
    return id;
  }

  [[nodiscard]] const Entity* GetEntity(const EntityID id) const {
    auto it = entities.find(id);
    return it != entities.end() ? &it->second : nullptr;
  }

 private:
  EntityID nextID = 1;
  unordered_map<EntityID, Entity> entities;

  friend class Scene;
  friend class EntityHandle;
};
