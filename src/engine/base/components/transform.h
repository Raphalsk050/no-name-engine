#pragma once
#include "LinearMath/btQuaternion.h"
#include "LinearMath/btTransform.h"
#include "LinearMath/btVector3.h"

class Transform {
 public:
  btVector3 getPosition() const;
  btQuaternion getRotation() const;
  btVector3 getForward() const;
  btVector3 getRight() const;
  btVector3 getUp() const;

 private:
  btTransform* transform_;
};
