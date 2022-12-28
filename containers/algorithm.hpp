#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP
# include <cstring>			//memcmp
# include <algorithm>		//min	Todo
# include <stdlib.h>
# include "type_traits.hpp"

namespace ft {
	template <bool B>
	struct _equal {
		template <class InputIt1, class InputIt2>
		static bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
			for (; first1 != last1; (void)++first1, (void)++first2)
				if (*first1 != *first2)
					return (false);
			return (true);
		}
	};

	template <>
	struct _equal<true> {
		template <class InputIt1, class InputIt2>
		static bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
			if (const size_t len = (last1 - first1))
				return (!std::memcmp(first1, first2, (last1 - first1))); // on mac, ubuntu, ... this way is way faster than for loop 
			return (true);
		}
	};
	
	template <class InputIt1, class InputIt2>
	inline bool equal_auxiliary(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		typedef iterator_traits<InputIt1>::value_type	v1;
		typedef iterator_traits<InputIt2>::value_type	v2;
		const bool simple = ((is_integral<v1>::value || is_pointer<v1>::value)
							&& is_pointer<InputIt1>::value
							&& is_pointer<InputIt2>::value
							&& are_same<v1, v2>::value);
		return (_equal<simple>::equal(first1, last1, first2));
	}

	template <class InputIt1, class InputIt2>
	inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		return (equal_auxiliary<InputIt1, InputIt2>(first1, last1, first2));
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	inline bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
			for (; first1 != last1; (void)++first1, (void)++first2)
				if (!p(*first1, *first2))
					return (false);
			return (true);
	}

	bool lexicographical_compare(char *first1, char *last1, char *first2, char *last2);
	bool lexicographical_compare(const char *first1, const char *last1, const char *first2, const char *last2);
	bool lexicographical_compare(signed char *first1, signed char *last1, signed char *first2, signed char *last2);
	bool lexicographical_compare(const signed char *first1, const signed char *last1, const signed char *first2, const signed char *last2);
	bool lexicographical_compare(unsigned char *first1, unsigned char *last1, unsigned char *first2, unsigned char *last2);
	bool lexicographical_compare(const unsigned char *first1, const unsigned char *last1, const unsigned char *first2, const unsigned char *last2);
	
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}	
}
#endif