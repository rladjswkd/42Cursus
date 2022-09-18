#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
class Converter 
{
private:
	std::string	source;
	// class NonDisplayableException : public std::exception
	// {
	// 	const char	*what(void) const throw();
	// };
	// class ImpossibleConversionException : public std::exception
	// {
	// 	const char	*what(void) const throw();
	// };
public:
	
	Converter(void);
	Converter(Converter &other);
	Converter(std::string source);
	~Converter(void);
	Converter	&operator=(Converter &other);
};

Converter::Converter(void) : source("") {}
Converter::Converter(Converter &other){ *this = other; }
Converter::~Converter(void){}
Converter	&Converter::operator=(Converter &other){ 
	source = other.source;
	return (*this);
}

Converter::Converter(std::string source) : source(source) {}

// const char	*Converter::NonDisplayableException::what(void) const {
// 	return ("Non displayable");
// }

// const char	*Converter::ImpossibleConversionException::what(void) const {
// 	return ("Impossible");
// }

std::ostream	&operator<<(std::ostream &os, const Converter &converter){

}
#endif