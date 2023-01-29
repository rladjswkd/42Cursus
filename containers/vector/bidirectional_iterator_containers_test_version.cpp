#include "common.hpp"
#include <set>
#include "set.hpp"
#include "tree.cpp"
#include "vector.hpp"
#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::set<TESTED_TYPE> 				st;
	TESTED_NAMESPACE::set<TESTED_TYPE>::iterator	iter;
	for (int i = 1; i < 5; ++i)
		st.insert(i);
		
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(st.begin(), st.end());
	printSize(vct);

	st.clear();
	for (int i = 5; i < 10; ++i)
		st.insert(i);
	vct.assign(st.begin(), st.end());
	printSize(vct);

	vct.insert(vct.end(), st.rbegin(), st.rend());
	printSize(vct);
	return (0);
}
