#include "../system/system_methods.ipp"
#include UTILITIES
#include VECTOR
#include UTIL1
#include UTIL2
#include UTIL3

// wrap_iter<T>에서 구현체가 공식라이브러리와 T가 포인터냐 아니냐의 차이가 있어서 다르게 나옴
bool iterator_traits_test() {	
	std::vector<string> res;
	std::vector<string> res2;
	g_start1 = g_end1 = timer();

	// res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	// res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	// res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	// res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	// res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	// res.push_back(typeid(std::vector<int>::iterator::reference).name());
	// res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	// res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	// res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	// res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	// res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	// res2.push_back(typeid(_vector<int>::iterator::iterator_category).name());
	// res2.push_back(typeid(_vector<int>::iterator::value_type).name());
	// res2.push_back(typeid(_vector<int>::iterator::difference_type).name());
	// res2.push_back(typeid(_vector<int>::iterator::iterator_type).name());
	// res2.push_back(typeid(_vector<int>::iterator::pointer).name());
	// res2.push_back(typeid(_vector<int>::iterator::reference).name());
	// res2.push_back(typeid(_vector<int>::reverse_iterator::iterator_category).name());
	// res2.push_back(typeid(_vector<int>::reverse_iterator::value_type).name());
	// res2.push_back(typeid(_vector<int>::reverse_iterator::difference_type).name());
	// res2.push_back(typeid(_vector<int>::reverse_iterator::pointer).name());
	// res2.push_back(typeid(_vector<int>::reverse_iterator::reference).name());

	// std::cout << std::endl;
	// std::cout << typeid(std::vector<int>::iterator::iterator_category).name() << std::endl;	//
	// std::cout << typeid(_vector<int>::iterator::iterator_category).name() << std::endl;	//
	// std::cout << typeid(std::vector<int>::iterator::value_type).name() << std::endl;
	// std::cout << typeid(_vector<int>::iterator::value_type).name() << std::endl;
	// std::cout << typeid(std::vector<int>::iterator::difference_type).name() << std::endl;
	// std::cout << typeid(_vector<int>::iterator::difference_type).name() << std::endl;
	// std::cout << typeid(std::vector<int>::iterator::iterator_type).name() << std::endl;	// Pi
	// std::cout << typeid(_vector<int>::iterator::iterator_type).name() << std::endl;	// i
	// std::cout << typeid(std::vector<int>::iterator::pointer).name() << std::endl;
	// std::cout << typeid(_vector<int>::iterator::pointer).name() << std::endl;
	// std::cout << typeid(std::vector<int>::iterator::reference).name() << std::endl;
	// std::cout << typeid(_vector<int>::iterator::reference).name() << std::endl;
	// std::cout << typeid(std::vector<int>::reverse_iterator::iterator_category).name() << std::endl;	//
	// std::cout << typeid(_vector<int>::reverse_iterator::iterator_category).name() << std::endl;	//
	// std::cout << typeid(std::vector<int>::reverse_iterator::value_type).name() << std::endl;
	// std::cout << typeid(_vector<int>::reverse_iterator::value_type).name() << std::endl;
	// std::cout << typeid(std::vector<int>::reverse_iterator::difference_type).name() << std::endl;
	// std::cout << typeid(_vector<int>::reverse_iterator::difference_type).name() << std::endl;
	// std::cout << typeid(std::vector<int>::reverse_iterator::pointer).name() << std::endl;
	// std::cout << typeid(_vector<int>::reverse_iterator::pointer).name() << std::endl;
	// std::cout << typeid(std::vector<int>::reverse_iterator::reference).name() << std::endl;
	// std::cout << typeid(_vector<int>::reverse_iterator::reference).name() << std::endl;

	

	return res == res2;
}

int main() {

	exit(run_bool_unit_test("iterators_traits", iterator_traits_test));
}
