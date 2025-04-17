#include <src/engine/base/scene.h>
#include <src/engine/engine.h>

#include "src/engine/base/systems/window_system.h"
#include "src/input/input_system.h"
#include "src/physics/physics_system.h"

int main() {
  auto engine = new Engine();
  Scene scene;
  scene.CreateEntity("Player");
  engine->RegisterSystem<WindowSystem>();
  engine->RegisterSystem<PhysicsSystem>();
  engine->RegisterSystem<InputSystem>();
  engine->Initialize();
  return 0;
}
