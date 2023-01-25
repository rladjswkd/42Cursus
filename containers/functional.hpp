#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP
# include "pair.hpp"

namespace ft {
	template <typename ArgumentType, typename ResultType>
	struct unary_function {
		typedef ArgumentType 	argument_type;   
		typedef ResultType 		result_type;  
	};

	template <typename ArgumentType1, typename ArgumentType2, typename ResultType>
	struct binary_function {
		typedef ArgumentType1   first_argument_type;
		typedef ArgumentType2   second_argument_type;
		typedef ResultType 		result_type;
	};

	template <typename Pair>
	struct use_first : public unary_function<Pair, typename Pair::first_type> {
		typename Pair::first_type	&operator()(Pair& p) const {
			return (p.first);
		}

		const typename Pair::first_type	&operator()(const Pair& p) const {
			return (p.first);
		}	
	};

	template <typename T>
	struct use_self : public unary_function<T, T> {
		T	&operator()(T &t) const {
			return (t);
		}

		const T	&operator()(const T &t) const {
			return t;
		}
	};

	template <typename T>
	struct use_self<const T> : use_self<T> { };
}
#endif