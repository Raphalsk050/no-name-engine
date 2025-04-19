#include <no_name_engine.h>

int main() {
  auto engine = new Engine();
  engine->RegisterSystem<WindowSystem>();
  engine->RegisterSystem<PhysicsSystem>();
  engine->RegisterSystem<InputSystem>();
  engine->Initialize();
  return 0;
}
