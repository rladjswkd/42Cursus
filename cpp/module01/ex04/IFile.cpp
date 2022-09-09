#include "IFile.hpp"

IFile::~IFile(void){
	iFile.close();
}

bool	IFile::openFile(const char *path){
	iFile.open(path);
	return (iFile.is_open());
}

std::string	IFile::getContent(void){
	std::string	line;

	while (iFile.good() && getline(iFile, line)){
		content.append(line);
		content.append("\n");
	}
	if (content.length() > 0)
		content.resize(content.length() - 1);
	return (content);	
}