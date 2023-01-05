#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <stddef.h>	//ptrdiff_t
# include "type_traits.hpp"
# include "iterator_base_types.hpp"

namespace ft {
	// template <class T>
	// class InputIterator {
	// protected:
	// 	T	current;
	// public:
	// 	typedef T															iterator_type;
	// 	typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	// 	typedef typename iterator_traits<iterator_type>::value_type			value_type;
	// 	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
	// 	typedef typename iterator_traits<iterator_type>::pointer			pointer;
	// 	typedef typename iterator_traits<iterator_type>::reference			reference;	

	// 	InputIterator();
	// 	InputIterator(const InputIterator<T>& other);
	// 	~InputIterator();

	// 	iterator_type		base() const;
	// 	InputIterator<T>&	operator=(const InputIterator<T>& other);
	// 	reference			operator*() const;
	// 	pointer				operator->() const;
	// 	InputIterator<T>	operator++();
	// 	InputIterator<T>	operator++(int);
	// };

	// template <class T>
	// InputIterator<T>::InputIterator() : current(T()) {}

	// template <class T>
	// InputIterator<T>::~InputIterator() {}

	// template <class T>
	// InputIterator<T>::InputIterator(const InputIterator<T>& other) : current(other.current) {}

	// template <class T>
	// InputIterator<T>&	InputIterator<T>::operator=(const InputIterator<T>& other) {
	// 	if (this != &other)
	// 		this->current = other.current;
	// 	return (*this);
	// }

	// template <class T>
	// typename InputIterator<T>::iterator_type	InputIterator<T>::base() const {
	// 	return (current);
	// }

	// template <class T1, class T2>
	// bool	operator==(const InputIterator<T1>& lhs, const InputIterator<T2>& rhs) {
	// 	return (lhs.base() == rhs.base());
	// }

	// template <class T1, class T2>
	// bool	operator!=(const InputIterator<T1>& lhs, const InputIterator<T2>& rhs) {
	// 	return (!operator==(lhs, rhs));
	// }

	// template <class T>
	// typename InputIterator<T>::reference	InputIterator<T>::operator*() const {
	// 	return (*current);
	// }

	// template <class T>
	// typename InputIterator<T>::pointer	InputIterator<T>::operator->() const {
	// 	return (&(*current));
	// }

	// template <class T>
	// InputIterator<T>	InputIterator<T>::operator++() {
	// 	++current;
	// 	return (*this);
	// }

	// template <class T>
	// InputIterator<T>	InputIterator<T>::operator++(int) {
	// 	InputIterator<T>	temp(*this);

	// 	++current;
	// 	return (temp);
	// }

	template <typename Iter>
	class reverse_iterator {
	protected:
		Iter	current;
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

		reverse_iterator();
		explicit reverse_iterator(iterator_type x);
		template <typename U> reverse_iterator(const reverse_iterator<U>& other);
		template <typename U> reverse_iterator &operator=(const reverse_iterator<U>& other);	// not standard. it is implemented just for compatibility between const and non-const.
		iterator_type		base() const;
		reference			operator*() const;
		pointer				operator->() const;
		reference			operator[](difference_type n) const;
		reverse_iterator&	operator++();
		reverse_iterator&	operator--();
		reverse_iterator	operator++(int);
		reverse_iterator	operator--(int);
		reverse_iterator	operator+(difference_type n) const;
		reverse_iterator	operator-(difference_type n) const;
		reverse_iterator&	operator+=(difference_type n);
		reverse_iterator&	operator-=(difference_type n);
	};

// Todo: Container template parameter 재고하기
	template <typename Iter, typename Container>
	class random_access_iterator {
	protected:
		Iter	current;
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

		random_access_iterator();
		template <typename U> // copy assignable
		random_access_iterator(const random_access_iterator<U, typename ft::enable_if<(ft::are_same<U, typename Container::pointer>::value), Container>::type> &other);
		explicit random_access_iterator(const Iter &it);
		// random_access_iterator<Iter, Container>	&operator=(const random_access_iterator<Iter, typename ft::enable_if<(ft::are_same<Iter, typename Container::pointer>::value), Container>::type> &other);
		~random_access_iterator();
		iterator_type			base() const;
		reference				operator*() const;
		pointer					operator->() const;
		reference				operator[](difference_type n) const;
		random_access_iterator&	operator++();
		random_access_iterator&	operator--();
		random_access_iterator	operator++(int);
		random_access_iterator	operator--(int);
		random_access_iterator	operator+(difference_type n) const;
		random_access_iterator	operator-(difference_type n) const;
		random_access_iterator&	operator+=(difference_type n);
		random_access_iterator&	operator-=(difference_type n);
	};

///////////////////////////////////////////////////////////////////////
// reverse_iterator
///////////////////////////////////////////////////////////////////////

