#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
	// member types
		typedef T1	first_type;
		typedef T2	second_type;

	// member variables
		T1	first;
		T2	second;

	// member functions
		// default constructor	
		pair() : first(), second() { }
		// initialization constructor
		pair(const T1& x, const T2& y) : first(x), second(y) { }
		// copy constructor
		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }
	};

	template <class T1, class T2>
	inline pair<T1, T2> make_pair(T1 t, T2 u) {
		return (pair<T1, T2>(t, u));
	}
}
#endif