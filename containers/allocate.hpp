#ifndef	ALLOCATE_HPP
# define ALLOCATE_HPP

namespace ft {
	template <class ForwardIt, class Allocator>
	void	destroy_range(ForwardIt first, ForwardIt last, Allocator& alloc) {
		for (; first != last; ++first)
			alloc.destroy(alloc.address(*first));
	}

	template <class InputIterator, class ForwardIterator, class Allocator>
	ForwardIterator	uninitialized_copy_alloc(InputIterator first, InputIterator last, ForwardIterator result, Allocator& alloc) {
		ForwardIterator cur = result;

		try {
			for (; first != last; (void)++first, (void)++cur)
				alloc.construct(alloc.address(*cur), *first);
			return cur;
		} catch(...) {
			_destroy_range(result, cur, alloc);
			throw;
		}
	}
}
#endif