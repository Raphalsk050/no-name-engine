#include "physics_system.h"
#include "../engine/debug/debug_helper.h"

PhysicsSystem::PhysicsSystem() {}

PhysicsSystem::~PhysicsSystem() {}

void PhysicsSystem::Initialize() {
    physics_manager_ = PhysicsManager::GetInstance();
    physics_manager_->Initialize();
    DebugHelper::NLog_info(" [PhysicsSystem] Physics system initialized");
}

void PhysicsSystem::Update(float deltaTime) {
    physics_manager_->GetPhysicsWorld()->stepSimulation(deltaTime);
}

void PhysicsSystem::Shutdown() {
    // O PhysicsManager é um singleton, então não deletamos aqui
    DebugHelper::NLog_info(" [PhysicsSystem] Physics system shutdown");
}

btRigidBody* PhysicsSystem::AddRigidBody(btVector3 origin, float mass, btCollisionShape* shape) {
    return physics_manager_->AddRigidBody(origin, mass, shape);
}

void PhysicsSystem::SetGravity(const btVector3& gravity) {
    physics_manager_->GetPhysicsWorld()->ChangeWorldGravity(gravity);
}