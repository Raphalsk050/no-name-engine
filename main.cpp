#include <iostream>
#include "src/engine/engine.h"

int main() {
	Engine* engine = new Engine();
	engine->Initialize(nullptr);

	delete engine;
	return 0;
}