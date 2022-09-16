#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
private:
	std::string		target;
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
	try{
		checkCondition(executor);
	} catch (std::exception &ex) {
		throw ex;
	}
}
#endif