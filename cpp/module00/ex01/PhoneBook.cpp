/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:49:49 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/09 08:49:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(){
	pos = 0;
}

std::string	PhoneBook::modifyString(std::string str){
	if (str.length() > 9){
		str.at(9) = '.';
		str.resize(10);
	}
	return (str);
}

void	PhoneBook::printInfoOf(int index){
	Contact current = phoneBook[index - 1];

	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << modifyString(current.getFirstName()) << "|";
	std::cout << std::setw(10) << modifyString(current.getLastName()) << "|";
	std::cout << std::setw(10) << modifyString(current.getNickName()) << std::endl;
}

void	PhoneBook::ADD(void){
	Contact		current;
	std::string	temp = "";

	while (temp.empty()){
		std::cout << "first name : ";
		getline(std::cin, temp);
	}
	current.setFirstName(temp);
	temp = "";
	while (temp.empty()){
		std::cout << "last name : ";
		getline(std::cin, temp);
	}
	current.setLastName(temp);
	temp = "";
	while (temp.empty()){
		std::cout << "nick name : ";
		getline(std::cin, temp);
	}
	current.setNickName(temp);
	temp = "";
	while (temp.empty()){
		std::cout << "phone number : ";
		getline(std::cin, temp);
	}
	current.setPhoneNumber(temp);
	temp = "";
	while (temp.empty()){
		std::cout << "darkest secret : ";
		getline(std::cin, temp);
	}
	current.setDarkestSecret(temp);
	phoneBook[pos % 8] = current;
	pos++;
}

void	PhoneBook::SEARCH(void){
	int			idx = -1;
	std::string	temp;

	if (pos == 0){
		std::cout << "Nothing is in this phonebook." << std::endl;
		return ;
	}
	while (idx < 1 || idx > 8){
		std::cout << "index of the entry to display : ";
		getline(std::cin, temp);
		if (temp.length() == 1 && 48 < temp.at(0) && temp.at(0) < 57)
			idx = temp.at(0) - 48;
	}
	if (idx - 1 >= pos){
		std::cout << "index is too big" << std::endl;
		return ;
	}
	printInfoOf(idx);
}