	template <typename Iter>
	inline reverse_iterator<Iter>::reverse_iterator() : current() { }


	template <typename Iter>
	inline reverse_iterator<Iter>::reverse_iterator(iterator_type x) : current(x) { }
	

	template <typename Iter>
	template <typename U>
	inline reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U> &other) : current(other.current) { }


	template <typename Iter>
	template <typename U>
	inline reverse_iterator<Iter> &reverse_iterator<Iter>::operator=(const reverse_iterator<U>& other) {
		this->current = other.current;
		return (*this);
	}


	template <typename Iter>
	inline Iter	reverse_iterator<Iter>::base() const {
		return (current);
	}


	template <typename Iter>
	inline typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator*() const {
		Iter	temp = current;

		return (*(--temp));
	}


	template <typename Iter>
	inline typename reverse_iterator<Iter>::pointer	reverse_iterator<Iter>::operator->() const {
		return (&(operator*()));
	}


	template <typename Iter>
	inline typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator[](reverse_iterator<Iter>::difference_type n) const {
		return (current[-n - 1]);
	}


	template <typename Iter>
	inline reverse_iterator<Iter>&	reverse_iterator<Iter>::operator++() {
		--current;
		return (*this);
	}


	template <typename Iter>
	inline reverse_iterator<Iter>&	reverse_iterator<Iter>::operator--() {
		++current;
		return (*this);
	}


	template <typename Iter>
	inline reverse_iterator<Iter>	reverse_iterator<Iter>::operator++(int) {
		reverse_iterator temp = *this;

		--current;
		return (temp);	
	}


	template <typename Iter>
	inline reverse_iterator<Iter>	reverse_iterator<Iter>::operator--(int) {
		reverse_iterator temp = *this;

		++current;
		return (temp);
	}


	template <typename Iter>
	inline reverse_iterator<Iter>	reverse_iterator<Iter>::operator+(difference_type n) const {
		return (reverse_iterator(current - n));
	}


	template <typename Iter>
	inline reverse_iterator<Iter>	reverse_iterator<Iter>::operator-(difference_type n) const {
		return (reverse_iterator(current + n));
	}
	

	template <typename Iter>
	inline reverse_iterator<Iter>&	reverse_iterator<Iter>::operator+=(difference_type n) {
		current -= n;
		return (*this);
	}
	

	template <typename Iter>
	inline reverse_iterator<Iter>&	reverse_iterator<Iter>::operator-=(difference_type n) {
		current += n;
		return (*this);
	}


	template <typename Iter1, typename Iter2>
	inline bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() == rhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() != rhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() < rhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() <= rhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() > rhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() >= rhs.base());
	}


	template <typename Iter>
	inline reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it) {
		return (reverse_iterator<Iter>(it.base() - n));
	}


	template <typename Iter>
	inline typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
		return (rhs.base() - lhs.base());
	}


	template <typename Iter1, typename Iter2>
	inline typename reverse_iterator<Iter1>::difference_type	operator-(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {
		return (rhs.base() - lhs.base());
	}


///////////////////////////////////////////////////////////////////////
// random_access_iterator
///////////////////////////////////////////////////////////////////////

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container>::random_access_iterator() : current() { }


	template <typename Iter, typename Container>
	template <typename U>
	inline random_access_iterator<Iter, Container>::random_access_iterator(const random_access_iterator<U, typename ft::enable_if<(ft::are_same<U, typename Container::pointer>::value), Container>::type> &other)
	: current(other.base()) { }


	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container>::random_access_iterator(const Iter &it) : current(it) { }


	// template <typename Iter, typename Container>
	// inline random_access_iterator<Iter, Container> &random_access_iterator<Iter, Container>::operator=(const random_access_iterator<Iter, typename ft::enable_if<(ft::are_same<Iter, typename Container::pointer>::value), Container>::type> &other) {
	// 	this->current = other.current;
	// 	return (*this);
	// }
	

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container>::~random_access_iterator() { }
	

	template <typename Iter, typename Container>
	inline typename random_access_iterator<Iter, Container>::iterator_type random_access_iterator<Iter, Container>::base() const {
		return (this->current);
	}
	

	template <typename Iter, typename Container>
	inline typename random_access_iterator<Iter, Container>::reference random_access_iterator<Iter, Container>::operator*() const	{
		return (*current);
	}
	

	template <typename Iter, typename Container>
	inline typename random_access_iterator<Iter, Container>::pointer random_access_iterator<Iter, Container>::operator->() const {
		return (&(*current));
	}
	

	template <typename Iter, typename Container>
	inline typename random_access_iterator<Iter, Container>::reference random_access_iterator<Iter, Container>::operator[](difference_type n) const {
		return (current[n]);
	}


	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> &random_access_iterator<Iter, Container>::operator++() {
		++current;
		return (*this);
	}


	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> &random_access_iterator<Iter, Container>::operator--() {
		--current;
		return (*this);
	}
	

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> random_access_iterator<Iter, Container>::operator++(int)	{
		return (random_access_iterator<Iter, Container>(current++));
	}
	

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> random_access_iterator<Iter, Container>::operator--(int) {
		return (random_access_iterator<Iter, Container>(current--));
	}
	

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> random_access_iterator<Iter, Container>::operator+(difference_type n) const {
		return (random_access_iterator<Iter, Container>(current + n));
	}


	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> random_access_iterator<Iter, Container>::operator-(difference_type n) const {
		return (random_access_iterator<Iter, Container>(current - n));
	}
	

	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> &random_access_iterator<Iter, Container>::operator+=(difference_type n) {
		current += n;
		return (*this);
	}


	template <typename Iter, typename Container>
	inline random_access_iterator<Iter, Container> &random_access_iterator<Iter, Container>::operator-=(difference_type n) {
		current -= n;
		return (*this);
	}


	template <typename Iter, typename Container>
	bool	operator==(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() == rhs.base());
	}

	// for example, Iter1 is int* and Iter2 is const(or volatile) int*
	template <typename Iter1, typename Iter2, typename Container>
	bool	operator==(const random_access_iterator<Iter1, Container> &lhs, const random_access_iterator<Iter2, Container> &rhs) {
		return (lhs.base() == rhs.base());
	}


	template <typename Iter, typename Container>
	bool	operator!=(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() != rhs.base());
	}
	

	template <typename Iter, typename Container>
	bool	operator>(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() > rhs.base());
	}
	

	template <typename Iter, typename Container>
	bool	operator>=(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() >= rhs.base());
	}
	

	template <typename Iter, typename Container>
	bool	operator<(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() < rhs.base());
	}
	

	template <typename Iter, typename Container>
	bool	operator<=(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() <= rhs.base());
	}
	

	template <typename Iter, typename Container>
	random_access_iterator<Iter, Container>	operator+(typename random_access_iterator<Iter, Container>::difference_type n, const random_access_iterator<Iter, Container>& it) {
		return (random_access_iterator<Iter, Container>(it.base() + n));
	}
	

	template <typename Iter, typename Container>
	inline typename random_access_iterator<Iter, Container>::difference_type	operator-(const random_access_iterator<Iter, Container> &lhs, const random_access_iterator<Iter, Container> &rhs) {
		return (lhs.base() - rhs.base());
	}


	template <typename Iter1, typename Iter2, typename Container>
	inline typename random_access_iterator<Iter1, Container>::difference_type	operator-(const random_access_iterator<Iter1, Container> &lhs, const random_access_iterator<Iter2, Container> &rhs) {
		return (lhs.base() - rhs.base());
	}

	
///////////////////////////////////////////////////////////////////////
// other functions
///////////////////////////////////////////////////////////////////////

	template <typename Iter>
	inline Iter	unwrap_iterator(Iter iter){
		return (iter);
	}	
	
	
	template <typename Iter, typename Container>
	inline Iter	unwrap_iterator(random_access_iterator<Iter, Container> iter) {
		return (iter.base());
	}
}
#endif
