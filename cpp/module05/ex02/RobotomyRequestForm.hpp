#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
private:
	std::string		target;
	
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator=(RobotomyRequestForm &other);

	void	execute(Bureaucrat const & executor) const;
};

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequsetForm", 72, 45), target("NoTarget") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other){ *this = other; }

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &other){
	target = other.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		checkCondition(executor);
	} catch (std::exception &ex) {
		throw ex;
	}
	std::cout << "[ DU DUDU DUDUDUDUDUDU ]" << std::endl;
	
}
#endif