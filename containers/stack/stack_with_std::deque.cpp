#include <iostream>
#include <deque>
#include "stack.hpp"

int	main() {
	ft::stack<int, std::deque<int> >	st;
	st.push(1);
	st.push(2);
	std::cout << st.size() << std::endl;	
	st.pop();
	std::cout << st.top() << std::endl;
	return (0);
}