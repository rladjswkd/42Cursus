#include "Zombie.hpp"
#define	COUNT	42

Zombie	*zombieHorde(int N, std::string name);

int main(void){
    Zombie	*horde = zombieHorde(COUNT, "HEAP");

	for (int i = 0; i < COUNT; i++)
		horde->announce();
	delete[] (horde);
}