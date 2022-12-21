#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>

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
}
#endif