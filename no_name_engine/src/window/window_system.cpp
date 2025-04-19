#include "window_system.h"

#include "../engine/debug/debug_helper.h"

WindowSystem::WindowSystem() {}

WindowSystem::~WindowSystem() {}

void WindowSystem::Initialize() {
    window_ = new WindowGLFW(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    window_->initialize();
    DebugHelper::NLog_info(" [WindowSystem] Window system initialized");
}

void WindowSystem::Update(float deltaTime) {
    window_->update();
}

void WindowSystem::Shutdown() {
    delete window_;
    window_ = nullptr;
    DebugHelper::NLog_info(" [WindowSystem] Window system shutdown");
}

bool WindowSystem::ShouldClose() const {
    return window_->shouldClose();
}