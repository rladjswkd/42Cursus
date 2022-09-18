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

Converter::Converter(void) {
	source = "";
	charVal = 0;
	intVal = 0;
	floatVal = 0;
	doubleVal = 0;
	isNaN = 0;
	isInf = 0;
}
Converter::Converter(Converter &other){ *this = other; }
Converter::~Converter(void){}
Converter	&Converter::operator=(Converter &other){ 
	source = other.source;
	charVal = other.charVal;
	intVal = other.intVal;
	floatVal = other.floatVal;
	doubleVal = other.doubleVal;
	isNaN = other.isNaN;
	isInf = other.isInf;
	return (*this);
}

Converter::Converter(std::string source) : source(source){
	charVal = 0;
	intVal = 0;
	floatVal = 0;
	doubleVal = 0;
	isNaN = 0;
	isInf = 0;
}

bool	Converter::isChar(void){
	if (source.length() == 3 && source.at(0) == '\'' && source.at(2) == '\'')
		return (true);
	return (false);
}

bool	Converter::isNumber(char ch){
	return (47 < ch && ch < 58);
}

bool	Converter::isFirstOfNumberTypes(char ch){
	return (ch == '+' || ch == '-' || isNumber(ch));
}

bool	Converter::isInt(void){
	int	i = 1;
	int	len = source.length();

	if (!isFirstOfNumberTypes(source.at(0)))
		return (false);
	while (i < len && isNumber(source.at(i)))
		i++;
	return (i == len && isNumber(source.at(i - 1)));
}

bool	Converter::isFloat(void){
	int	i = 0;
	int	len = source.length();

	if (isFirstOfNumberTypes(source.at(0)))
		i++;
	while (i < len && isNumber(source.at(i)))
		i++;
	if (i >= len || source.at(i) != '.')
		return (false);
	i++;
	while (i < len && isNumber(source.at(i)))
		i++;
	return (i == len - 1 && source.at(i) == 'f');
}

bool	Converter::isDouble(void){
	int	i = 0;
	int	len = source.length();

	if (isFirstOfNumberTypes(source.at(0)))
		i++;
	while (i < len && isNumber(source.at(i)))
		i++;
	if (i >= len || source.at(i) != '.')
		return (false);
	i++;
	while (i < len && isNumber(source.at(i)))
		i++;
	return ((i == len && isNumber(source.at(i - 1))) || (i == len && source.at(i - 1) == '.'));
}

// input literals "MUST" be one of {'char', int, float, double}. others, like asdf.gyjf, can't be the input.
void	Converter::setVals(void){
	std::stringstream	stream;

	if (isChar()){
		charVal = source.at(1);
		intVal = static_cast<int>(charVal);
		floatVal = static_cast<float>(charVal);
		doubleVal = static_cast<double>(charVal);
	} else if (isInt()){
		stream << source;
		stream >> tempVal;
		charVal = static_cast<char>(tempVal);
		intVal = static_cast<int>(tempVal);
		floatVal = static_cast<float>(tempVal);
		doubleVal = static_cast<double>(tempVal);
		if (intVal != tempVal) // int overflows. so it isn't correct value for float or double.
			isNaN = true;
	} else if (isFloat()){
		stream << source;
		stream >> floatVal;
		charVal = static_cast<char>(floatVal);
		intVal = static_cast<int>(floatVal);
		tempVal = static_cast<long long>(floatVal);
		doubleVal = static_cast<double>(floatVal);
		if (floatVal <= -std::numeric_limits<float>::max())
			isInf = -1;
		if (std::numeric_limits<float>::max() <= floatVal)
			isInf = 1;
	} else if (isDouble()){
		stream << source;
		stream >> doubleVal;
		charVal = static_cast<char>(doubleVal);
		intVal = static_cast<int>(doubleVal);
		tempVal = static_cast<long long>(doubleVal);
		floatVal = static_cast<float>(doubleVal);
		if (doubleVal <= -std::numeric_limits<double>::max())
			isInf = -1;
		if (std::numeric_limits<double>::max() <= doubleVal)
			isInf = 1;
	} else{
		if (source.compare("+inff") == 0 || source.compare("+inf") == 0){
			floatVal = std::numeric_limits<float>::max();
			doubleVal = std::numeric_limits<double>::max();
			isInf = 1;
		}
		else if (source.compare("-inf") == 0 || source.compare("-inff") == 0){
			floatVal = std::numeric_limits<float>::min();
			doubleVal = std::numeric_limits<double>::min();			
			isInf = -1;
		}
		else if (source.compare("nanf") == 0 || source.compare("nan") == 0)
			isNaN = true;
		else{
			isNaN = true;
			isInf = 1;
		}
	}
}

std::string	Converter::getCharString(void){
	std::string	ret;

	if (charVal != tempVal || isNaN || isInf)
		return ("Impossible");
	if (charVal < 32 || 126 < charVal)
		return ("Non displayable");
	ret += charVal;
	return ("'" + ret + "'");
}

std::string	Converter::getIntString(void){
	std::stringstream	stream;
	std::string			ret;

	if (isNaN || isInf || intVal != tempVal)
		return ("Impossible");
	stream << intVal;
	stream >> ret;
	return (ret);
}

std::string	Converter::getFloatString(void){
	std::stringstream	stream;
	std::string			ret;

	if (isNaN && isInf)
		return ("Impossible");
	if (isNaN)
		return ("nanf");
	if (isInf == 1 || doubleVal >= std::numeric_limits<float>::max())
		return ("+inff");
	if (isInf == -1 || doubleVal <= -std::numeric_limits<float>::max())
		return ("-inff");
	stream << floatVal;
	stream >> ret;
	if (static_cast<long long>(floatVal) == floatVal)
		ret.append(".0");
	ret.append("f");
	return (ret);
}

std::string	Converter::getDoubleString(void){
	std::stringstream	stream;
	std::string			ret;

	if (isNaN && isInf)
		return ("Impossible");
	if (isNaN)
		return ("nan");
	if (isInf == 1)
		return ("+inf");
	if (isInf == -1)
		return ("-inf");
	stream << doubleVal;
	stream >> ret;
	if (static_cast<long long>(doubleVal) == doubleVal)
		ret.append(".0");
	return (ret);
}

void	Converter::convert(void){
	setVals();
	std::cout << "char: " << getCharString() << std::endl;
	std::cout << "int: " << getIntString() << std::endl;
	std::cout << "float: " << getFloatString()  << std::endl;
	std::cout << "double: " << getDoubleString() << std::endl;
}

#endif