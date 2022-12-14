#include "equal.hpp"
#include <iostream>
#include <type_traits>
#include <algorithm>

bool foo(int p1, int p2) {
	return (p1 == p2);
}

int main() {
	std::cout << ft::is_pointer<int *>::value << std::endl;
	std::cout << ft::are_same<int, int>::value << std::endl;
	std::cout << ft::is_integral<int>::value << std::endl;

	std::vector<int>	v;
	std::vector<int>	other;

	v.push_back(1);
	v.push_back(1);
	v.push_back(2);

	other.push_back(1);
	other.push_back(1);
	other.push_back(2);

	std::cout << ft::equal(v.begin(), v.end(), other.begin()) << std::endl;

	int	iter[3] = {1, 2, 3};
	int iter2[3] = {1, 2, 3};

	std::cout << ft::equal(&(iter[0]), &(iter[3]), &(iter2[0])) << std::endl;

	int	iter3[3] = {0, 2, 3};
	int iter4[3] = {1, 2, 3};

	std::cout << ft::equal(&(iter3[0]), &(iter3[3]), &(iter4[0])) << std::endl;

	std::cout << ft::equal(&(iter[0]), &(iter[3]), &(iter2[0]), &foo) << std::endl;
	return (0);
}
