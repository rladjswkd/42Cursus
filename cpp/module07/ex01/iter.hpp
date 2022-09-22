/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:35:43 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:35:44 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
// no return type for fp because iter returns nothing.
template <class T, class U> 
void	iter(T *array, U len, void (*fp)(T &)){
	for (U i = 0; i < len; i++)
		(*fp)(array[i]);
}

template <class T, class U>
void	iter(T *array, U len, void (*fp)(const T &)){
	for (U i = 0; i < len; i++)
		(*fp)(array[i]);
}
#endif
