#include "event_manager.h"

EventManager* EventManager::instance = nullptr;

EventManager* EventManager::getInstance() {
    if (instance == nullptr) {
        instance = new EventManager();
    }
    return instance;
}