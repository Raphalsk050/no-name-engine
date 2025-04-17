#pragma once
#include <string>

#include "../component.h"

/* This component is always attached to a new node. This component
 * is used to represent a node in the scene graph and have all the
 * necessary information to handle the node's properties and behavior.
 */
class NodeComponent : public Component {
 public:
  std::string GetName();

 private:
  std::string name_;
};
