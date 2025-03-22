#include <iostream>
#include "src/engine/engine.h"

int main() {
	auto engine = new Engine();
	engine->Initialize(nullptr);

	delete engine;
	return 0;
}