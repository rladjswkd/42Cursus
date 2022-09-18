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
T	min(T const &val1, T const &val2){
	return (val1 < val2 ? val1 : val2);
}

template <class T>
T	max(T const &val1, T const &val2){
	return (val1 > val2 ? val1 : val2);
}
