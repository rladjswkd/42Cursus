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