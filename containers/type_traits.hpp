#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
	template <typename T>
	struct is_pointer {
		enum {value = 0};
	};

	template <typename T>
	struct is_pointer<T*> {
		enum {value = 1};
	};


	template <typename, typename>
	struct are_same {
		enum {value = 0};
	};

	template <typename T>
	struct are_same<T, T> {
		enum {value = 1};
	};


	template <typename T, T v>
	struct integral_constant {
		static const T				value = v;
		typedef T					value_type;
		typedef integral_constant	type;
		operator value_type() const;
	};

	template <typename T, T v>
	integral_constant<T, v>::operator value_type() const {
		return (value);
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

	// template <>
	// struct is_integral<char16_t> : public true_type {};

	// template <>
	// struct is_integral<char32_t> : public true_type {};

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


	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};


	template <typename T>
	struct is_floating {
		enum {value = 0};
	};

	template <>
	struct is_floating<float> {
		enum {value = 1};
	};

	template <>
	struct is_floating<double> {
		enum {value = 1};
	};

	template <>
	struct is_floating<long double> {
		enum {value = 1};
	};


	template <typename First, typename Second>
	struct traitor {
		enum {value = bool(First::value) || bool(Second::value)};	//	using anonymous enum as template argument is invalid before c++11. casting to bool is required here.
	};

	template <typename T>
	struct is_arithmetic : public traitor< is_integral<T>, is_floating<T> > { };

	template <typename T>
	struct is_scalar : public traitor< is_arithmetic<T>, is_pointer<T> > { };

	template <typename T>
	struct is_byte {
		enum {value = 0};
	};

	template <>
	struct is_byte<char> {
		enum {value = 1};
	};

	template <>
	struct is_byte<signed char> {
		enum {value = 1};
	};

	template <>
	struct is_byte<unsigned char> {
		enum {value = 1};
	};
}
#endif