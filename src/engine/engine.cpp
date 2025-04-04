#include "engine.h"

#include "debug/debug_helper.h"

EventManager* EventManager::instance = nullptr;

void Engine::Initialize() {
  window_ = new WindowGLFW(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  physics_world_ = new PhysicsWorld();
  engine_state_ = new RunningState();
  window_->initialize();
  DEBUG(" [Engine] Engine Initialized!");
  Run();
}

Engine::Engine() {
  EventManager::getInstance()->AddWindowCloseListener([this]() {
    // cleanup();
    DEBUG(" [Engine] Engine closed!");
  });
}

Engine::~Engine() {}

void Engine::Run() const {
  if (*engine_state_ != RunningState::RUNNING)
    *engine_state_ = RunningState::RUNNING;

  if (window_ == nullptr) return;
  DEBUG(" [Engine] Engine changed it's state to: RUNNING");

  window_->run();
}

void Engine::Pause() const {
  if (*engine_state_ == RunningState::RUNNING)
    *engine_state_ = RunningState::PAUSED;

  DEBUG(" [Engine] Engine changed it's state to: PAUSED");
}

void Engine::cleanup() const {
  delete physics_world_;
  DEBUG(" [Engine] Engine cleared!");
  DEBUG(" [Engine] Engine finished succefully :)");
}
