/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:34:03 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:34:03 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int	main(void){
	Intern	someRandomIntern;
	Form	*rrf;
	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	
	Bureaucrat	b("Someone", 1);
	b.signForm(*rrf);
	b.executeForm(*rrf);
	return (0);
}
