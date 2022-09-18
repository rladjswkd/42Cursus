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

	Bureaucrat	b1(50);
	b1.setName("B1");
	Form		f1(49);
	b1.signForm(f1);

	Bureaucrat	b2(50);
	b2.setName("B2");
	Form		f2(50);
	b2.signForm(f2);

	Bureaucrat	b3(50);
	b3.setName("B3");
	Form		f3(51);
	b3.signForm(f3);
	return (0);
}
