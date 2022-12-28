#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft {
	template <class Type, class Container= ft::vector<Type> >
	class stack {
	protected:
		Container	c;
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;			//	c++98? c++11?
		typedef typename Container::const_reference	const_reference;	//	c++98? c++11?

		explicit stack(const Container& right = Container());
		bool			empty() const;
		void			pop();
		void			push(const Type& val);
		size_type		size() const;
		reference		top();
		const_reference	top() const;
	};
	
	template <class Type, class Container>
	inline stack<Type, Container>::stack(const Container& right) : c(right) { }

	template <class Type, class Container>
	inline bool	stack<Type, Container>::empty() const {
		return (c.empty());
	}

	template <class Type, class Container>
	inline void	stack<Type, Container>::pop() {
		c.pop_back();
	}

	template <class Type, class Container>
	inline void	stack<Type, Container>::push(const Type& val) {
		c.push_back(val);
	}

	template <class Type, class Container>
	inline typename stack<Type, Container>::size_type	stack<Type, Container>::size() const {
		return (c.size());
	}

	template <class Type, class Container>
	inline typename stack<Type, Container>::reference	stack<Type, Container>::top() {
		return (c.back());
	}

	template <class Type, class Container>
	inline typename stack<Type, Container>::const_reference	stack<Type, Container>::top() const {
		return (c.back());
	}

	template<typename Type, typename Container>
	inline bool	operator==(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (lhs.c == rhs.c);
	}

	template<typename Type, typename Container>
	inline bool	operator!=(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (!(lhs == rhs));
	}

	template<typename Type, typename Container>
	inline bool	operator<(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (lhs.c < rhs.c);
	}

	template<typename Type, typename Container>
	inline bool	operator<=(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (!(rhs < lhs));
	}

	template<typename Type, typename Container>
	inline bool	operator>(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (rhs < lhs);
	}

	template<typename Type, typename Container>
	inline bool	operator>=(const stack<Type, Container>& lhs, const stack<Type, Container>& rhs) {
		return (!(lhs < rhs));
	}
}
#endif