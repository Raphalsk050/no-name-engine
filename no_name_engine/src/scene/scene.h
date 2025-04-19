#pragma once
#include <memory>

#include "../engine/base/component_handle.h"
#include "../engine/base/entity_handle.h"
#include "../engine/base/managers/entity_manager.h"
#include "scene_attachment_manager.h"

class Scene {
 public:
  Scene() : entityManager(std::make_unique<EntityManager>()) {}

  EntityHandle CreateEntity(const std::string& name = "Entity") {
    EntityID id = entityManager->CreateEntity(name);
    return EntityHandle{id, this};
  }

  template <typename T, typename... Args>
  ComponentHandle<T> AddComponent(EntityID entity, Args&&... args) {
    return attachmentManager.AddComponent<T>(entity,
                                             std::forward<Args>(args)...);
  }

  template <typename T>
  std::vector<ComponentHandle<T>> GetComponents(EntityID entity) const {
    return attachmentManager.GetComponents<T>(entity);
  }

  [[nodiscard]] const Entity* GetEntity(EntityID id) const {
    return entityManager->GetEntity(id);
  }

 private:
  std::unique_ptr<EntityManager> entityManager;
  SceneAttachmentManager attachmentManager;

  friend class EntityHandle;
};
