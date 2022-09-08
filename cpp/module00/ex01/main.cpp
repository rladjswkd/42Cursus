#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	pb;
	std::string	input;

	while (1){
		std::cout << "input ADD, SEARCH or EXIT: ";
		getline(std::cin, input);

		if (input.compare("ADD") == 0)
			pb.ADD();
		else if (input.compare("SEARCH") == 0)
			pb.SEARCH();
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}