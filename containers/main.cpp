#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include "lexicographical_compare.hpp"
int main()
{
    std::vector<char> v1{'a', 'b', 'c', 'd'};
    std::vector<char> v2{'a', 'b', 'c', 'd'};
 
    std::mt19937 g{std::random_device{}()};
    while (!ft::lexicographical_compare(v1.begin(), v1.end(),
                                         v2.begin(), v2.end()))
    {
        for (auto c : v1)
            std::cout << c << ' ';
        std::cout << ">= ";
 
        for (auto c : v2)
            std::cout << c << ' ';
        std::cout << '\n';
 
        std::shuffle(v1.begin(), v1.end(), g);
        std::shuffle(v2.begin(), v2.end(), g);
    }
 
    for (auto c : v1)
        std::cout << c << ' ';
    std::cout << "<  ";
 
    for (auto c : v2)
        std::cout << c << ' ';
    std::cout << '\n';
}