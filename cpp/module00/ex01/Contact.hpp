/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:49:35 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/09 08:49:36 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
	std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;
public:
	Contact();
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickName(std::string str);
	void		setPhoneNumber(std::string str);
	void		setDarkestSecret(std::string str);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
};
#endif
