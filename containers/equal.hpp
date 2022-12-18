#ifndef EQUAL_HPP
# define EQUAL_HPP
# include "is_integral.hpp"
# include "iterator.hpp"
# include <cstring>			//memcmp

namespace ft {
	template <class T>
	struct is_pointer {
		enum {value = 0};
	};

	template <class T>
	struct is_pointer<T*> {
		enum {value = 1};
	};

	template <class, class>
	struct are_same {
		enum {value = 0};
	};

	template <class T>
	struct are_same<T, T> {
		enum {value = 1};
	};

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
		typedef typename iterator_traits<InputIt1>::value_type v1;
		typedef typename iterator_traits<InputIt2>::value_type v2;
		const bool simple = (
			(is_integral<v1>::value || is_pointer<v1>::value)
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
}
#endif