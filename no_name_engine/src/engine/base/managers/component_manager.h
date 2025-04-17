#pragma once

#include <cassert>
#include <unordered_map>
#include <vector>

#include "../types.h"

template <typename T>
class ComponentHandle;

template <typename T>
class ComponentManager {
 public:
  ComponentManager() = default;

  template <typename... Args>
  ComponentHandle<T> AddComponent(EntityID owner, Args&&... args) {
    ComponentID id = nextID++;
    components[id] = T(std::forward<Args>(args)...);
    entityMap[owner].push_back(id);
    return ComponentHandle<T>(id, this);
  }

  const T* Get(ComponentID id) const {
    auto it = components.find(id);
    return it != components.end() ? &it->second : nullptr;
  }

  T* GetMutable(ComponentID id) {
    auto it = components.find(id);
    return it != components.end() ? &it->second : nullptr;
  }

  std::vector<ComponentHandle<T>> GetByEntity(EntityID entity) const {
    std::vector<ComponentHandle<T>> result;
    auto it = entityMap.find(entity);
    if (it != entityMap.end()) {
      for (ComponentID id : it->second) {
        result.emplace_back(id, this);
      }
    }
    return result;
  }

  void RemoveComponent(ComponentID id) {
    // Remove from components
    components.erase(id);

    // Remove from entityMap
    for (auto& [entity, list] : entityMap) {
      auto it = std::remove(list.begin(), list.end(), id);
      if (it != list.end()) {
        list.erase(it, list.end());
        break;
      }
    }
  }

  void RemoveAllComponents(EntityID entity) {
    auto it = entityMap.find(entity);
    if (it != entityMap.end()) {
      for (ComponentID id : it->second) {
        components.erase(id);
      }
      entityMap.erase(it);
    }
  }

  void UpdateComponents() {
    for (auto component : components) {
      component.second->Update();
    }
  }

 private:
  ComponentID nextID = 1;
  std::unordered_map<ComponentID, T> components;
  std::unordered_map<EntityID, std::vector<ComponentID>> entityMap;

  friend class ComponentHandle<T>;
};
