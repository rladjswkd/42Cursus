#include <type_traits>

namespace ft {
	template <class T, T v>
	struct integral_constant {
		static const T				value = v;
		typedef T					value_type;
		typedef integral_constant	type;
		operator value_type() const;
	};

	template <class T, T v>
	integral_constant<T, v>::operator value_type() const {
		return value;
	}

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;


	template <typename T>
	struct remove_const {
		typedef T	type;
	};

	template <typename T>
	struct remove_const<const T> {
		typedef T	type;
	};

	template <typename T>
	struct remove_volatile {
		typedef T	type;
	};

	template <typename T>
	struct remove_volatile<volatile T> {
		typedef T	type;
	};

	template <typename T>
	struct remove_cv {
		typedef typename remove_const<typename remove_volatile<T>::type>::type	type;
	};


	template <typename>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<wchar_t> : public true_type {};

	template <>
	struct is_integral<char16_t> : public true_type {};

	template <>
	struct is_integral<char32_t> : public true_type {};

	template <>
	struct is_integral<short> : public true_type {};

	template <>
	struct is_integral<unsigned short> : public true_type {};

	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<long> : public true_type {};

	template <>
	struct is_integral<unsigned long> : public true_type {};

	template <>
	struct is_integral<long long> : public true_type {};

	template <>
	struct is_integral<unsigned long long> : public true_type {};

	template <>
	struct is_integral<__int128_t> : public true_type {};

	template <>
	struct is_integral<__uint128_t> : public true_type {};
};