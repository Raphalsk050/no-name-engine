#include "physics_manager.h"

#include "../engine/debug/debug_helper.h"

PhysicsManager* PhysicsManager::instance_ = nullptr;

PhysicsManager* PhysicsManager::GetInstance() {
  if (!instance_) {
    instance_ = new PhysicsManager();
  }
  return instance_;
}

PhysicsManager::PhysicsManager() : physics_world_(new PhysicsWorld()) {}

PhysicsManager::~PhysicsManager() {
  // Clean up rigid bodies before physics world.
  for (auto* body : rigid_bodies_) {
    physics_world_->RemoveRigidBody(body); // Assuming you'll add this method to PhysicsWorld
    delete body->getMotionState();
    delete body;
  }
  rigid_bodies_.clear();

  delete physics_world_;
  DEBUG(" [PhysicsManager] Physics Manager destroyed!");
}

void PhysicsManager::Initialize() {
  physics_world_->CreatePhysicsWorld();
  DEBUG(" [PhysicsManager] Physics Manager Initialized!");
}


btRigidBody* PhysicsManager::AddRigidBody(btVector3 origin, float mass, btCollisionShape* shape) {
    btVector3 localInertia(0, 0, 0);
    shape->calculateLocalInertia(mass, localInertia);

    btRigidBody::btRigidBodyConstructionInfo rbInfo = physics_world_->CreateRigidBodyConstructionInfo(origin, mass, localInertia, shape);
    btRigidBody* body = physics_world_->AddRigidBody(rbInfo);
    rigid_bodies_.push_back(body);
    return body;
}


PhysicsWorld* PhysicsManager::GetPhysicsWorld() const { return physics_world_; }