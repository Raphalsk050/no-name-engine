#pragma once
#include <LinearMath/btTransform.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class Entity {
 public:
  btVector3 GetPosition();

  btQuaternion GetRotation();

  btVector3 GetScale();

  btTransform GetTransform();

 private:
  btTransform transform_;
  int8_t id_ = 0;
};
