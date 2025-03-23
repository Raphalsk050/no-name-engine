#include "scene.h"

#include "entity_handle.h"

Scene::Scene() {}
Scene::~Scene() {}
CameraManager& Scene::GetCameraManager() const { return *camera_manager_; }
SceneAttachmentManager& Scene::GetEntityManager() const {
  return *entity_manager_;
}
ComponentManager& Scene::GetComponentManager() const {
  return *component_manager_;
}

EntityHandle Scene::CreateEntity() { return EntityHandle(); }