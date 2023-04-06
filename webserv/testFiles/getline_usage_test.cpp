#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream is;
    std::string str;

    is.open("./testfile");
    
    for (; std::getline(is, str); )
        std::cout << str << is.eof() << is.fail() << is.bad() << is.good() << std::endl;
    std::cout << str << is.eof() << is.fail() << is.bad() << is.good() << std::endl;

    return (0);
}