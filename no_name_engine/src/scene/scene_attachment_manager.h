#pragma once
#include "../component/component_handle.h"
#include "../engine/base/managers/component_manager.h"
#include "../entity/entity.h"

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
