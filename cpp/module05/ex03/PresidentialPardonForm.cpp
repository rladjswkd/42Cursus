#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), target("NoTarget") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : Form(other) { *this = other; }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &other){
	target = other.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try{
		checkCondition(executor);
	} catch (Form::GradeTooHighException &highEx){
		throw highEx;
	} catch (Form::GradeTooLowException &lowEx) {
		throw lowEx;
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}