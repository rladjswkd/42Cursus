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
template <class T, class U, class V>
void	iter(T *array, U len, V fp(T &)){
	for (U i = 0; i < len; i++)
		fp(array[i]);	
}
#endif
