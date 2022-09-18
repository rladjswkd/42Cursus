/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:45 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("NoType"){}

AMateria::AMateria(AMateria &other) {
	*this = other;
}

AMateria::AMateria(std::string const & type) : type(type){}

AMateria::~AMateria(void){}

AMateria	&AMateria::operator=(AMateria &other){
	(void)other;
	// copying type doesn't make sense.
	return (*this);
}

std::string const & AMateria::getType() const{
	return (type);
}

void AMateria::use(ICharacter& target){
	std::cout << "It is invalid for " << target.getName() << " to use AMateria" << std::endl;
}
