/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:23 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:23 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void){
	try {
		Bureaucrat	b1(0);
	} catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	
	try {
		Bureaucrat	b2(151);
	} catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	
	try {
		Bureaucrat	b3(50);
		b3.incGrade();
		b3.setName("Bu");
	} catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	
	try {
		Bureaucrat	b4(150);
		b4.decGrade();
	} catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}

	try {
		Bureaucrat	b5(1);
		b5.incGrade();
	} catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
