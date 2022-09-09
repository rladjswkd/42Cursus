/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:13 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type){
	setType(type);
}

const std::string	&Weapon::getType(void){
	return (type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}
