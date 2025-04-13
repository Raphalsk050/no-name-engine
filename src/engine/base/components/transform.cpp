#include "transform.h"
btVector3 Transform::getPosition() const { return transform_->getOrigin(); }
btQuaternion Transform::getRotation() const {
  return transform_->getRotation();
}
btVector3 Transform::getForward() const {
  return transform_->getBasis().getColumn(2);
}
btVector3 Transform::getRight() const {
  return transform_->getBasis().getColumn(0);
}
btVector3 Transform::getUp() const {
  return transform_->getBasis().getColumn(1);
}
