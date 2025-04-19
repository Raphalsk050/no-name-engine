cmake_minimum_required(VERSION 2.4.3)
project(no_name_engine)

# needed packages
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)


# bullet path
set(BULLET_PATH third_party/bullet)
set(SPDLOG_PATH third_party/spdlog)
set(CMAKE_CXX_STANDARD 20)

# rules to compile only the necessary libs from bullet
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Bullet as static library")
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "Disable Bullet2 demos")
set(BUILD_CPU_DEMOS OFF CACHE BOOL "Disable CPU demos")
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "Disable OpenGL demos")
set(BUILD_UNIT_TESTS OFF CACHE BOOL "Disable Unit Tests")
set(BUILD_EXTRAS OFF CACHE BOOL "Disable Extras")
set(INSTALL_LIBS ON CACHE BOOL "Install Bullet libraries")

add_library(no_name_engine STATIC
        src/engine/base/components/transform.cpp
        src/engine/base/components/transform.h
        src/engine/base/managers/camera_manager.cpp
        src/engine/base/managers/camera_manager.h
        # events ------------------------------
        src/events/event_manager.h
        src/events/event_manager.cpp
        # scene -------------------------------
        src/scene/scene.h
        src/scene/scene.cpp
        # window ------------------------------
        src/window/window_glfw.cpp
        src/window/window_glfw.h
        src/window/window_system.h
        src/window/window_system.cpp
        # physics -----------------------------
        src/physics/rigidbody_component.cpp
        src/physics/rigidbody_component.h
        src/physics/physics_system.cpp
        src/physics/physics_system.h
        src/physics/physics_world.cpp
        src/physics/physics_world.h
        src/physics/physics_manager.cpp
        src/physics/physics_manager.h
        # entity ------------------------------
        src/entity/entity_system.cpp
        src/entity/entity_system.h
        src/entity/entity.h
        src/entity/entity.cpp
        src/entity/entity_handle.h
        src/entity/entity_handle.cpp
        src/entity/entity_manager.h
        src/entity/entity_manager.cpp
        # component ---------------------------
        src/component/component_system.cpp
        src/component/component_system.h
        src/component/component.h
        src/component/component.cpp
        src/component/component_handle.h
        src/component/component_handle.cpp
        # debug -------------------------------
        src/engine/debug/debug_helper.h
        # input -------------------------------
        src/input/input_system.cpp
        src/input/input_system.h
        # engine ------------------------------
        src/engine/base/types.h
        src/engine/base/systems/engine_system.cpp
        src/engine/base/systems/engine_system.h
        src/engine/engine.cpp
        src/engine/engine.h
        no_name_engine.h
)

# bullet directory
add_subdirectory(${BULLET_PATH})
add_subdirectory(${SPDLOG_PATH})

# bullet lib includes
target_include_directories(no_name_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${BULLET_PATH}/src)

target_link_libraries(no_name_engine PUBLIC BulletDynamics BulletCollision LinearMath spdlog::spdlog glfw GLEW::GLEW "-framework OpenGL")
