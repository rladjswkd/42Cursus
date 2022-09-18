/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:49:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:49:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
template <class T>
class Array 
{
private:
	T				*arr;
	unsigned int	len;
public:
	class OutOfBoundsException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	~Array(void);
	Array			&operator=(const Array &other);
	T				&operator[](const int index) const;
	unsigned int	size(void) const;
};

template <class T>
Array<T>::Array(void) : arr(new T[0]), len(0) {} // new T[0] is legal! it has no elements but has its own address.

template <class T>
Array<T>::Array(unsigned int n) : arr(new T[n]), len(n) {}

//deep copy
template <class T>
Array<T>::Array(const Array &other) : arr(new T[0]), len(0) { *this = other; } //without "arr(new T[0]), len(0)", delete[] (arr); statement causes segfault.

template <class T>
Array<T>::~Array(void){ delete[] (arr); }

//deep copy
template <class T>
Array<T>	&Array<T>::operator=(const Array<T> &other){
	if (this != &other){
		delete[] (arr);
		len = other.len;
		arr = new T[len];
		for (unsigned int i = 0; i < len; i++)
			arr[i] = (other.arr)[i];
	}
	return (*this);
}

template <class T>
T	&Array<T>::operator[](const int index) const{
	if (index < 0 || len <= static_cast<unsigned int>(const_cast<int&>(index)))
		throw (OutOfBoundsException());
	return (arr[index]);
}

template <class T>
const char	*Array<T>::OutOfBoundsException::what(void) const throw(){
	return ("Index is out of range!");
}

template <class T>
unsigned int	Array<T>::size(void) const{ return (len); }
#endif
