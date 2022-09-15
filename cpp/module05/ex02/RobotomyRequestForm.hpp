#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
private:

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm &);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator=(RobotomyRequestForm &);
};

RobotomyRequestForm::RobotomyRequestForm(void){

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &){

}

RobotomyRequestForm::~RobotomyRequestForm(void){

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &){

}
#endif