#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <stddef.h>
# include <iterator>
namespace ft {
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iter>
	struct iterator_traits {
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;	
	};

	template <typename T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef random_access_iterator_tag			iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef random_access_iterator_tag			iterator_category;
	};


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

	template <class Iter>
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
		template <class U> reverse_iterator(const reverse_iterator<U>& other);
	};

	template <class Iter>
	inline reverse_iterator<Iter>::reverse_iterator() : current() { }

	template <class Iter>
	inline reverse_iterator<Iter>::reverse_iterator(iterator_type x) : current(x) { }
	
	template <class Iter>
	template <class U>
	inline reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U> &other) : current(other.current) { }
}
#endif
