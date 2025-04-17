// src/physics/rigidbody_component.h
#pragma once
#include "../engine/base/component.h"
#include <btBulletDynamicsCommon.h>
#include <memory>

class RigidBodyComponent : public Component {
/*public:
  RigidBodyComponent();

  // Configuração principal
  void SetMass(float mass);
  void SetFriction(float friction);
  void SetRestitution(float restitution);
  void SetLinearDamping(float damping);
  void SetAngularDamping(float damping);

  void ApplyForce(const btVector3& force, const btVector3& relativePos = btVector3(0,0,0));
  void ApplyImpulse(const btVector3& impulse, const btVector3& relativePos = btVector3(0,0,0));
  void ApplyTorque(const btVector3& torque);
  void SetLinearVelocity(const btVector3& velocity);
  void SetAngularVelocity(const btVector3& velocity);

  void SetKinematic(bool kinematic);
  void SetCollisionEnabled(bool enabled);
  void SetSleepingThresholds(float linear, float angular);

  void Setup() override;
  void Update(FrameTime& frame_time) override;
  void Shutdown() override;

  btRigidBody* GetRigidBody() const { return rigidBody.get(); }

private:
  std::unique_ptr<btRigidBody> rigidBody;
  std::unique_ptr<btMotionState> motionState;
  btCollisionShape* collisionShape;*/
};