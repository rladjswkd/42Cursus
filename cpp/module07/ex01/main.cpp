#include <iostream>
#include "iter.hpp"
void	increase(int &v){
	v++;
}

void	print(int &v){
	std::cout << v << " ";
}

template <class T>
T	decrease(T &v){
	--v;
	return (v);
}

template <class T>
T	printTemplate(T &v){
	std::cout << v << " ";
	return (v);
}

int main( void ) {
	int		arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float	arrf[10] = {0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f};

	::iter(arr, 10, increase);
	::iter(arr, 10, print);
	std::cout << std::endl;

	::iter(arr, 10, decrease<int>);
	::iter(arr, 10, printTemplate<int>);
	
	std::cout << std::endl;
	::iter(arrf, 10, decrease<float>);
	::iter(arrf, 10, printTemplate<float>);
	std::cout << std::endl;
	return 0;
}