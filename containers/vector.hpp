#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <algorithm>
# include "iterator.hpp"
# include "allocate.hpp"

namespace ft {
	template<typename T, typename Allocator>
	struct vector_base {
	public:

		typedef Allocator											allocator_type;

	protected:

		// allocator_type is always std::allocator<T> in this project.
		typedef typename allocator_type::template rebind<T>::other	T_allocator_type;
		typedef typename allocator_type::pointer					pointer;

		pointer				begin;
		pointer				end;
		pointer				end_cap;

		T_allocator_type	t_alloc;

		vector_base();
		vector_base(const allocator_type& alloc);
		vector_base(size_t count, const allocator_type& alloc);
		~vector_base();

		pointer	allocate(size_t count);
		void	deallocate(pointer ptr, size_t count);
		void	create_storage(size_t count);

		T_allocator_type&		get_T_allocator();
		const T_allocator_type&	get_T_allocator() const;
		allocator_type			get_allocator() const;
	};


	template < class T, class Allocator = std::allocator<T> >
	class vector : protected vector_base<T, Allocator> {

		typedef vector_base<T, Allocator>							Base;
		typedef typename Base::T_allocator_type						T_allocator_type;

	public:

		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;
		typedef T*										iterator;				// implement iterator later.
		typedef const T*								const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	protected:

		using Base::allocate;													// using declaration
		using Base::deallocate;
		using Base::t_alloc;
		using Base::get_T_allocator;

	public:

		vector();
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		vector(const vector& other);
		template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());

		~vector();

		vector&			operator=(const vector& other);
		allocator_type	get_allocator() const;
		void			assign(size_type count, const T& value);
		template <class InputIt>
		void			assign(InputIt first, InputIt last);


// element access
		reference		at(size_type pos);
		const_reference	at(size_type pos) const;
		reference		operator[](size_type pos);
		const_reference	operator[](size_type pos) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;
		T*				data();
		const T*		data() const;

// iterator
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

// capacity
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;
		void		reserve(size_type new_cap);
		size_type	capacity() const;

// modifier
		void		clear();
		iterator	insert(const_iterator pos, const T& value);
		void		insert(const_iterator pos, size_type count, const value_type& value);
		template <class InputIt>
		iterator	insert(const_iterator pos, InputIt first, InputIt last);
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		push_back(const T& value);
		void		pop_back();
		void		resize(size_type count, T value = T());
		void		swap(vector& other);

	protected:

		static size_type	_max_size(const T_allocator_type& alloc);
		pointer				_allocate_and_copy(size_type count, pointer first, pointer last);
	};

///////////////////////////////////////////////////////////////////////
// vector_base
///////////////////////////////////////////////////////////////////////

// constructor
	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base()
	: begin(NULL), end(NULL), end_cap(NULL), t_alloc() { }

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(const allocator_type& alloc)
	: begin(NULL), end(NULL), end_cap(NULL), t_alloc(alloc) { }

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(size_t count, const allocator_type& alloc)
	: t_alloc(alloc) {
		create_storage(count)
	}

// destructor
	template <class T, class Allocator>
	inline vector_base<T, Allocator>::~vector_base() {
		deallocate(begin, end_cap - begin);
	}

// other member functions
	template <class T, class Allocator>
	inline vector_base<T, Allocator>::pointer	vector_base<T, Allocator>::allocate(size_t count) {
		if (count != 0)
			this->t_alloc.allocate(count);
		return (pointer());
	}

	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::deallocate(pointer ptr, size_t count) {
		if (ptr)
			this->t_alloc.deallocate(ptr, count);
	}

	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::create_storage(size_t count) {
		this->begin = allocate(count);
		this->end = this->begin;
		this->end_cap = this->begin + this->count;
	}

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::T_allocator_type&	vector_base<T, Allocator>::get_T_allocator() {
		return (this->t_alloc);
	}

	template <class T, class Allocator>
	inline const vector_base<T, Allocator>::T_allocator_type&	vector_base<T, Allocator>::get_T_allocator() const {
		return (this->t_alloc);
	}

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::allocator_type	vector_base<T, Allocator>::get_allocator() const {
		return (allocator_type(t_alloc));
	}

///////////////////////////////////////////////////////////////////////
// vector
///////////////////////////////////////////////////////////////////////
// constructor

// destructor

// element access

// iterator
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
	
// capacity
	template <class T, class Allocator>
	inline bool vector<T, Allocator>::empty() const {
		return (this->begin == this->end);
	}
	
	template <class T, class Allocator>
	vector<T, Allocator>::size_type vector<T, Allocator>::size() const {
		return (size_type(this->end - this->begin));
	}
	
	template <class T, class Allocator>
	vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const {
		return(_max_size(get_T_allocator()));
	}
	
	template <class T, class Allocator>
	void vector<T, Allocator>::reserve(size_type new_cap) {
		const size_type	old_size;
		pointer			reserved;

		if (new_cap > this->max_size())
			__throw_length_error("__vector::reserve");
  	    if (this->capacity() < new_cap) {
			old_size = size();
			reserved = _allocate_and_copy(new_cap, this->begin, this->end);
			ft::destroy_range(this->begin, this->end, this->t_alloc);
			deallocate(this->begin, this->end_cap - this->begin);
			this->begin = reserved;
			this->end = reserved + old_size;
			this->end_cap = this->begin + new_cap;
		}
	}
	
	template <class T, class Allocator>
	vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
		return (size_type(this->end_cap - this->begin));
	}

// modifier

// other member functions

// non-member functions
	template <class T, class Allocator>
	bool	operator==(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator!=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator<(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator<=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator>(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator>=(const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	void	swap(std::vector<T, Allocator>& lhs, std::vector<T, Allocator>& rhs);

// others
	template <class T, class Allocator>
	vector<T, Allocator>::size_type	vector<T, Allocator>::_max_size(const T_allocator_type& alloc) {
		return (std::min<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() / sizeof(T), alloc.max_size()));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::pointer	vector<T, Allocator>::_allocate_and_copy(size_type count, pointer first, pointer last) {
		pointer result = this->allocate(count);

		try {
			uninitialized_copy_alloc(first, last, result, this->t_alloc); 	// std::uninitialized_copy with allocator
			return result;
		} catch(...) {
			deallocate(result, count);
			throw;
		}
	}
}
#endif