#include "Lexer.hpp"
#include <iostream>

int main()
{
    Lexer::Tokens tok = Lexer("123123123").tokenize();
    for (std::vector<std::string>::iterator it = tok.begin(); it != tok.end(); it++)
        std::cout << *it << std::endl;
    return (0);
}