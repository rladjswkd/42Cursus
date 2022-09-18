/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:53 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:54 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>
class Intern 
{
private:
	std::map<std::string, int>	nameIndexMap;
	Form						*(Intern::*fp[3])(std::string target);
	
	Form	*createShrubbery(std::string target);
	Form	*createRobotomy(std::string target);
	Form	*createPresidential(std::string target);
public:

	Intern(void);
	Intern(Intern &);
	~Intern(void);
	Intern	&operator=(Intern &);

	Form	*makeForm(std::string formName, std::string formTarget);
};

#endif
