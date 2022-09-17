#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base	*generate(void){
	int	val;

	srand(time(NULL));
	val = rand() % 3;
	if (val == 0)
		return (new A);
	else if (val == 1)
		return (new B);
	else
		return (new C);
}