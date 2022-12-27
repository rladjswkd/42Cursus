#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <algorithm>
# include <stdexcept> 		// exceptions
# include <sstream>
# include "iterator.hpp"
# include "allocate.hpp"
# include "is_integral.hpp"

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
		pointer			data();
		const_pointer	data() const;

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
		iterator	insert(const_iterator pos, const value_type& value);
		void		insert(const_iterator pos, size_type count, const value_type& value);
		template <class InputIt>
		void		insert(const_iterator pos, InputIt first, InputIt last);
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		push_back(const T& value);
		void		pop_back();
		void		resize(size_type count, T value = T());
		void		swap(vector& other);

	protected:

		template <class Integral>
		void				init_dispatch(Integral count, Integral value, ft::true_type);
		template <class InputIt>
		void				init_dispatch(InputIt first, InputIt last, ft::false_type);
		static size_type	choose_max_size(const T_allocator_type& alloc);
		pointer				allocate_and_copy(size_type count, pointer first, pointer last);
		void				erase_from_pos(pointer pos);
		void				insert_no_realloc(iterator pos, const value_type& value);
		void				insert_realloc(iterator pos, const value_type& value);
		void				insert_fill(iterator pos, size_type count, const value_type& value);
		template <class Integral>
		void				insert_dispatch(iterator pos, Integral count, Integral value, ft::true_type);
		template <class InputIt>
		void				insert_dispatch(iterator pos, InputIt first, InputIt last, ft::false_type);
		template <class InputIt>
		void				insert_range(iterator pos, InputIt first, InputIt last, ft::input_iterator_tag);
		template <class ForwardIt>
		void				insert_range(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag);

	// validation
		void				validate_range(size_type count) const;
		size_type			validate_length(size_type count, const char *msg) const;
		size_type			validate_init_length(size_type count);
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
		this->begin = this->allocate(count);
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
	template <class T, class Allocator>
	vector<T, Allocator>::vector() { }

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const Allocator& alloc)
	: vector_base(alloc) { }

	template <class T, class Allocator>
	vector<T, Allocator>::vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
	: vector_base(validate_init_length(count), alloc) {
		ft::uninitialized_fill_n_alloc(this->begin, count, value, alloc);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const vector& other)
	: vector_base(other.size(), other.get_T_allocator()) {
		ft::uninitialized_copy_alloc(other->begin, other->end, this->begin, this->t_alloc);
	}

	template <class T, class Allocator>
	template <class InputIt>
	vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
	: vector_base(alloc) {
		init_dispatch(first, last, ft::is_integral<InputIt>::type());
	}

// destructor
	template <class T, class Allocator>
	vector<T, Allocator>::~vector() {
		ft::destroy_range(this->begin, this->end, this->t_alloc);
	}

