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
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		explicit 		stack(const Container& right = Container());
		bool			empty() const;
		void			pop();
		void			push(const Type& val);
		size_type		size() const;
		reference		top();
		const_reference	top() const;
		
		template <class _Type, class _Container>
		friend bool		operator==(const stack<_Type, _Container> &lhs, const stack<_Type, _Container> &rhs);
		template <class _Type, class _Container>
		friend bool		operator<(const stack<_Type, _Container> &lhs, const stack<_Type, _Container> &rhs);
	};
	
	template <typename Type, typename Container>
	inline stack<Type, Container>::stack(const Container& right) : c(right) { }

	template <typename Type, typename Container>
	inline bool	stack<Type, Container>::empty() const {
		return (c.empty());
	}

	template <typename Type, typename Container>
	inline void	stack<Type, Container>::pop() {
		c.pop_back();
	}

	template <typename Type, typename Container>
	inline void	stack<Type, Container>::push(const Type& val) {
		c.push_back(val);
	}

	template <typename Type, typename Container>
	inline typename stack<Type, Container>::size_type	stack<Type, Container>::size() const {
		return (c.size());
	}

	template <typename Type, typename Container>
	inline typename stack<Type, Container>::reference	stack<Type, Container>::top() {
		return (c.back());
	}

	template <typename Type, typename Container>
	inline typename stack<Type, Container>::const_reference	stack<Type, Container>::top() const {
		return (c.back());
	}

	template <typename Type, typename Container>
	inline bool	operator==(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (lhs.c == rhs.c);
	}

	template <typename Type, typename Container>
	inline bool	operator!=(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Type, typename Container>
	inline bool	operator<(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (lhs.c < rhs.c);
	}

	template <typename Type, typename Container>
	inline bool	operator<=(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Type, typename Container>
	inline bool	operator>(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (rhs < lhs);
	}

	template <typename Type, typename Container>
	inline bool	operator>=(const stack<Type, Container> &lhs, const stack<Type, Container> &rhs) {
		return (!(lhs < rhs));
	}
}
#endif