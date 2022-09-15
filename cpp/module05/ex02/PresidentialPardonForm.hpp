#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
private:

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm &);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator=(PresidentialPardonForm &);
};

PresidentialPardonForm::PresidentialPardonForm(void){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &){

}

PresidentialPardonForm::~PresidentialPardonForm(void){

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &){

}
#endif