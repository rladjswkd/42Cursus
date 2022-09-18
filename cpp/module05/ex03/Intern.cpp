/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form	*Intern::createShrubbery(std::string target){
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::createRobotomy(std::string target){
	return (new RobotomyRequestForm(target));
}

Form	*Intern::createPresidential(std::string target){
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void){
	nameIndexMap["ShrubberyCreationForm"] = 0;
	nameIndexMap["RobotomyRequestForm"] = 1;
	nameIndexMap["PresidentialPardonForm"] = 2;
	fp[0] = &Intern::createShrubbery;
	fp[1] = &Intern::createRobotomy;
	fp[2] = &Intern::createPresidential;
}

Intern::Intern(Intern &other){
	(void)other;
	nameIndexMap["ShrubberyCreationForm"] = 0;
	nameIndexMap["RobotomyRequestForm"] = 1;
	nameIndexMap["PresidentialPardonForm"] = 2;
	fp[0] = &Intern::createShrubbery;
	fp[1] = &Intern::createRobotomy;
	fp[2] = &Intern::createPresidential;
}

Intern::~Intern(void){}

Intern	&Intern::operator=(Intern &other){ 
	(void)other;
	return (*this);
}

Form	*Intern::makeForm(std::string formName, std::string formTarget){
	Form	*ret;

	try {
		ret = (this->*(fp[nameIndexMap.at(formName)]))(formTarget);
		std::cout << "Intern creates " << formName << std::endl;
	} catch (std::exception &ex) {
		std::cout << "This Form(name) does NOT exist" << std::endl;
	}
	return (ret);
}
