/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:44:55 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/08 01:44:59 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	print_uppercase(std::string input)
{
	std::size_t	i = 0;
	std::size_t	len = input.length();

	while (i < len)
		std::cout << (unsigned char)(std::toupper(input.at(i++)));
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while (++i < argc)
			print_uppercase(std::string(argv[i]));
	std::cout << std::endl;
	return (0);
}
