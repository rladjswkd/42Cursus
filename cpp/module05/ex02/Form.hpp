#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeSign;
	const int			gradeExec;

protected:
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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class FileNotOpenException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

public:

	Form(void);
	Form(Form &);
	Form(std::string name, int gradeSign, int gradeExec);
	~Form(void);
	Form	&operator=(Form &);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	void		beSigned(const Bureaucrat &bureaucrat);

	void	checkCondition(Bureaucrat const & executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &os, Form const &form);
#endif