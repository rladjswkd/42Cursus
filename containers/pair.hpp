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
		pair();
		// initialization constructor
		pair(const T1& x, const T2& y);
		// copy constructor
		template <class U1, class U2>
		pair(const pair<U1, U2>& p);

		pair& operator=(const pair& other);
	};

	template <class T1, class T2>
	pair<T1, T2>::pair() : first(), second() { }

	template <class T1, class T2>
	pair<T1, T2>::pair(const T1& x, const T2& y) : first(x), second(y) { }

	template <class T1, class T2>
	template <class U1, class U2>
	pair<T1, T2>::pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }
	
	template <class T1, class T2>
	pair<T1, T2>& pair<T1, T2>::operator=(const pair& other) {
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}

	template <class T1, class T2>
	inline pair<T1, T2> make_pair(T1 t, T2 u) {
		return (pair<T1, T2>(t, u));
	}
}
#endif