/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:32:25 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:32:25 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	
	Animal	*animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i++){
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++){
		delete (animals[i]);
	}

	Cat	*a = new Cat;
	Cat	*a2 = new Cat;
	
	a->setIdea(0, "hello");
	*a2 = *a;
	delete (a);
	a2->printIdea(0);
	delete (a2);
	Dog basic;
	{
		Dog temp = basic;
	}
	system("leaks program");
	return 0;
}
