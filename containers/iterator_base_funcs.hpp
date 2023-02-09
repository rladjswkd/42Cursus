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
		return (ft::distance_impl(first, last, typename ft::iterator_traits<InputIt>::iterator_category()));
	}


	template <typename InputIt, typename Distance>
	inline void	advance_impl(InputIt &it, Distance n, ft::input_iterator_tag)	{
		while (n--)
			++it;
	}


	template <typename BidirectionalIt, typename Distance>
	inline void	advance_impl(BidirectionalIt &it, Distance n, ft::bidirectional_iterator_tag) {
		if (n > 0)
			while (n--)
				++it;
		else
			while (n++)
				--it;
	}


	template <typename RandomAccessIt, typename Distance>
	inline void	advance_impl(RandomAccessIt &it, Distance n, ft::random_access_iterator_tag) {
		it += n;
	}


	template <typename InputIt, typename Distance>
	inline void	advance(InputIt &it, Distance d) {
		typename iterator_traits<InputIt>::difference_type diff = d;
		advance_impl(it, diff, typename ft::iterator_traits<InputIt>::iterator_category());
	}
}
#endif