/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:02:25 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/20 09:02:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
typedef	std::vector<int>::iterator	vecIter;
class Span 
{
private:
	std::vector<int>	vector;
	unsigned int		size;
public:
	class VectorFullException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
	class NoSpanException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
	Span(void);
	Span(const Span &other);
	Span(unsigned int N);
	~Span(void);
	Span	&operator=(const Span &other);
	void	addNumber(int number);
	int		shortestSpan(void);
	int		longestSpan(void);

	void	fill(const vecIter &begin, const vecIter &end);
};

#endif
