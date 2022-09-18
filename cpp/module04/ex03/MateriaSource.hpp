/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:01 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:01 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
	AMateria	*learned[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource &);
	~MateriaSource(void);
	MateriaSource	&operator=(MateriaSource &);

	void learnMateria(AMateria*);
	AMateria	*createMateria(std::string const &);
};
#endif
