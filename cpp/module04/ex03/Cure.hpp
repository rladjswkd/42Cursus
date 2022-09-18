/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:51 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure &);
	~Cure(void);
	Cure	&operator=(Cure &);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
