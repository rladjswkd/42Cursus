/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:41 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:43 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IFile.hpp"
#include "OFile.hpp"

int	main(int argc, char **argv){
	IFile		iFile;
	OFile		oFile;
	
	if (argc != 4)
		return (0);
	if (!iFile.openFile(argv[1])){
		std::cout << "File " << argv[1] << " is invalid." << std::endl;
		return (0);
	}
	if (!oFile.openFile(std::string(argv[1]).append(".replace").c_str())){
		std::cout << "File " << std::string(argv[1]).append(".replace") << " is invalid." << std::endl;
		return (0);
	}
	oFile.convertAndWriteFile(iFile.getContent(), std::string(argv[2]), std::string(argv[3]));
	return (0);
}
