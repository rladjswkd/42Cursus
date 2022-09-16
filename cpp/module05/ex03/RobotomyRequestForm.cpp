#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequsetForm", 72, 45), target("NoTarget") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : Form(other) { *this = other; }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequsetForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &other){
	target = other.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		checkCondition(executor);
	} catch (Form::GradeTooHighException &highEx){
		throw highEx;
	} catch (Form::GradeTooLowException &lowEx) {
		throw lowEx;
	}
	std::cout << "[ DU DUDU DUDUDUDUDUDU ]" << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << target << " has NOT been robotomized" << std::endl;
}