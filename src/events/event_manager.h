#pragma once

#include <vector>
#include <functional>

using WindowCloseDelegate = std::function<void()>;
class EventManager {
public:
	static EventManager* getInstance() {
		if (instance == nullptr) {
			instance = new EventManager();
		}
		return instance;
	}

	void AddWindowCloseListener(WindowCloseDelegate delegate) {
		windowCloseDelegates.push_back(delegate);
	}

	void NotifyWindowClose() {
		for (auto& delegate : windowCloseDelegates) {
			delegate();
		}
	}

private:
	EventManager() {}
	static EventManager* instance;
	std::vector<WindowCloseDelegate> windowCloseDelegates;
};