/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:35:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:35:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
void	print(const int &v){
	std::cout << v << " ";
}

template <class T>
void	printTemplate(const T &v){
	std::cout << v << " ";
}

int main( void ) {
	int			arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	float		arrf[10] = {0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f};
	std::string	arrs[3] = {"hello", "world", "!"};

	::iter(arr, 10, print);
	std::cout << std::endl;

	::iter(arr, 10, printTemplate<int>);
	std::cout << std::endl;
	
	::iter(arrf, 10, printTemplate<float>);
	std::cout << std::endl;

	::iter(arrs, 3, printTemplate<std::string>);
	std::cout << std::endl;
	return 0;
}
