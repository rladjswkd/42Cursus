/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OFile.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:33 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/14 16:00:14 by gyepark          ###   ########.fr       */
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
	std::size_t	prev = 0;

	if (!s1.empty()){
		while ((index = iFileContent.find(s1, prev)) != std::string::npos){
			iFileContent.erase(index, s1.length());
			iFileContent.insert(index, s2);
			prev = index + s2.length();;
		}
	}
	oFile << iFileContent;
}
