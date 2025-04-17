#include "engine.h"

#include "../events/event_manager.h"
#include "debug/debug_helper.h"

Engine::Engine() { DEBUG(" [Engine] Engine created"); }

Engine::~Engine() {
  Shutdown();
  DEBUG(" [Engine] Engine destroyed");
}

void Engine::Initialize() {
  for (auto& system : systems_) {
    system->Initialize();
  }
  running_ = true;
  paused_ = false;
  EventManager::getInstance()->AddWindowCloseListener([this] { Shutdown(); });
  Run();
  DEBUG(" [Engine] Engine Initialized!");
}

void Engine::Run() {
  if (!running_) {
    Initialize();
  }

  paused_ = false;
  DEBUG(" [Engine] Engine running");

  // Main game loop
  while (running_ && !paused_) {
    UpdateSystems(deltaTime_);
  }
}

void Engine::Pause() {
  paused_ = true;
  DEBUG(" [Engine] Engine paused");
}

void Engine::Shutdown() {
  // Shutdown systems in reverse order
  for (auto it = systems_.rbegin(); it != systems_.rend(); ++it) {
    (*it)->Shutdown();
  }
  running_ = false;
  DEBUG(" [Engine] Engine shut down");
}

void Engine::UpdateSystems(float deltaTime) {
  for (auto& system : systems_) {
    system->Update(deltaTime);
  }
}