#include "Contact.hpp"

Contact::Contact(){
	FirstName = LastName = NickName = PhoneNumber = DarkestSecret = "";
}

void	Contact::setFirstName(std::string str){
	FirstName = std::string(str);
}

void	Contact::setLastName(std::string str){
	LastName = std::string(str);
}

void	Contact::setNickName(std::string str){
	NickName = std::string(str);
}

void	Contact::setPhoneNumber(std::string str){
	PhoneNumber = std::string(str);
}

void	Contact::setDarkestSecret(std::string str){
	DarkestSecret = std::string(str);
}

std::string	Contact::getFirstName(void){
	return (FirstName);
}

std::string	Contact::getLastName(void){
	return (LastName);
}

std::string	Contact::getNickName(void){
	return (NickName);
}

std::string	Contact::getPhoneNumber(void){
	return (PhoneNumber);
}

std::string	Contact::getDarkestSecret(void){
	return (DarkestSecret);
}
