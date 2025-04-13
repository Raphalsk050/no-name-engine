#include <iostream>
#include "src/engine/engine.h"

// this is a comment
int main() {
	auto engine = new Engine();
	engine->Initialize();

	delete engine;
	return 0;
}
