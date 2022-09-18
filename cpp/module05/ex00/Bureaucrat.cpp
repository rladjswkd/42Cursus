/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:18 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:19 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name), grade(other.grade){}

Bureaucrat::Bureaucrat(std::string name, const int inGrade) : name(name){
	std::cout << "grade constructor called" << std::endl;
	if (inGrade < 1){
		grade = 150;
		throw GradeTooHighException();
	}
	if (inGrade > 150)
	{
		grade = 150;
		throw GradeTooLowException();
	}
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
