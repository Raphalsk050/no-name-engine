#pragma once

using ComponentID = uint32_t;
using EntityID = uint32_t;

struct FrameTime {
  float deltaTime;
};

enum ComponentActiveState : uint8_t {
  DISABLED = 0,
  ENABLED = 1,
};