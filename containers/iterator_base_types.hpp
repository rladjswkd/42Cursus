#ifndef ITERATOR_BASE_TYPES_HPP
# define ITERATOR_BASE_TYPES_HPP
# include <iterator>

namespace ft {
	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag : public input_iterator_tag {};
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	typedef std::input_iterator_tag					input_iterator_tag;
	typedef std::output_iterator_tag				output_iterator_tag;
	typedef std::forward_iterator_tag				forward_iterator_tag;
	typedef std::bidirectional_iterator_tag			bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag			random_access_iterator_tag;

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
}
#endif