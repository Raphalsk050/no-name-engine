cmake_minimum_required(VERSION 3.28)
project(no_name_engine)

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
        src/window/window.h
        src/engine/debug/debug_helper.h
)

# bullet directory
add_subdirectory(third_party/bullet)

# bullet lib includes
target_include_directories(no_name_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/bullet/src)
target_link_libraries(no_name_engine PRIVATE BulletDynamics BulletCollision LinearMath)
