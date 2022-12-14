#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP
# include <stdlib.h>
# include <algorithm>

namespace ft {
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

	bool lexicographical_compare(char *first1, char *last1, char *first2, char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
	}

	bool lexicographical_compare(const char *first1, const char *last1, const char *first2, const char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
	}
	
	bool lexicographical_compare(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
	}
	
	bool lexicographical_compare(const signed char *first1, const signed char *last1, const signed char *first2, const signed char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
	}
	
	bool lexicographical_compare(unsigned char *first1, unsigned char *last1, unsigned char *first2, unsigned char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
	}
	
	bool lexicographical_compare(const unsigned char *first1, const unsigned char *last1, const unsigned char *first2, const unsigned char *last2) {
		const size_t	len1 = last1 - first1;
		const size_t	len2 = last2 - first2;
		const int		result = std::memcmp(first1, first2, std::min(len1, len2));

		if (result < 0)
			return (true);
		if (result > 0)
			return (false);
		return (len1 < len2);
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
