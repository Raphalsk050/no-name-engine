#pragma once
#include "../physics/physics_world.h"
#include "../window/window.h"
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

	void Run();

	void Pause();

private:
	float fixed_frame_time_ms_ = 0.16f;
	RunningState* engine_state_;
	PhysicsWorld *physics_world_ = nullptr;
};
