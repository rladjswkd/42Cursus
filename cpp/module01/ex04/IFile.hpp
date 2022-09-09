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
