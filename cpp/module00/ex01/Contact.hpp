#ifndef CONTACT_HPP
#define CONTACK_HPP
#include <string>

class Contact
{
	std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;
public:
	Contact();
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickName(std::string str);
	void		setPhoneNumber(std::string str);
	void		setDarkestSecret(std::string str);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
};
#endif