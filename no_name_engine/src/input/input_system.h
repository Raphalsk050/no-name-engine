#pragma once
#include "../engine/base/systems/engine_system.h"
#include <unordered_map>

enum class KeyState {
    RELEASED,
    PRESSED,
    HELD
};

class InputSystem : public EngineSystem {
public:
    InputSystem();
    ~InputSystem() override;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Shutdown() override;
    
    bool IsKeyPressed(int keyCode) const;
    bool IsKeyHeld(int keyCode) const;
    bool IsKeyReleased(int keyCode) const;

private:
    std::unordered_map<int, KeyState> keyStates_;
};