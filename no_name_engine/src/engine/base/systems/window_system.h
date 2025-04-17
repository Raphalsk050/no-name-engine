#pragma once
#include "engine_system.h"
#include "../../../window/window_glfw.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "NNEngine"

class WindowSystem : public EngineSystem {
public:
    WindowSystem();
    ~WindowSystem() override;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Shutdown() override;
    
    [[nodiscard]] bool ShouldClose() const;
    [[nodiscard]] WindowGLFW* GetWindow() const { return window_; }

private:
    WindowGLFW* window_ = nullptr;
};