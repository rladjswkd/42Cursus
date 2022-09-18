/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:00 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	for (int i = 0; i < 4; i++)
		learned[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource &other){
	for (int i = 0; i < 4; i++)
		learned[i] = 0;
	*this = other;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 4; i++)
		delete (learned[i]);
}

MateriaSource	&MateriaSource::operator=(MateriaSource &other){
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++){
		delete (learned[i]);
		learned[i] = 0;
		if (other.learned[i])
			learned[i] = other.learned[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
	int	i = 0;
	if (!materia)
		return ;
	while (i < 4 && learned[i])
		i++;
	if (i < 4)
		learned[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
		if (learned[i] && learned[i]->getType().compare(type) == 0)
			return (learned[i]->clone());
	return (0);
}
