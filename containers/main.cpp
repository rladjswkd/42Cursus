#include <vector>
#include <iostream>

int main() {
	std::vector<int>	v = {2, 3, 1, 4};

	auto a = v.begin() + 3;
	std::cout << *a << std::endl;
	return (0);	
}