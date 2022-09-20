/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:02:24 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/20 09:02:25 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"
#define	COUNT	10000
int main()
{
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	std::vector<int>	vec;
	Span sp2(COUNT);

	srand(time(0));
	for (size_t i = 0; i < COUNT + 1; i++) // COUNT + 1 to test VectorFullException.
		vec.push_back(rand() % 500);
	
	try{
		sp2.fill(vec.begin(), vec.end());
	} catch (Span::VectorFullException &ex){
		std::cout << ex.what() << std::endl;
	}
	
	try{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (Span::NoSpanException &ex){
		std::cout << ex.what() << std::endl;
	}
return 0;
}
