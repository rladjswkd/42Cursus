/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:14 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:15 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(void);
	Weapon(std::string);

	const std::string	&getType(void);
	void				setType(std::string);
};
#endif
