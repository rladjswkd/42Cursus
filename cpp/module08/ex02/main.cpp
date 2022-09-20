/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:48:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/20 10:48:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
int main()
{
	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);
	
	MutantStack<int> mstack;
	std::stack<int>	stack;

	// std::cout << stack.top() << std::endl; // STL stack segfault.
	mstack.push(5);
	mstack.push(17);

	mstack.pop();

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	while (!s.empty()){
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	for (MutantStack<int>::reverseIterator i = mstack.rbegin(); i != mstack.rend(); i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	return 0;
}
