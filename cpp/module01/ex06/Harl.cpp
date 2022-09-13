/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:47:41 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:47:42 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){
	fp[0] = &Harl::debug;
	funcNames[0] = "DEBUG";
	fp[1] = &Harl::info;
	funcNames[1] = "INFO";
	fp[2] = &Harl::warning;
	funcNames[2] = "WARNING";
	fp[3] = &Harl::error;
	funcNames[3] = "ERROR";
}
void	Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int	Harl::isInFuncNames(std::string level){
	int	i = 0;

	while (i < 4 && funcNames[i].compare(level) != 0)
		i++;
	return (i);
}

void	Harl::complain(std::string level){
	size_t	i = isInFuncNames(level);
	
	switch (i){
		case (0):
			std::cout << "[ " << funcNames[0] << " ]" << std::endl;
			(this->*(fp[0]))();
			std::cout << std::endl;			
		case (1):
			std::cout << "[ " << funcNames[1] << " ]" << std::endl;
			(this->*(fp[1]))();
			std::cout << std::endl;
		case (2):
			std::cout << "[ " << funcNames[2] << " ]" << std::endl;
			(this->*(fp[2]))();
			std::cout << std::endl;
		case (3):
			std::cout << "[ " << funcNames[3] << " ]" << std::endl;
			(this->*(fp[3]))();
			std::cout << std::endl;
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;

	}
}
