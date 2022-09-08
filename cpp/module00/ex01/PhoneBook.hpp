#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	int		pos;
	Contact	phoneBook[8];
public:
	PhoneBook();
	std::string	modifyString(std::string);
	void		printInfoOf(int);
	void		ADD(void);
	void		SEARCH(void);
};
