#pragma once
#include "physics_world.h"
#include <vector>
#include "LinearMath/btVector3.h"

class PhysicsManager {
 public:
  static PhysicsManager* GetInstance();
  PhysicsManager(const PhysicsManager&) = delete;
  PhysicsManager& operator=(const PhysicsManager&) = delete;
  ~PhysicsManager();

  void Initialize();
  btRigidBody* AddRigidBody(btVector3 origin, float mass, btCollisionShape* shape);
  PhysicsWorld* GetPhysicsWorld() const;

 private:
  PhysicsManager();
  static PhysicsManager* instance_;
  PhysicsWorld* physics_world_;
  std::vector<btRigidBody*> rigid_bodies_; // Track created rigid bodies.
};