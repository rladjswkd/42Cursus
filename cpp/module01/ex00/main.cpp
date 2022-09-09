#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void){
	Zombie *heap = newZombie("HEAP");
	heap->announce();
	delete (heap);
	randomChump("STACK");
	return (0);
}