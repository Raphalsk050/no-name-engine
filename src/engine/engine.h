#pragma once
#include "../physics/physics_world.h"
#include "../window/window.h"
#include "../window/window_glfw.h"
#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"

enum RunningState
{
	INACTIVE,
	RUNNING,
	PAUSED
};

class Engine {
public:
	void Initialize(Window *window);

	Engine();

	~Engine();

	void Run() const;

	void Pause() const;

private:
	float fixed_frame_time_ms_ = 0.16f;
	RunningState* engine_state_;
	GLFWWindow* window_;
	EventManager* event_manager_;
	PhysicsWorld *physics_world_ = nullptr;
	void cleanup() const;
};
