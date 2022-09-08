#include <string>
#include <iostream>
#include <sstream> //c++20

int	main(void){
	std::string	str ("123.4");
	float		converted;

	std::stringstream(str) >> converted;
	converted += 1.0;
	std::cout << converted << std::endl;
}