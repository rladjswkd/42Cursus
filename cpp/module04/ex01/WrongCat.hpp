/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:23 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:24 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat &);
	~WrongCat(void);
	WrongCat &operator=(WrongCat &);

	void	makeSound(void) const;
};
#endif

