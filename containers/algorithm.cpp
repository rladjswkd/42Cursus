#include "algorithm.hpp"

bool ft::lexicographical_compare(char *first1, char *last1, char *first2, char *last2) {
	const size_t	len1 = last1 - first1;
	const size_t	len2 = last2 - first2;
	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

	if (result < 0)
		return (true);
	if (result > 0)
		return (false);
	return (len1 < len2);
}
// it is possible to call a function with const parameters using non-const parameters (pointer or reference)

// bool ft::lexicographical_compare(const char *first1, const char *last1, const char *first2, const char *last2) {
// 	const size_t	len1 = last1 - first1;
// 	const size_t	len2 = last2 - first2;
// 	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

// 	if (result < 0)
// 		return (true);
// 	if (result > 0)
// 		return (false);
// 	return (len1 < len2);
// }

bool ft::lexicographical_compare(signed char *first1, signed char *last1, signed char *first2, signed char *last2) {
	const size_t	len1 = last1 - first1;
	const size_t	len2 = last2 - first2;
	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

	if (result < 0)
		return (true);
	if (result > 0)
		return (false);
	return (len1 < len2);
}

// bool ft::lexicographical_compare(const signed char *first1, const signed char *last1, const signed char *first2, const signed char *last2) {
// 	const size_t	len1 = last1 - first1;
// 	const size_t	len2 = last2 - first2;
// 	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

// 	if (result < 0)
// 		return (true);
// 	if (result > 0)
// 		return (false);
// 	return (len1 < len2);
// }

bool ft::lexicographical_compare(unsigned char *first1, unsigned char *last1, unsigned char *first2, unsigned char *last2) {
	const size_t	len1 = last1 - first1;
	const size_t	len2 = last2 - first2;
	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

	if (result < 0)
		return (true);
	if (result > 0)
		return (false);
	return (len1 < len2);
}

// bool ft::lexicographical_compare(const unsigned char *first1, const unsigned char *last1, const unsigned char *first2, const unsigned char *last2) {
// 	const size_t	len1 = last1 - first1;
// 	const size_t	len2 = last2 - first2;
// 	const int		result = std::memcmp(first1, first2, ft::min(len1, len2));

// 	if (result < 0)
// 		return (true);
// 	if (result > 0)
// 		return (false);
// 	return (len1 < len2);
// }