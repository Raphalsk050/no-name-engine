#pragma once
#include <btBulletDynamicsCommon.h>

#include <iostream>
#include <vector>
#include "LinearMath/btScalar.h"

#define DEFAULT_GRAVITY_FORCE (-9.81)

typedef btRigidBody::btRigidBodyConstructionInfo RigidBodyConfiguration;

class PhysicsWorld {
 public:
  PhysicsWorld();

  ~PhysicsWorld();

  void CreatePhysicsWorld();

  void ChangeWorldGravity(btVector3 gravity) const;

  void stepSimulation(btScalar steps);

  RigidBodyConfiguration CreateRigidBodyConstructionInfo(
      btVector3 origin, btScalar mass, btVector3 local_inertia,
      btCollisionShape *shape);

  [[nodiscard]] btRigidBody *AddRigidBody(const RigidBodyConfiguration &rbInfo);

  void RemoveRigidBody(btRigidBody* rigidBody);

 private:
  btDynamicsWorld *dynamics_world_;
  btDefaultCollisionConfiguration *collision_configuration_;
  btCollisionDispatcher *dispatcher_;
  btBroadphaseInterface *overlapping_pair_cache_;
  btSequentialImpulseConstraintSolver *solver_;
  std::vector<btRigidBody *> rigid_bodies_;
  void DestroyAllRigidBodies();
  int32_t passed_steps_ = 0;
};