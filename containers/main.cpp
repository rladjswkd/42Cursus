// pair::operator= example
#include "pair.hpp"
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  ft::pair <std::string,int> planet, homeplanet;

  planet = ft::make_pair("Earth",6371);

  homeplanet = planet;

  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';
  return 0;
}