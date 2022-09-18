#include "Converter.hpp"

int	main(int argc, char **argv){
	if (argc != 2)
		return (0);
	Converter c(argv[1]);
	c.convert();
}