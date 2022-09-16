#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
private:
	std::string		target;
public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator=(PresidentialPardonForm &other);

	void	execute(Bureaucrat const & executor) const;
};
#endif