/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:34:33 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:34:34 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <limits>
#include <cmath>
class Converter 
{
private:
	std::string	source;

	char		charVal;
	int			intVal;
	long long	tempVal;
	float		floatVal;
	double		doubleVal;
	bool		isNaN;
	int			isInf;

	bool	isNumber(char ch);
	bool	isFirstOfNumberTypes(char ch);

	bool	isChar(void);
	bool	isInt(void);
	bool	isFloat(void);
	bool	isDouble(void);

	void	setVals(void);

	std::string	getCharString(void);
	std::string	getIntString(void);
	std::string	getFloatString(void);
	std::string	getDoubleString(void);
public:
	
	Converter(void);
	Converter(Converter &other);
	Converter(std::string source);
	~Converter(void);
	Converter	&operator=(Converter &other);

	void	convert(void);
};

#endif
