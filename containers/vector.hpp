#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstddef> // std::size_t, std::ptrdiff_t
# include "iterator.hpp"

# include <vector> // remove

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
	public:
	// member types - cppreference.com
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T*										iterator;	//나중에 이터레이터 구현하기
		typedef const T*								const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	};
}
#endif