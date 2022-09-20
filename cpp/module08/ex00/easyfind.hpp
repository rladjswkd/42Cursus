/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:03:01 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 13:03:02 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>
template <class T>
typename T::iterator	easyfind(T container, int val){
	typename T::iterator	it = std::find(container.begin(), container.end(), val);

	if (it == container.end())
		throw std::invalid_argument("Can't find!");
	return (it);
}
#endif
