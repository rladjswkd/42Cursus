/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:55 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:56 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), target("NoTarget") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : Form(other) { *this = other; }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &other){
	target = other.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try{
		checkCondition(executor);
	} catch (Form::GradeTooHighException &highEx){
		throw highEx;
	} catch (Form::GradeTooLowException &lowEx) {
		throw lowEx;
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
