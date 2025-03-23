#pragma once
#include <btBulletDynamicsCommon.h>

#include <iostream>
#include <vector>

#define DEFAULT_GRAVITY_FORCE (-9.81)

typedef btRigidBody::btRigidBodyConstructionInfo RigidBodyConfiguration;

class PhysicsWorld {
 public:
  PhysicsWorld();

  ~PhysicsWorld();

  void CreatePhysicsWorld();

  void ChangeWorldGravity(btVector3 gravity) const;

  RigidBodyConfiguration CreateRigidBodyConstructionInfo(
      btVector3 origin, btScalar mass, btVector3 local_inertia,
      btCollisionShape *shape);

  [[nodiscard]] btRigidBody *AddRigidBody(const RigidBodyConfiguration &rbInfo);

 private:
  btDynamicsWorld *dynamics_world_;
  btDefaultCollisionConfiguration *collision_configuration_;
  btCollisionDispatcher *dispatcher_;
  btBroadphaseInterface *overlapping_pair_cache_;
  btSequentialImpulseConstraintSolver *solver_;
  std::vector<btRigidBody *> rigid_bodies_;
  void DestroyAllRigidBodies();
};
