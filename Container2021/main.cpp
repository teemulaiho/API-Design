#include "Container.h"
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) noexcept {
	
	Container<int> container{ 1, 2, 3, 4 };

	for (auto c : container)
	{
		std::cout << c << "\n";
	}

	auto sum = std::accumulate(container.begin(), container.end(), 0);

	std::cout << sum << "\n";

	return 0;
}