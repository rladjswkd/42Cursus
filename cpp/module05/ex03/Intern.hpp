#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "Form.hpp"
class Intern 
{
private:

public:

	Intern(void);
	Intern(Intern &);
	~Intern(void);
	Intern	&operator=(Intern &);

	Form	*makeForm(std::string formName, std::string formTarget);
};

Intern::Intern(void){}

Intern::Intern(Intern &other){ *this = other; }

Intern::~Intern(void){}

Intern	&Intern::operator=(Intern &){ return (*this); }

Form	*makeForm(std::string formName, std::string formTarget){
	
}
#endif