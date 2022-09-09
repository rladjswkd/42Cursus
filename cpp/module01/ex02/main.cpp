/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:45:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:45:31 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << std::endl
		<< stringPTR << std::endl
		<< &stringREF << std::endl;
	std::cout << str << std::endl
		<< *stringPTR << std::endl
		<< stringREF << std::endl;
	return (0);
}
