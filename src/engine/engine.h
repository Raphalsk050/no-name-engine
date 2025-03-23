#pragma once
#include "../events/event_manager.h"
#include "../physics/physics_world.h"
#include "../window/window_glfw.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"

enum RunningState { INACTIVE, RUNNING, PAUSED };

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "NNEngine"

class Engine {
 public:
  void Initialize();

  Engine();

  ~Engine();

  void Run() const;

  void Pause() const;

 private:
  float fixed_frame_time_ms_ = 0.16f;
  RunningState* engine_state_;
  WindowGLFW* window_;
  EventManager* event_manager_;
  PhysicsWorld* physics_world_ = nullptr;
  void cleanup() const;
};
