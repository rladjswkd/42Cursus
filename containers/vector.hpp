#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "iterator.hpp"
# include <memory>
# include <cstddef> // std::size_t, std::ptrdiff_t
# include <stdexcept> // exceptions

# include <vector> // remove
# include <deque>
namespace ft {
// vector_base
	template <class T, class Allocator>
	struct vector_base {
		typedef Allocator	allocator_type;
		typedef T*			pointer;
		typedef std::size_t	size_type;

		pointer		begin;
		pointer		end;
		pointer		capacity_end;
		Allocator	allocator;

		vector_base();
		vector_base(const allocator_type& alloc);
		vector_base(size_type count, const allocator_type& alloc);
		~vector_base();

		pointer	allocate_memory(size_type count);
		void	deallocate_memory(pointer ptr, size_type count);
		void	create_storage(size_type count);

	};

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base() : begin(NULL), end(NULL), capacity_end(NULL), alloc() { }

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(const allocator_type& alloc) : begin(NULL), end(NULL), capacity_end(NULL), allocator(alloc) { }

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(size_type count, const allocator_type& alloc) : allocator(alloc) {
		create_storage(count);
	}

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::~vector_base() {
		deallocate_memory(begin, apacity_end - begin);
	}

	template <class T, class Allocator>
	inline T* vector_base<T, Allocator>::allocate_memory(size_type count) {
		if (count != 0)
			return (Allocator().allocate(count));  // default constructors are stateless.
		return (pointer());
	}

	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::deallocate_memory(pointer ptr, size_type count) {
		if (ptr)
			Allocator().deallocate(ptr, count);
	}

	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::create_storage(size_type count) {
		begin = allocate_memory(count);
		end = begin;
		capacity_end = begin + count;
	}


// vector
	template < class T, class Allocator = std::allocator<T> >
	class vector : protected vector_base<T, Allocator> {
	public:
	// member types
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T*										iterator;	// implement iterator later.
		typedef const T*								const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	// constructor
		vector();
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template <class InputIt> vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		vector(const vector& other);

	// iterator
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
	};

	template <class T, class Allocator>
	inline vector<T, Allocator>::vector() { }

	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(const Allocator& alloc)
	: vector_base(alloc) { }

	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
	: vector_base(count, alloc) {
		
	}

	template <class T, class Allocator>
	template <class InputIt>
	inline vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {

	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(const vector& other) {

	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
		return (iterator(this->begin));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
		return (const_iterator(this->begin));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::iterator vector<T, Allocator>::end() {
		return (iterator(this->end));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
		return (const_iterator(this->end));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() {
		return (reverse_iterator(this->end));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const {
		return (const_reverse_iterator(this->end));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() {
		return (reverse_iterator(this->begin));
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const {
		return (const_reverse_iterator(this->begin));
	}
}
#endif