#ifndef ITERATOR_BASE_FUNCS_HPP
# define ITERATOR_BASE_FUNCS_HPP
# include "iterator_base_types.hpp"

namespace ft {
	template <typename InputIt>
	inline typename iterator_traits<InputIt>::difference_type distance_impl(InputIt first, InputIt last, ft::input_iterator_tag) {
		typename iterator_traits<InputIt>::difference_type	diff = 0;

		while ((first++) != last)
			diff++;
		return (diff);
	}


	template <typename RandomAccessIt>
	inline typename iterator_traits<RandomAccessIt>::difference_type distance_impl(RandomAccessIt first, RandomAccessIt last, ft::random_access_iterator_tag) {
		return (last - first);
	}

	
	template <typename InputIt>
	inline typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
		return ft::distance_impl(first, last, ft::iterator_traits<InputIt>::iterator_category());
	}
}
#endif