#include "entity_system.h"

#include "../engine/debug/debug_helper.h"
void EntitySystem::Initialize() {
  DebugHelper::NLog_info(" [EntitySystem] Entity system initialized");
}
void EntitySystem::Update(float deltaTime) {
  // DebugHelper::NLog_info(" [EntitySystem] Entity system update");
}
void EntitySystem::Shutdown() {
  DebugHelper::NLog_info(" [EntitySystem] Entity system shutdown");
}