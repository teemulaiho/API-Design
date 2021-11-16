#include "Container.h"
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept {
	Container<int> container_a(1);
	Container<int> container_b(2);

	container_b = container_a;
	return 0;
}