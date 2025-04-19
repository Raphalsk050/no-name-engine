#pragma once
#include <memory>

#include "../component/component_handle.h"
#include "entity.h"

using namespace std;
class Scene;

class EntityHandle {
 public:
  EntityHandle(EntityID id, Scene* scene) : id(id), scene(scene) {}

  EntityID GetID() const { return id; }

  template <typename T, typename... Args>
  ComponentHandle<T> AddComponent(Args&&... args);

  template <typename T>
  std::vector<ComponentHandle<T>> GetComponents() const;

 private:
  EntityID id;
  Scene* scene;
};
