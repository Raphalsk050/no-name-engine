#pragma once

#include <functional>
#include <vector>

using WindowCloseDelegate = std::function<void()>;
class EventManager {
 public:
  static EventManager* getInstance();

  void AddWindowCloseListener(WindowCloseDelegate delegate) {
    windowCloseDelegates.push_back(delegate);
  }

  void NotifyWindowClose() {
    for (auto& delegate : windowCloseDelegates) {
      delegate();
    }
  }

 private:
  static EventManager* instance;
  std::vector<WindowCloseDelegate> windowCloseDelegates;
};