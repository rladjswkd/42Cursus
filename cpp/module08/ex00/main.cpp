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
#include <deque>
#include <list>
#include <vector>
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
	try{
		it1 = easyfind(vector, SIZE / 2);
		std::cout << *it1 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		it1 = easyfind(vector, -2);
		std::cout << *it1 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		it2 = easyfind(list, SIZE / 2);
		std::cout << *it2 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		it2 = easyfind(list, -2);
		std::cout << *it2 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		it3 = easyfind(deque, SIZE / 2);
		std::cout << *it3 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		it3 = easyfind(deque, -2);
		std::cout << *it3 << std::endl;
	} catch(std::exception &ex){
		std::cout << ex.what() << std::endl;
	}

	return (0);
}
