/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:35:42 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:35:43 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
void	swap(T &val1, T &val2){
	T	temp = val1;
	val1 = val2;
	val2 = temp;
}

template <class T>
T	min(T val1, T val2){
	T	res = val2;
	if (val1 < val2)
		res = val1;
	return (res);
}

template <class T>
T	max(T val1, T val2){
	T	res = val2;
	if (val1 > val2)
		res = val1;
	return (res);	
}
