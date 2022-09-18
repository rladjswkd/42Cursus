/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:46 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;
class AMateria
{
protected:
	std::string	type;
public:
	AMateria(void);
	AMateria(AMateria &);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria	&operator=(AMateria &);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif
