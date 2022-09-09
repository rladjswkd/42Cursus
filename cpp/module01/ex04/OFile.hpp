/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OFile.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:35 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:36 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFILE_HPP
#define OFILE_HPP
#include <iostream>
#include <fstream>
#include <string>

class OFile
{
private:
	std::ofstream	oFile;
public:
					~OFile(void);
	bool			openFile(const char *);
	void			convertAndWriteFile(std::string, std::string, std::string);
};
#endif
