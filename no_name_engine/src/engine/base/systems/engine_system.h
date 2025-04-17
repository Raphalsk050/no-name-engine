#pragma once

class EngineSystem {
 public:
  virtual void Initialize() = 0;
  virtual void Update(float deltaTime) = 0;
  virtual void Shutdown() = 0;
  virtual ~EngineSystem() = default;
};
