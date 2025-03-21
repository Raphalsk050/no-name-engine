#include "engine.h"
#include "debug/debug_helper.h"

void Engine::Initialize(Window* window) {
	physics_world_ = new PhysicsWorld();
	engine_state_ = new RunningState();
	Run();
	std::cout << "[Engine] Engine Initialized!" << std::endl;
}

Engine::Engine() {
}

Engine::~Engine() {
	delete physics_world_;
	std::cout << "[Engine] Engine cleared!" << std::endl;
	std::cout << "[Engine] Engine finished succefully :)" << std::endl;
}

void Engine::Run() {
	if(*engine_state_ != RunningState::RUNNING)
		*engine_state_ = RunningState::RUNNING;

	DEBUG(" Engine changed it's state to: " + *engine_state_);
	
}

void Engine::Pause() {
	if(*engine_state_ == RunningState::RUNNING)
		*engine_state_ = RunningState::PAUSED;
}
