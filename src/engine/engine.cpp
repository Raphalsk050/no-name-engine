#include "engine.h"

void Engine::Initialize(Window* window) {
	physics_world_ = new PhysicsWorld();

	std::cout << "[Engine] Engine Initialized!" << std::endl;
}

Engine::Engine() {
}

Engine::~Engine() {
	delete physics_world_;
	std::cout << "[Engine] Engine cleared!" << std::endl;
}

void Engine::Run() {
}

void Engine::Pause() {
}
