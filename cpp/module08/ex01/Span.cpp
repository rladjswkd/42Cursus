/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:02:22 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/20 09:02:23 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : size(0) {}

Span::Span(const Span &other){ *this = other; }

Span::Span(unsigned int N) : size(N) {}

Span::~Span(void){}

Span	&Span::operator=(const Span &other){
	if (this != &other){
		size = other.size;
		vector.clear();
		vector = other.vector;
	}
	return (*this);
}

void	Span::addNumber(int number){
	//N개 차있으면 exception
	if (vector.size() == size)
		throw (VectorFullException());
	vector.push_back(number);
}

int		Span::shortestSpan(void){
	int	span = std::numeric_limits<int>::max();
	//원소가 1개 이하면 exception
	if (vector.size() < 2)
		throw (NoSpanException());
	for (vecIter current = vector.begin(); current != vector.end(); current++){
		for (vecIter left = current - 1; left != vector.begin() - 1; left--)
			if (*left > *current){
				span = std::min(span, *left - *current);
				break ;
			}
		for (vecIter right = current + 1; right != vector.end(); right++)
			if (*right > *current){
				span = std::min(span, *right - *current);
				break ;
			}
	}
	return (span);	
}

int		Span::longestSpan(void){
	int	span = 0;

	//원소가 1개 이하면 exception
	if (vector.size() < 2)
		throw (NoSpanException());
	for (vecIter current = vector.begin(); current != vector.end(); current++){
		for (vecIter left = current - 1; left != vector.begin() - 1; left--)
			if (*left > *current){
				span = std::max(span, *left - *current);
				break ;
			}
		for (vecIter right = current + 1; right != vector.end(); right++)
			if (*right > *current){
				span = std::max(span, *right - *current);
				break ;
			}
	}
	return (span);
}

void	Span::fill(const vecIter &begin, const vecIter &end){
	try{
		// vector.insert(vector.end(), begin, end);
		for (vecIter it = begin; it != end; it++)
			addNumber(*it);
	} catch (VectorFullException &ex){
		throw ex;
	}
}

const char	*Span::VectorFullException::what(void) const throw(){
	return ("Vector is full now!");
}

const char	*Span::NoSpanException::what(void) const throw(){
	return ("You need more elements!");
}
