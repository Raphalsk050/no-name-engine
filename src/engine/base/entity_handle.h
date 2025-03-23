#pragma once
#include <memory>

#include "entity.h"

class EntityHandle {
 public:
  EntityHandle() : entity_(std::make_unique<Entity>()) {}

  Entity& operator*() const { return *entity_; }
  Entity* operator->() const { return entity_.get(); }

  bool operator==(const EntityHandle& other) const {
    return entity_ == other.entity_;
  }

  bool operator!=(const EntityHandle& other) const {
    return entity_ != other.entity_;
  }

  explicit operator bool() const noexcept { return entity_ != nullptr; }

  [[nodiscard]] bool IsValid() const { return entity_ != nullptr; }

 private:
  std::unique_ptr<Entity> entity_;
};
