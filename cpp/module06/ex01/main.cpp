#include <iostream>
#define uintptr_t	unsigned int *

struct Data
{
	int	data1;
	int	data2;
};

uintptr_t serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

int	main(void){
	Data	dataPtr = {12, 23};

	if (deserialize(serialize(&dataPtr)) == &dataPtr){
		std::cout << "Equal!" << std::endl;
		std::cout << deserialize(serialize(&dataPtr))->data1 << std::endl;
		std::cout << deserialize(serialize(&dataPtr))->data2 << std::endl;
	}
	else
		std::cout << "NOT equal!" << std::endl;
	return (0);
}