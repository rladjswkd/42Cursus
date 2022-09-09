/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IFile.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	IFILE_HPP
#define IFILE_HPP
#include <iostream>
#include <fstream>
#include <string>

class IFile
{
private:
	std::ifstream	iFile;
	std::string		content;

public:
					~IFile(void);
	bool			openFile(const char *);
	std::string		getContent(void);
};
#endif
