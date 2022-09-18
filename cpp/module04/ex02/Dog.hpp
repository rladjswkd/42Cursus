/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:36 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog(void);
	Dog(Dog &);
	~Dog(void);
	Dog &operator=(Dog &);

	virtual void	makeSound(void) const;
	void			printIdea(int);
};
#endif
