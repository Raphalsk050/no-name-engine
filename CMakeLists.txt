cmake_minimum_required(VERSION 3.30)
project(no_name_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(no_name_engine main.cpp
        src/physics/physics_world.cpp
        src/physics/physics_world.h
        src/engine/engine.cpp
        src/engine/engine.h
        src/window/window.h
)

# bullet directory
add_subdirectory(third_party/bullet)

# bullet lib includes
target_include_directories(no_name_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/bullet/src)
target_link_libraries(no_name_engine PRIVATE BulletDynamics BulletCollision LinearMath)
