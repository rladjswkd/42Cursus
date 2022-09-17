#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>
#include <iostream>
#include <sstream>
class Converter 
{
private:

public:

	Converter(void);
	Converter(Converter &other);
	~Converter(void);
	Converter	&operator=(Converter &other);
};

Converter::Converter(void){}
Converter::Converter(Converter &other){}
Converter::~Converter(void){}
Converter	&Converter::operator=(Converter &other){ return (*this); }


#endif