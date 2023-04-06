#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream is;
    std::string str;

    is.open("./delimitertestfile");
    
    for (; std::getline(is, str, ';'); )
        std::cout << str << std::endl;

    return (0);
}