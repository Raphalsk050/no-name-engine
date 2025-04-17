#pragma once
#include "../component_handle.h"
#include "../entity.h"
#include "component_manager.h"

class SceneAttachmentManager {
 public:
  template <typename T, typename... Args>
  ComponentHandle<T> AddComponent(EntityID entity, Args&&... args) {
    return GetOrCreateManager<T>().AddComponent(entity,
                                                std::forward<Args>(args)...);
  }

  template <typename T>
  std::vector<ComponentHandle<T>> GetComponents(EntityID entity) const {
    return GetOrCreateManager<T>().GetByEntity(entity);
  }

 private:
  template <typename T>
  static ComponentManager<T>& GetOrCreateManager() {
    static ComponentManager<T> manager;
    return manager;
  }
};
