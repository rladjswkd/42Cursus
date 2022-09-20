/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:30 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:31 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void){

	Bureaucrat	b1("B1", 50);
	Form		f1("F1", 49, 150);
	b1.signForm(f1);

	Bureaucrat	b2("B2", 50);
	Form		f2("F2", 50, 150);
	b2.signForm(f2);

	Bureaucrat	b3("B3", 50);
	Form		f3("F3", 51, 150);
	b3.signForm(f3);
	return (0);
}
