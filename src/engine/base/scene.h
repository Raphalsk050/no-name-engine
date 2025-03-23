#pragma once
#include <memory>
class ComponentManager;
class SceneAttachmentManager;
class CameraManager;
class EntityHandle;

class Scene {
 public:
  Scene();

  ~Scene();

  CameraManager& GetCameraManager() const;

  SceneAttachmentManager& GetEntityManager() const;

  ComponentManager& GetComponentManager() const;

  EntityHandle CreateEntity();

 private:
  std::unique_ptr<ComponentManager> component_manager_;
  std::unique_ptr<SceneAttachmentManager> entity_manager_;
  std::unique_ptr<CameraManager> camera_manager_;
};
