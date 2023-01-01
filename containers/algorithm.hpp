#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP
# include <cstring>			//memcmp, memset
// # include <algorithm>		//min	Todo: remove
# include <stdlib.h>
# include "type_traits.hpp"
# include "iterator.hpp"

namespace ft {
	template <bool B>
	struct _equal {
		template <typename InputIt1, typename InputIt2>
		static bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
			for (; first1 != last1; (void)++first1, (void)++first2)
				if (*first1 != *first2)
					return (false);
			return (true);
		}
	};


	template <>
	struct _equal<true> {
		template <typename InputIt1, typename InputIt2>
		static bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
			if (const size_t len = (last1 - first1))
				return (!std::memcmp(first1, first2, (last1 - first1))); // on mac, ubuntu, ... this way is way faster than for loop 
			return (true);
		}
	};
	

	template <typename InputIt1, typename InputIt2>
	inline bool equal_auxiliary(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		typedef typename iterator_traits<InputIt1>::value_type	v1;
		typedef typename iterator_traits<InputIt2>::value_type	v2;
		const bool simple = ((is_integral<v1>::value || is_pointer<v1>::value)
							&& is_pointer<InputIt1>::value
							&& is_pointer<InputIt2>::value
							&& are_same<v1, v2>::value);
		return (_equal<simple>::equal(first1, last1, first2));
	}


	template <typename InputIt1, typename InputIt2>
	inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		return (equal_auxiliary<InputIt1, InputIt2>(first1, last1, first2));
	}


	template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
	inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
			for (; first1 != last1; (void)++first1, (void)++first2)
				if (!p(*first1, *first2))
					return (false);
			return (true);
	}
	

	template <typename InputIt1, typename InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}
	

	template <typename InputIt1, typename InputIt2, typename Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}	


	bool lexicographical_compare(char *first1, char *last1, char *first2, char *last2);


	bool lexicographical_compare(const char *first1, const char *last1, const char *first2, const char *last2);


	bool lexicographical_compare(signed char *first1, signed char *last1, signed char *first2, signed char *last2);


	bool lexicographical_compare(const signed char *first1, const signed char *last1, const signed char *first2, const signed char *last2);


	bool lexicographical_compare(unsigned char *first1, unsigned char *last1, unsigned char *first2, unsigned char *last2);


	bool lexicographical_compare(const unsigned char *first1, const unsigned char *last1, const unsigned char *first2, const unsigned char *last2);


	template <typename T>
	inline const T	&min(const T &a, const T &b) {
		if (b < a)
			return (b);
		return (a);
	}


	template <typename T>
	inline const T	&max(const T &a, const T &b)
	{
		if (a < b)
			return (b);
		return (a);
	}

	// wrap random_access_iterator around other and returns it.	Todo: have to decide to(if not used) or not to remove this.
	template <typename RandomAccessIter, typename Base>
	inline RandomAccessIter
	wrap_random_access_around(RandomAccessIter wrapper, Base other) {
		return (wrapper + (other - ft::unwrap_iterator(wrapper)));
	}

	// defensive programming?	Todo: have to decide to(if not used) or not to remove this.
	template <typename RandomAccessIter>
	inline RandomAccessIter
	wrap_random_access_around(const RandomAccessIter&, RandomAccessIter res) {
		return (res);
	}


	template <typename InputIt, typename OutputIt, typename Category>
	inline OutputIt copy_impl(InputIt first, InputIt last, OutputIt result, ft::input_iterator_tag) {
		for (; first != last; (void)++result, (void)++first)
			*result = *first;
		return (result);
	}


	template <typename InputIt, typename OutputIt>
	inline OutputIt	copy_impl(InputIt first, InputIt last, OutputIt result, ft::random_access_iterator_tag) {
		for(typename iterator_traits<InputIt>::difference_type d = last - first; d > 0; --d) {
			*result = *first;
			++first;
			++result;
		}
		return (result);
	}


	template <typename InputIt, typename OutputIt>
	inline OutputIt	copy_helper(InputIt first, InputIt last, OutputIt result) {
		return (copy_impl(first, last, result, typename ft::iterator_traits<InputIt>::iterator_category()));
	}	


	template <typename InputIt, typename OutputIt>
	inline OutputIt	copy(InputIt first, InputIt last, OutputIt result) {
		return (wrap_random_access_around(result, copy_helper(
			ft::unwrap_iterator(first),
			ft::unwrap_iterator(last),
			ft::unwrap_iterator(result))));
	}


	template <typename ForwardIt, typename T>
	inline typename ft::enable_if<!is_scalar<T>::value, void>::type	fill_impl(ForwardIt first, ForwardIt last, const T &value)
	{
		for (; first != last; ++first)
			*first = value;
	}

	template <typename ForwardIt, typename T>
	inline typename ft::enable_if<is_scalar<T>::value, void>::type	fill_impl(ForwardIt first, ForwardIt last, const T &value)
	{
		const T	temp = value;

		for (; first != last; ++first)
			*first = temp;
	}

	template <typename T>
	inline typename ft::enable_if<is_byte<T>::value, void>::type	fill_impl(T *first, T *last, const T &value)
	{
		const T	temp = value;
		if (const size_t len = last - first)
			std::memset(first, static_cast<unsigned char>(temp), len);
	}

	template <typename ForwardIt, typename T>
	inline void	fill(ForwardIt first, ForwardIt last, const T &value) {
		fill_impl(ft::unwrap_iterator(first), ft::unwrap_iterator(last), value);
	}


	template<typename OutputIt, typename Size, typename T>
	inline typename ft::enable_if<!is_scalar<T>::value, OutputIt>::type	fill_n_impl(OutputIt first, Size n, const T &value) {
		for (size_t niter = n; niter > 0; (void)--niter, (void) ++first)
			*first = value;
		return (first);
	}

	template<typename OutputIt, typename Size, typename T>
	inline typename ft::enable_if<is_scalar<T>::value, OutputIt>::type	fill_n_impl(OutputIt first, Size n, const T &value) {
		const T tmp = value;
		for (size_t niter = n; niter > 0; (void)--niter, (void) ++first)
			*first = tmp;
		return (first);
	}

	template<typename Size, typename T>
	inline typename ft::enable_if<is_byte<T>::value, T*>::type	fill_n_impl(T* first, Size n, const T &c) {
		fill_impl(first, first + n, c);
		return (first + n);
	}

	template <typename OutputIt, typename Size, typename T>
	inline OutputIt	fill_n(OutputIt first, Size n, const T &value) {
		return (ft::wrap_random_access_around(first, fill_n_impl(ft::unwrap_iterator(first), n, value)));
	}


	template <typename BidirectionalIt1, typename BidirectionalIt2>
	inline BidirectionalIt2	copy_backward_impl(BidirectionalIt1 first, BidirectionalIt1 last, BidirectionalIt2 result, ft::input_iterator_tag) {
		while (first != last)
			*--result = *--last;
		return (result);
	}

	template <typename BidirectionalIt1, typename BidirectionalIt2>
	inline BidirectionalIt2	copy_backward_impl(BidirectionalIt1 first, BidirectionalIt1 last, BidirectionalIt2 result, ft::random_access_iterator_tag) {
		typename iterator_traits<_BI1>::difference_type	diff;
		for (diff = last - first; diff > 0; --diff)
			*--result = *--last;
		return (result);
	}

	template <typename BidirectionalIt1, typename BidirectionalIt2>
	inline BidirectionalIt2	copy_backward_helper(BidirectionalIt1 first, BidirectionalIt1 last, BidirectionalIt2 result) {
		return (copy_backward_impl(first, last, result, typename ft::iterator_traits<BidirectionalIt1>::iterator_category()));
	}

	template <typename BidirectionalIt1, typename BidirectionalIt2>
	inline BidirectionalIt2	copy_backward(BidirectionalIt1 first, BidirectionalIt1 last, BidirectionalIt2 result) {
	return (ft::wrap_random_access_around(result, ft::copy_backward_helper(
		ft::__niter_base(first),
		ft::__niter_base(last),
		ft::__niter_base(result))));
	}
}
#endif