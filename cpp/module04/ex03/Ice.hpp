/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:57 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:58 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice &);
	~Ice(void);
	Ice	&operator=(Ice &);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