// element access
	template <class T, class Allocator>
	vector<T, Allocator>::reference		vector<T, Allocator>::at(size_type pos){
		validate_range(pos);
		return ((*this)[pos]);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type pos) const{
		validate_range(pos);
		return ((*this)[pos]);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::reference		vector<T, Allocator>::operator[](size_type pos){
		return (*(this->begin + pos))
	}

	template <class T, class Allocator>
	vector<T, Allocator>::const_reference	vector<T, Allocator>::operator[](size_type pos) const{
		return (*(this->begin + pos));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::reference		vector<T, Allocator>::front(){
		return (*(this->begin));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::const_reference	vector<T, Allocator>::front() const{
		return (*(this->begin));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::reference		vector<T, Allocator>::back(){
		return (*(this->end - 1));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::const_reference	vector<T, Allocator>::back() const{
		return (*(this->end - 1));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::pointer	vector<T, Allocator>::data(){
		return (this->begin);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::const_pointer		vector<T, Allocator>::data() const{
		return (this->begin);
	}

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
		return(choose_max_size(get_T_allocator()));
	}
	
	template <class T, class Allocator>
	void vector<T, Allocator>::reserve(size_type new_cap) {
		const size_type	old_size;
		pointer			reserved;

		if (new_cap > this->max_size())
			throw std::length_error("vector::reserve");
  	    if (this->capacity() < new_cap) {
			old_size = size();
			reserved = allocate_and_copy(new_cap, this->begin, this->end);
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
	template <class T, class Allocator>
	void		vector<T, Allocator>::clear() {
		erase_from_pos(this->begin);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::iterator	vector<T, Allocator>::insert(const_iterator pos, const value_type& value) {
		if (this->end != this->end_cap)				// if there is no problem, end is always smaller than end_cap
			insert_no_realloc(pos, value);
		else
			insert_realloc(pos, value);
		return (iterator(pos));
	}

	template <class T, class Allocator>
	void		vector<T, Allocator>::insert(const_iterator pos, size_type count, const value_type& value) {
		insert_fill(pos, count, value);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) {
		insert_dispatch(pos, first, last, ft::is_integral<InputIt>::type);
	}

	template <class T, class Allocator>
	template <class Integral>
	inline void vector<T, Allocator>::init_dispatch(Integral count, Integral value, ft::true_type) {
		this->begin = this->allocate(count);
		this->end = this->begin + count;
		this->end_cap = this->end;
		// this->end = 
		ft::uninitialized_fill_n(this->begin, count, value, this->t_alloc);
	}

	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::init_dispatch(InputIt first, InputIt last, ft::false_type) {
	}

	template <class T, class Allocator>
	template <class Integral>
	inline void vector<T, Allocator>::insert_dispatch(iterator pos, Integral count, Integral value, ft::true_type) {
		insert_fill(pos, count, value);
	}

	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::insert_dispatch(iterator pos, InputIt first, InputIt last, ft::false_type) {
		insert_range(pos, first, last, ft::iterator_traits<InputIt>::iterator_category())
	}

	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::insert_range(iterator pos, InputIt first, InputIt last, ft::input_iterator_tag) {
		if (pos == this->end) {
			for (; first != last; ++first)
				insert(this->end, *first);	//	call insert(const_iterator pos, const value_type& value)
		}
		else if (first != last) {
			vector temp(first, last, this->t_alloc);
			insert(pos, temp.begin(), temp.end());	//	at the end, call insert_range(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag)
		}
	}

	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::insert_range(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag) {
		if (first != last) {
			const size_type diff = std::distance(first, last);				//	last - first is impossible for forward iterators
			if (size_type(this->end_cap - this->end) >= diff) {				//	if capacity is enough
				const size_type elems_after = this->end - pos;
				if (elems_after > diff) {									//	if new diff elements fits in vector size()
					ft::uninitialized_copy_alloc(this->end - diff, this->end, this->end, this->t_alloc);
					std::copy_backward(pos.base(), this->end - diff, this->end);
					std::copy(first, last, pos);
				}
				else {
					ForwardIt temp_it = first;
					std::advance(temp_it, elems_after);
					ft::uninitialized_copy_alloc(temp_it, last, this->end, this->t_alloc);
					ft::uninitialized_copy_alloc(pos.base(), this->end, this->end + diff - elems_after, this->t_alloc);
					std::copy(first, temp_it, pos);
				}
				this->end += diff;
			}
			else {															//	capacity is not enough
				pointer old_begin = this->begin;
				pointer old_end = this->end;
				const size_type len = validate_length(diff, "vector::insert_range");
				pointer new_begin = this->allocate(len);
				pointer new_end = new_begin;
				try {
					new_end = ft::uninitialized_copy_alloc(old_begin, pos.base(), new_begin, this->t_alloc);
					new_end	= ft::uninitialized_copy_alloc(first, last, new_end, this->t_alloc);
					new_end = ft::uninitialized_copy_alloc(pos.base(), old_end, new_end, this->t_alloc);
				} catch(...) {
					ft::destroy_range(new_begin, new_end, this->t_alloc);
					deallocate(new_begin, len);
					throw;
				}
				ft::destroy_range(old_begin, old_end, this->t_alloc);
				deallocate(old_begin, this->end_cap - old_begin);
				this->begin = new_begin;
				this->end = new_end;
				this->end_cap = new_begin + len; 		
			}
		}
	}

	template <class T, class Allocator>
	vector<T, Allocator>::iterator	vector<T, Allocator>::erase(iterator pos) {
		if (pos + 1 != this->end)
			std::copy(pos + 1, this->end, pos);
		--this->end;
		this->t_alloc.destroy(this->end);
		return (pos);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::iterator	vector<T, Allocator>::erase(iterator first, iterator last) {
		if (first != last) {
			if (last != this->end)
				std::copy(last, this->end, first);
			erase_from_pos(first.base() + (this->end - last));
		}
		return (first);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::push_back(const T& value) {
		if (this->end != this->end_cap)	//	end < end_cap
			this->t_alloc.construct((this->end)++, value);
		else
			insert_realloc(this->end, value);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::pop_back() {
		--this->end;
		this->t_alloc.destroy(this->end);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::resize(size_type count, T value = T()) {
		if (count < size())
			erase_from_pos(this->begin + count);
		else if (count > size())
			insert_fill(this->end, count - size(), value);	//	if capacity is less than count, reallocation occurs here
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::swap(vector& other) {
		pointer	begin_temp = this->begin;
		pointer	end_temp = this->end;
		pointer	end_cap_temp = this->end_cap;

		this->begin = other.begin;
		this->end = other.end;
		this->end_cap = other.end_cap;
		other.begin = begin_temp;
		other.end = end_temp;
		other.end_cap = end_cap_temp;
		//	std::allocator<T> is stateless. interchangeable.
	}

// other member functions

// non-member functions
	template <class T, class Allocator>
	bool	operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	bool	operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs);

	template <class T, class Allocator>
	void	swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs) {
		lhs.swap(rhs);
	}

// others
	template <class T, class Allocator>
	vector<T, Allocator>::size_type	vector<T, Allocator>::choose_max_size(const T_allocator_type& alloc) {
		return (std::min<ptrdiff_t>(std::numeric_limits<ptrdiff_t>::max() / sizeof(T), alloc.max_size()));
	}

	template <class T, class Allocator>
	vector<T, Allocator>::pointer	vector<T, Allocator>::allocate_and_copy(size_type count, pointer first, pointer last) {
		pointer result = this->allocate(count);

		try {
			uninitialized_copy_alloc(first, last, result, this->t_alloc); 	// std::uninitialized_copy with allocator
			return result;
		} catch (...) {
			deallocate(result, count);
			throw;
		}
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::validate_range(size_type count) const {
		std::ostringstream	ss;

		if (count >= this->size()) {
			ss << "vector::validate_range: count (which is " << count << ") >= this->size() (which is " << this->size() << ")";
			throw std::out_of_range(ss.str());
		}
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::size_type vector<T, Allocator>::validate_length(size_type count, const char *msg) const {
		const size_type	new_size;

		if (max_size() - size() < count)
			throw std::length_error(msg);
		new_size = size() + std::max(size(), count);	// twice as its current size()
		if (new_size < size() || new_size > max_size())	// new_size < size() is checking overflow
			return (max_size());
		return (new_size);
	}

	template <class T, class Allocator>
	inline vector<T, Allocator>::size_type vector<T, Allocator>::validate_init_length(size_type count) {
		if (count > choose_max_size(get_T_allocator()))
			throw std::length_error("cannot create ft::vector larger than max_size()");
		return (count);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::erase_from_pos(pointer pos) {
		ft::destroy_range(pos, this->end, t_alloc);
		this->end = pos;
	}

	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_no_realloc(iterator pos, const value_type &value) {
		T	copy;

		if (pos == this->end) {
			this->t_alloc.construct(this->end, value);
			++this->end;
		}
		else {
			this->t_alloc.construct(this->end, *(this->end - 1));
			++this->end;
			std::copy_backward(pos.base(), this->end - 2, this->end - 1);	//	&(at(pos - this->begin))
			copy = value;
			*pos = copy;
		}
	}

	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_realloc(iterator pos, const value_type &value) {
		const size_type	len = validate_length(size_type(1), "vector::insert");
		const size_type	elems_before = pos - this->begin;
		pointer			old_begin = this->begin;
		pointer			old_end = this->end;
		pointer			new_begin(this->allocate(len));	// no need to do something for exceptions thrown by this.
		pointer			new_end;
		try {
			this->t_alloc.construct(this->t_alloc, new_begin + elems_before, value);
			new_end = pointer();
			new_end = ft::uninitialized_copy_alloc(old_begin, pos.base(), new_begin, this->t_alloc);
			++new_end;	// this memory space is for "value"
			new_end = ft::uninitialized_copy_alloc(pos.base(), old_end, new_end, this->t_alloc);
		}
		catch (...) {
			if (!new_end)
				this->t_alloc.destroy(new_begin + elems_before);	// first ft::uninitialized_copy_alloc is failed
			else
				ft::destroy_range(new_begin, new_end, this->t_alloc);
			deallocate(new_begin, len);
			throw;
		}
		ft::destroy_range(old_begin, old_end, this->t_alloc);
		deallocate(old_begin, this->end_cap - old_begin);
		this->begin = new_begin;
		this->end = new_end;
		this->end_cap = new_begin + len;
	}

	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_fill(iterator pos, size_type count, const value_type &value) {
		value_type		copy;
		const size_type	elems_before;
		const size_type	elems_after;
		pointer			old_begin;
		pointer			old_end;
		const pointer	pos_base;
		const size_type	len;
		pointer			new_begin;
		pointer			new_end;

		if (count == 0)
			return;
		if (size_type(this->end_cap - this->end) >= count){	//	free, allocated memory blocks are more than or equal to "count"
			copy = value;
			elems_after = this->end - pos;
			old_end(this->end);
			if (elems_after > count) {
				ft::uninitialized_copy_alloc(old_end - count, old_end, old_end, this->t_alloc);	//	memory blocks after end need "construct"
				this->end += count;
				std::copy_backward(pos.base(), old_end - count, old_end);	//	"construct" is unnecessary
				std::fill(pos.base(), pos.base() + count, copy);
			}
			else {
				this->end =	ft::uninitialized_fill_n_alloc(old_end, count - elems_after, copy, this->t_alloc);	//	fill "copy" after end
				ft::uninitialized_copy_alloc(pos.base(), old_end, this->end, this->t_alloc);	//	fill original values after new end
				this->end += elems_after;	//	end is old_end + count now
				std::fill(pos.base(), old_end, copy);
			}
		}
		else {
			old_begin = this->begin;
			old_end = this->end;
			pos_base = pos.base();
			len = validate_length(count, "vector::insert_fill");
			elems_before = pos_base - old_begin;
			new_begin(this->allocate(len));
			try {
				ft::uninitialized_fill_n_alloc(new_begin + elems_before, count, value, this->t_alloc);
				new_end = pointer();
				new_end = ft::uninitialized_copy_alloc(old_begin, pos_base, new_begin, this->t_alloc);
				new_end += count;
				new_end = ft::uninitialized_copy_alloc(pos_base, old_end, new_end, this->t_alloc);
			} catch (...) {
				if (!new_end)
					ft::destroy_range(new_begin + elems_before,	new_begin + elems_before + count, this->t_alloc);
				else
					ft::destroy_range(new_begin, new_end, this->t_alloc);
				deallocate(new_begin, len);
				throw;
			}
			destroy_range(old_begin, old_end, this->t_alloc);
			deallocate(old_begin, this->end_cap - old_begin);
			this->begin = new_begin;
			this->end = new_end;
			this->end_cap = new_begin + len;
		}
	}
}
#endif