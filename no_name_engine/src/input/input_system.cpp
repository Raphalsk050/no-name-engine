#include "input_system.h"
#include "../engine/debug/debug_helper.h"

InputSystem::InputSystem() {}

InputSystem::~InputSystem() {}

void InputSystem::Initialize() {
    DebugHelper::NLog_info(" [InputSystem] Input system initialized");
}

void InputSystem::Update(float deltaTime) {
}

void InputSystem::Shutdown() {
    DebugHelper::NLog_info(" [InputSystem] Input system shutdown");
}

bool InputSystem::IsKeyPressed(int keyCode) const {
    auto it = keyStates_.find(keyCode);
    return it != keyStates_.end() && it->second == KeyState::PRESSED;
}

bool InputSystem::IsKeyHeld(int keyCode) const {
    auto it = keyStates_.find(keyCode);
    return it != keyStates_.end() && (it->second == KeyState::HELD || it->second == KeyState::PRESSED);
}

bool InputSystem::IsKeyReleased(int keyCode) const {
    auto it = keyStates_.find(keyCode);
    return it != keyStates_.end() && it->second == KeyState::RELEASED;
}