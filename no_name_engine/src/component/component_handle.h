// component_handle.h

#pragma once
#include "../engine/base/managers/component_manager.h"

template <typename T>
class ComponentHandle {
 public:
  ComponentHandle(const ComponentID id, const ComponentManager<T>* mgr)
      : id(id), manager(mgr) {}

  const T* Get() const { return manager ? manager->Get(id) : nullptr; }

  const T& operator*() const { return *Get(); }
  const T* operator->() const { return Get(); }

 private:
  ComponentID id;
  const ComponentManager<T>* manager;
};
