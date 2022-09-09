/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:49:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/09 08:50:29 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	int		pos;
	Contact	phoneBook[8];
public:
	PhoneBook();
	std::string	modifyString(std::string);
	void		printInfoOf(int);
	void		ADD(void);
	void		SEARCH(void);
};
#endif
