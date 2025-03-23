cmake_minimum_required(VERSION 3.28)
project(no_name_engine)

# needed packages
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 20)

# rules to compile only the necessary libs from bullet 
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Bullet as static library")
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "Disable Bullet2 demos")
set(BUILD_CPU_DEMOS OFF CACHE BOOL "Disable CPU demos")
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "Disable OpenGL demos")
set(BUILD_UNIT_TESTS OFF CACHE BOOL "Disable Unit Tests")
set(BUILD_EXTRAS OFF CACHE BOOL "Disable Extras")
set(INSTALL_LIBS ON CACHE BOOL "Install Bullet libraries")

add_executable(no_name_engine main.cpp
        src/physics/physics_world.cpp
        src/physics/physics_world.h
        src/engine/engine.cpp
        src/engine/engine.h
        src/window/window_glfw.cpp
        src/window/window_glfw.h
        src/engine/debug/debug_helper.h
        src/events/event_manager.h
        src/engine/base/component.cpp
        src/engine/base/component.h
        src/engine/base/scene.cpp
        src/engine/base/scene.h
        src/engine/base/entity.cpp
        src/engine/base/entity.h
        src/engine/base/managers/entity_manager.cpp
        src/engine/base/managers/entity_manager.h
        src/engine/base/managers/component_manager.cpp
        src/engine/base/managers/component_manager.h
        src/engine/base/managers/camera_manager.cpp
        src/engine/base/managers/camera_manager.h
        src/engine/base/systems/component_system.cpp
        src/engine/base/systems/component_system.h
        src/engine/base/systems/entity_system.cpp
        src/engine/base/systems/entity_system.h
        src/engine/base/systems/camera_system.cpp
        src/engine/base/systems/camera_system.h
        src/engine/base/entity_handle.cpp
        src/engine/base/entity_handle.h
)

# sdl lib
include_directories(${SDL2_INCLUDE_DIRS})

# bullet directory
add_subdirectory(third_party/bullet)

# bullet lib includes
target_include_directories(no_name_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/bullet/src)

target_link_libraries(no_name_engine PRIVATE BulletDynamics BulletCollision LinearMath glfw GLEW::GLEW GL)
