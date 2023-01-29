#include <iostream>
#include "../set.hpp"
#include "../tree.cpp"
#include "../vector.hpp"
#define TESTED_TYPE int

void	print_vector(ft::vector<TESTED_TYPE> v) {
	for (ft::vector<TESTED_TYPE>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int		main(void)
{
	ft::set<TESTED_TYPE> 			st;
	ft::set<TESTED_TYPE>::iterator	iter;
	for (int i = 1; i < 5; ++i)
		st.insert(i);
	ft::vector<TESTED_TYPE> 		v(st.begin(), st.end());
	print_vector(v);
	
	st.clear();
	
	for (int i = 5; i < 10; ++i)
		st.insert(i);
	v.assign(st.begin(), st.end());
	print_vector(v);

	v.insert(v.end(), v.begin(), v.end());
	print_vector(v);
	return (0);
}
