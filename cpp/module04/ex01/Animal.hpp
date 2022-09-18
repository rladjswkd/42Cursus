/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>
class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(Animal &);
	virtual ~Animal(void);
	Animal &operator=(Animal &);

	virtual void	makeSound(void) const;
	std::string	getType(void) const;
};
#endif
