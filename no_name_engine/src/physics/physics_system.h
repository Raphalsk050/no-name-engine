#pragma once
#include "../engine/base/systems/engine_system.h""
#include "../physics/physics_manager.h"

class PhysicsSystem : public EngineSystem {
public:
    PhysicsSystem();
    ~PhysicsSystem() override;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Shutdown() override;
    
    PhysicsManager* GetPhysicsManager() const { return physics_manager_; }
    
    // Sistema de física específico
    btRigidBody* AddRigidBody(btVector3 origin, float mass, btCollisionShape* shape);
    void SetGravity(const btVector3& gravity);

private:
    PhysicsManager* physics_manager_ = nullptr;
};