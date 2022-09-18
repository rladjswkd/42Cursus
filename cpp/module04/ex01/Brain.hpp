/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:31:54 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:31:55 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>
class Brain
{
private:
	std::string	ideas[100];
public:
	Brain(void);
	Brain(Brain &);
	~Brain(void);
	Brain	&operator=(Brain &);

	std::string	getIdea(int index);
	void		setIdea(int index, std::string idea);
};
#endif
