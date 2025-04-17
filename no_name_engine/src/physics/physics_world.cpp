#include "physics_world.h"

#include "../engine/debug/debug_helper.h"
#include "LinearMath/btScalar.h"

PhysicsWorld::PhysicsWorld() {
  collision_configuration_ = new btDefaultCollisionConfiguration();
  dispatcher_ = new btCollisionDispatcher(collision_configuration_);
  overlapping_pair_cache_ = new btDbvtBroadphase();
  solver_ = new btSequentialImpulseConstraintSolver;
}

PhysicsWorld::~PhysicsWorld() {
  DestroyAllRigidBodies();
  delete dynamics_world_;
  delete solver_;
  delete overlapping_pair_cache_;
  delete dispatcher_;
  delete collision_configuration_;
  DEBUG(" [Physics] Physics world cleared! ---------------------------");
}

void PhysicsWorld::stepSimulation(btScalar steps) {
  if (!dynamics_world_) {
    DEBUG(
        " [Physics] No dynamic world created to simulation! "
        "---------------------------");
    return;
  }

  dynamics_world_->stepSimulation(steps);
  passed_steps_+=steps;
  // DEBUG(" [Physics] Update steps: ", passed_steps_);
}

btRigidBody *PhysicsWorld::AddRigidBody(const RigidBodyConfiguration &rbInfo) {
  if (!dynamics_world_) {
    DEBUG(" [Physics] No dynamic world created! ---------------------------");
    return nullptr;
  }

  auto *rigid_body = new btRigidBody(rbInfo);
  rigid_bodies_.push_back(rigid_body);
  dynamics_world_->addRigidBody(rigid_body);
  return rigid_body;
}

void PhysicsWorld::RemoveRigidBody(btRigidBody* rigidBody) {
    dynamics_world_->removeRigidBody(rigidBody);
    auto it = std::find(rigid_bodies_.begin(), rigid_bodies_.end(), rigidBody);
    if (it != rigid_bodies_.end()) {
        rigid_bodies_.erase(it);
    }
}

void PhysicsWorld::CreatePhysicsWorld() {
  dynamics_world_ = new btDiscreteDynamicsWorld(
      dispatcher_, overlapping_pair_cache_, solver_, collision_configuration_);
  dynamics_world_->setGravity(btVector3(0, DEFAULT_GRAVITY_FORCE, 0));
}

void PhysicsWorld::ChangeWorldGravity(const btVector3 gravity) const {
  dynamics_world_->setGravity(gravity);
}

RigidBodyConfiguration PhysicsWorld::CreateRigidBodyConstructionInfo(
    btVector3 origin, btScalar mass, btVector3 local_inertia,
    btCollisionShape *shape) {
  btTransform groundTransform;
  groundTransform.setIdentity();
  groundTransform.setOrigin(origin);
  auto *groundMotionState = new btDefaultMotionState(groundTransform);
  shape->calculateLocalInertia(mass, local_inertia);
  return {mass, groundMotionState, shape, local_inertia};
}

void PhysicsWorld::DestroyAllRigidBodies() {
  for (auto rigid_body : rigid_bodies_) {
    dynamics_world_->removeRigidBody(rigid_body);
    delete rigid_body->getMotionState();
    delete rigid_body;
  }

  rigid_bodies_.clear();
  DEBUG(" [Physics] All rigidbodies cleared! ---------------------------");
}