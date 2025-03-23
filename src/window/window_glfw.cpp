#include "window_glfw.h"

#include <iostream>

#include "../engine/debug/debug_helper.h"

WindowGLFW::WindowGLFW(int width, int height, const char *title)
    : width_(width), height_(height), title_(title), window_(nullptr) {}

WindowGLFW::~WindowGLFW() {
  if (window_) {
    glfwDestroyWindow(window_);
  }
  glfwTerminate();
}

bool WindowGLFW::initialize() {
  if (!glfwInit()) {
    DEBUG(" [WINDOW] Fail to initialize GLFW");
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(width_, height_, title_, nullptr, nullptr);
  if (!window_) {
    DEBUG(" [WINDOW] Fail to create GLFW window");
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window_);
  setupCallbacks();
  return true;
}

void WindowGLFW::run() {
  while (!shouldClose()) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    swapBuffers();
    pollEvents();
  }
  cleanup();
}

bool WindowGLFW::shouldClose() const { return glfwWindowShouldClose(window_); }

void WindowGLFW::swapBuffers() { glfwSwapBuffers(window_); }

void WindowGLFW::pollEvents() { glfwPollEvents(); }

void WindowGLFW::cleanup() { DEBUG(" [WINDOW] Window cleanedup"); }

void WindowGLFW::setupCallbacks() {
  glfwSetKeyCallback(window_, [](GLFWwindow *window, int key, int scancode,
                                 int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  });
}
