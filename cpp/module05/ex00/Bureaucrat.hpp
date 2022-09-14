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
		const char	*what(void);
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what(void);
	};
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat &);
	Bureaucrat(const int);
	~Bureaucrat(void);
	Bureaucrat	&operator=(Bureaucrat &);
	std::string	getName(void);
	int			getGrade(void);
	void		incGrade(void);
	void		decGrade(void);
};
#endif