#include "component_system.h"

#include "../engine/debug/debug_helper.h"
void ComponentSystem::Initialize() {
  DebugHelper::NLog_info(" [ComponentSystem] Component system initialized");
}
void ComponentSystem::Update(float deltaTime) {
  // DebugHelper::NLog_info(" [ComponentSystem] Component system update");
}
void ComponentSystem::Shutdown() {
  DebugHelper::NLog_info(" [ComponentSystem] Component system shutdown");
}