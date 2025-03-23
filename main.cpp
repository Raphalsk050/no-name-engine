#include <iostream>
#include "src/engine/engine.h"

int main() {
	auto engine = new Engine();
	engine->Initialize();

	delete engine;
	return 0;
}