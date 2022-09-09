/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OFile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:33 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:34 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OFile.hpp"

OFile::~OFile(void){
	oFile.close();
}

bool	OFile::openFile(const char *path){
	oFile.open(path);
	return (oFile.is_open());
}

void	OFile::convertAndWriteFile(std::string iFileContent, std::string s1, std::string s2){
	std::size_t	index;

	while ((index = iFileContent.find(s1)) != std::string::npos){
		iFileContent.insert(index, s2);
		iFileContent.erase(index + s2.length(), s1.length());
	}
	oFile << iFileContent;
}
