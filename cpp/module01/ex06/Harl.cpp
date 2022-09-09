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
	
	if (i == 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	for (; i < 4; i++){
		std::cout << "[ " << funcNames[i] << " ]" << std::endl;
		(this->*(fp[i]))();
		std::cout << std::endl;
	}
}
