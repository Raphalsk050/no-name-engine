#pragma once
#include <cstdint>

#include "../engine/base/types.h"

using ComponentID = uint32_t;
class Component {
  friend class ComponentManager;

 public:
  explicit Component(ComponentID id) : id_(id) {}

  virtual void Setup() = 0;
  virtual void Update(FrameTime& frame_time) = 0;
  virtual void Shutdown() = 0;

 private:
  ComponentID id_;
  ComponentActiveState active_state_;
};
