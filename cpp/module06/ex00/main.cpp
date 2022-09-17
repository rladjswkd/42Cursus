#include <iostream>
#include <limits>

int	main(int argc, char **argv){
	float	f = std::numeric_limits<float>::infinity();
	std::cout << f << std::endl;
	return (0);
}