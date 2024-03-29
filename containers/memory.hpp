#ifndef	MEMORY_HPP
# define MEMORY_HPP

namespace ft {
	template <class ForwardIt, class Allocator>
	void	destroy_range(ForwardIt first, ForwardIt last, Allocator& alloc) {
		for (; first != last; ++first)
			alloc.destroy(alloc.address(*first));	// this is just (*first).~value_type(); (value_type is typedef-ed through ft::iterator_traits<ForwardIt>::value_type)
	}

	template <class InputIterator, class ForwardIterator, class Allocator>
	ForwardIterator	uninitialized_copy_alloc(InputIterator first, InputIterator last, ForwardIterator result, Allocator& alloc) {
		ForwardIterator	cur = result;

		try {
			for (; first != last; (void)++first, (void)++cur)
				alloc.construct(alloc.address(*cur), *first);
			return (cur);
		} catch (...) {
			destroy_range(result, cur, alloc);
			throw;
		}
	}

	template <typename ForwardIterator, typename Size, typename T, typename Allocator>
	ForwardIterator	uninitialized_fill_n_alloc(ForwardIterator first, Size n, const T& value, Allocator& alloc) {
		ForwardIterator	cur = first;
		
		try{
			for (; n > 0; (void)--n, (void)++cur)
				alloc.construct(alloc.address(*cur), value);
			return (cur);
		} catch (...) {
			destroy_range(first, cur, alloc);
			throw;
		}
	}
}
#endif