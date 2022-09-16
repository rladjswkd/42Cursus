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

#endif