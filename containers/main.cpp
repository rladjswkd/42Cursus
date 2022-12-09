#include <vector>
#include <iostream>
#include <algorithm>

template<typename It>
void foo(It begin, It end) {std::cout << "template" << std::endl;}
void foo(double*a, double*b, int n=0) {std::cout << "non_tempalte" << std::endl;}


int main() {
	std::vector<int>	v = {2, 3, 1, 4};
	int	arr[4] = {2, 3, 1, 4};

	std::sort(v.begin(), v.end());
	std::sort(arr, arr + 4);

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v.at(i);
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
	return (0);
	
}