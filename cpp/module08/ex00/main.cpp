/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:16:25 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 18:16:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#define	SIZE	10
int	main(void){
	int	arr[SIZE];
	for (size_t i = 0; i < SIZE; i++)
		arr[i] = i;
	
	std::vector<int>::iterator	it1;
	std::list<int>::iterator	it2;
	std::deque<int>::iterator	it3;

		
	std::vector<int>	vector(arr, arr + SIZE);
	std::list<int>		list(arr, arr + SIZE);
	std::deque<int>		deque(arr, arr + SIZE);
	// std::queue<int>		queue(deque);
	// std::stack<int>		stack(deque);

	it1 = easyfind(vector, SIZE / 2);
	if (it1 != vector.end())
		std::cout << *it1 << std::endl << std::endl;
	it1 = easyfind(vector, -2);
	if (it1 != vector.end())
		std::cout << *it1 << std::endl << std::endl;

	it2 = easyfind(list, SIZE / 2);
	if (it2 != list.end())
		std::cout << *it2 << std::endl << std::endl;
	it2 = easyfind(list, -2);
	if (it2 != list.end())
		std::cout << *it2 << std::endl << std::endl;

	it3 = easyfind(deque, SIZE / 2);
	if (it3 != deque.end())
		std::cout << *it3 << std::endl << std::endl;
	it3 = easyfind(deque, -2);
	if (it3 != deque.end())
		std::cout << *it3 << std::endl << std::endl;
	return (0);
}
