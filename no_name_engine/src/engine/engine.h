#pragma once
#include <memory>
#include <string>
#include <vector>

#include "base/systems/engine_system.h"

class Engine {
 public:
  Engine();
  ~Engine();

  template <typename T, typename... Args>
  T* RegisterSystem(Args&&... args) {
    auto system = std::make_unique<T>(std::forward<Args>(args)...);
    T* ptr = system.get();
    systems_.push_back(std::move(system));
    return ptr;
  }

  void Initialize();
  void Run();
  void Pause();
  void Shutdown();

 private:
  float deltaTime_ = 0.016f;  // Default 60 FPS
  bool running_ = false;
  bool paused_ = false;
  std::vector<std::unique_ptr<EngineSystem>> systems_;
  void UpdateSystems(float deltaTime);
};