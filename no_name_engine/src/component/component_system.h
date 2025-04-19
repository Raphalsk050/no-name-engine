#pragma once
#include "../engine/base/systems/engine_system.h"

class ComponentSystem : public EngineSystem {
 public:
  void Initialize() override;
  void Update(float deltaTime) override;
  void Shutdown() override;
};
