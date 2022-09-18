/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:57 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:57 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat(void);
	Cat(Cat &);
	~Cat(void);
	Cat &operator=(Cat &);

	virtual void	makeSound(void) const;
	void			printIdea(int index);
	void			setIdea(int index, std::string idea);
};
#endif

