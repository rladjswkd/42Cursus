/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:29 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog &);
	~Dog(void);
	Dog &operator=(Dog &);

	virtual void	makeSound(void) const;
};
#endif
