#ifndef WINDOW_GLFW_H
#define WINDOW_GLFW_H

#include <GLFW/glfw3.h>

class WindowGLFW {
 public:
  WindowGLFW(int width, int height, const char* title);
  ~WindowGLFW();

  bool initialize();
  void run();
  bool shouldClose() const;
  void swapBuffers();
  void pollEvents();

 private:
  GLFWwindow* window_;
  void cleanup();
  int width_;
  int height_;
  const char* title_;

  void setupCallbacks();
};

#endif  // WINDOW_GLFW_H