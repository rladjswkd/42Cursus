// pair::pair example
#include "pair.hpp"
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
    ft::pair<std::string, double> product1;                     // default constructor
    ft::pair<std::string, double> product2("tomatoes",2.30);   // value init
    ft::pair<std::string, double> product3(product2);          // copy constructor
    ft::pair<std::string, double> product4(ft::make_pair<std::string, double>(std::string("apple"), 4.42));

    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    std::cout << "The price of " << product4.first << " is $" << product4.second << '\n';
    
    return 0;
}