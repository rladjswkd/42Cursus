#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.getName), grade(other.getGrade){}

Bureaucrat::Bureaucrat(const int grade){
	GradeTooHighException	exHigh;
	GradeTooLowException	exLow;
	
	try{
		if (grade )
	} catch{

	}
}

Bureaucrat::~Bureaucrat(void){

}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &other){

}

std::string	Bureaucrat::getName(void){

}

int		Bureaucrat::getGrade(void){

}

void	Bureaucrat::incGrade(void){

}

void	Bureaucrat::decGrade(void){

}
