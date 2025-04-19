#include "entity_handle.h"

#include "../../scene/scene.h"

template <typename T, typename... Args>
ComponentHandle<T> EntityHandle::AddComponent(Args&&... args) {
  return scene->AddComponent<T>(id, std::forward<Args>(args)...);
}

template <typename T>
std::vector<ComponentHandle<T>> EntityHandle::GetComponents() const {
  return scene->GetComponents<T>(id);
}
