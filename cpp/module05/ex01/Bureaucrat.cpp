#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name), grade(other.grade){}

Bureaucrat::Bureaucrat(const int inGrade) : name("Noname"){
	std::cout << "grade constructor called" << std::endl;
	if (inGrade < 1)
		throw GradeTooHighException();
	if (inGrade > 150)
		throw GradeTooLowException();
	grade = inGrade;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &other){
	name = other.name;
	grade = other.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const{
	return (name);
}

void		Bureaucrat::setName(std::string name){
	this->name = name;
}

int		Bureaucrat::getGrade(void) const{
	return (grade);
}

void	Bureaucrat::incGrade(void){
	std::cout << "incGrade called" << std::endl;
	if (grade < 2)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decGrade(void){
	std::cout << "decGrade called" << std::endl;
	if (grade > 149)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(Form &form){
	try{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception &ex){
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("This grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("This grade is too low!");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
