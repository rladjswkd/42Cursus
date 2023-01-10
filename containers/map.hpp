#ifndef MAP_HPP
# define MAP_HPP
# include <functional>
# include <stddef.h>
# include "pair.hpp"
# include "iterator.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map {
	public:
		typedef	Key							key_type;
		typedef T							mapped_type;
		typedef ft::pair<const Key, T>		value_type;
		typedef	std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Compare						key_compare;
		typedef Allocator					allocator_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef Allocator::pointer			pointer;
		typedef Allocator::const_pointer	const_pointer;
		// typedef bidirectional iterator to value_type	iterator;
		// typedef bidirectional iterator to const value_type	const_iterator;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	};
}
#endif