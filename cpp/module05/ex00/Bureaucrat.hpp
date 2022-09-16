#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <string>
#include <iostream>
#include <exception>
class Bureaucrat
{
private:
	std::string	name;
	int			grade;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat(std::string name, const int grade);
	~Bureaucrat(void);
	Bureaucrat	&operator=(Bureaucrat &bureaucrat);
	std::string	getName(void) const;
	void		setName(std::string name);
	int			getGrade(void) const;
	void		incGrade(void);
	void		decGrade(void);
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif