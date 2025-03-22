#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>
#include "window.h"

class GLFWWindow : public Window {
	struct Vertex {
		float pos[2]; // Posição 2D (x, y)
	};

	// Função auxiliar para verificar erros Vulkan
	void checkResult(VkResult result, const char *msg) {
		if (result != VK_SUCCESS) {
			std::cerr << "Erro Vulkan: " << msg << " (" << result << ")\n";
			exit(1);
		}
	}

public:
	GLFWWindow();

	~GLFWWindow();

	void run();

private:
	void initialize() override;

	void cleanup() const;

	GLFWwindow *window_instance_;
	VkInstance vulkan_instance_;
	VkApplicationInfo appInfo_ = {};
	VkInstanceCreateInfo create_info_ = {};
	VkSurfaceKHR vulkan_surface_;
};
