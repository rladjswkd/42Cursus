#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &os, const Form &form);

Form::Form(void) : name("Form"), isSigned(0), gradeSign(1), gradeExec(1){}

Form::Form(Form &form) : name(form.name), isSigned(form.isSigned), gradeSign(form.gradeSign), gradeExec(form.gradeExec){}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), isSigned(0), gradeSign(gradeSign), gradeExec(gradeExec){}

Form::~Form(void){}

Form	&Form::operator=(Form &other){
	const_cast<std::string&>(name) = other.name;
	isSigned = other.isSigned;
	const_cast<int&>(gradeSign) = other.gradeSign;
	const_cast<int&>(gradeExec) = other.gradeExec;
	return (*this);
}

std::string	Form::getName(void) const{
	return (name);
}

bool		Form::getIsSigned(void) const{
	return (isSigned);
}

int	Form::getGradeSign(void) const{
	return (gradeSign);
}

int	Form::getGradeExec(void) const{
	return (gradeExec);
}

std::ostream	&operator<<(std::ostream &os, const Form &form){
	std::cout << "Form name : " << form.getName() 
			<< "Statue : " << (form.getIsSigned()? "signed" : "NOT signed")
			<< "Grade needed to sign this form : " << form.getGradeSign()
			<< "Grade needed to execute this form : " << form.getGradeExec()
			<< std::endl;
	return (os);
}

void	Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigned = 1;
}

void	Form::checkCondition(Bureaucrat const & executor) const{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > gradeExec)
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what(void) const throw(){
	return ("This grade is too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw(){
	return ("This grade is too low!");
}

const char	*Form::NotSignedException::what(void) const throw(){
	return ("You can't execute this form. It's not signed!");
}

const char	*Form::FileNotOpenException::what(void) const throw(){
	return ("File is not open!");
}