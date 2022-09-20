/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:48:30 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/20 10:48:32 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator					iterator;
	typedef typename std::stack<T>::container_type::const_iterator				constIterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator		constReverseIterator;
	typedef typename std::stack<T>::container_type::reverse_iterator			reverseIterator;

	MutantStack(void);
	MutantStack(const MutantStack &other);
	~MutantStack(void);
	MutantStack	&operator=(const MutantStack &other);


	iterator				begin(void);
	iterator				end(void);
	constIterator			begin(void) const;
	constIterator			end(void) const;
	constReverseIterator	rbegin(void) const;
	constReverseIterator	rend(void) const;
	reverseIterator			rbegin(void);
	reverseIterator			rend(void);
};

template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) { *this = other; }

template <class T>
MutantStack<T>::~MutantStack(void){}

template <class T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &other){
	if (this != &other)
		this->c = other.c;
	return (*this);	
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void){ return (this->c.begin()); }

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void){ return (this->c.end()); }

template <class T>
typename MutantStack<T>::constIterator	MutantStack<T>::begin(void) const{ return (this->c.begin()); }

template <class T>
typename MutantStack<T>::constIterator	MutantStack<T>::end(void) const{ return (this->c.end()); }

template <class T>
typename MutantStack<T>::constReverseIterator	MutantStack<T>::rbegin(void) const{ return (this->c.rbegin()); }

template <class T>
typename MutantStack<T>::constReverseIterator	MutantStack<T>::rend(void) const{ return (this->c.rend()); }

template <class T>
typename MutantStack<T>::reverseIterator	MutantStack<T>::rbegin(void){ return (this->c.rbegin()); }

template <class T>
typename MutantStack<T>::reverseIterator	MutantStack<T>::rend(void){ return (this->c.rend()); }

#endif
