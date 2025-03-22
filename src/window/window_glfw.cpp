#include "window_glfw.h"
#include "../engine/debug/debug_helper.h"

GLFWWindow::GLFWWindow(): window_instance_(nullptr), vulkan_instance_(nullptr), vulkan_surface_(nullptr) {
	GLFWWindow::initialize();
}

GLFWWindow::~GLFWWindow() {
	cleanup();
}

void GLFWWindow::initialize() {
	if (!glfwInit()) {
		std::cerr << "Erro ao inicializar GLFW";
		return;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	window_instance_ = glfwCreateWindow(800, 600, "NNEngine", nullptr, nullptr);
	if (!window_instance_) {
		std::cerr << "Error to create window";
		glfwTerminate();
		return;
	}

	if (!glfwVulkanSupported()) {
		std::cerr << "Vulkan não suportado pelo GLFW";
		glfwDestroyWindow(window_instance_);
		glfwTerminate();
		return;
	}

	uint32_t extensionCount = 0;
	const char **extensions = glfwGetRequiredInstanceExtensions(&extensionCount);
	std::vector<const char *> requiredExtensions(extensions, extensions + extensionCount);

	DEBUG(" [Window] Required extensions for GLFW:");
	for (const auto *ext: requiredExtensions) {
		DEBUG("		Extension: ", ext);
	}
	DEBUG(" ");

	appInfo_.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo_.pApplicationName = "GLFW Vulkan App";
	appInfo_.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo_.pEngineName = "No Engine";
	appInfo_.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo_.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo instanceInfo = {};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pApplicationInfo = &appInfo_;
	instanceInfo.enabledExtensionCount = extensionCount;
	instanceInfo.ppEnabledExtensionNames = requiredExtensions.data();

	checkResult(vkCreateInstance(&instanceInfo, nullptr, &vulkan_instance_), "Criando instância Vulkan");

	VkSurfaceKHR surface;
	checkResult(glfwCreateWindowSurface(vulkan_instance_, window_instance_, nullptr, &surface),
	            "[Window] Creating vulkan surface");
}

void GLFWWindow::run() {
	while (!glfwWindowShouldClose(window_instance_)) {
		glfwPollEvents();
	}

	cleanup();
}


void GLFWWindow::cleanup() const {
	DEBUG(" [Window] Window cleanup!");
	EventManager::getInstance()->NotifyWindowClose();
	vkDestroySurfaceKHR(vulkan_instance_, vulkan_surface_, nullptr);
	vkDestroyInstance(vulkan_instance_, nullptr);
	glfwDestroyWindow(window_instance_);
	glfwTerminate();
}
