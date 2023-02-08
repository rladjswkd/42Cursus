#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <stdexcept>
# include <sstream>
# include <limits>
# include "iterator.hpp"
# include "algorithm.hpp"
# include "memory.hpp"
# include "iterator_base_funcs.hpp"

namespace ft {
	template<typename T, typename Allocator>
	struct vector_base {
	protected:
		typedef Allocator											allocator_type;
		typedef typename allocator_type::template rebind<T>::other	T_allocator_type;	//	allocator_type is always std::allocator<T> in this project.
		typedef typename allocator_type::pointer					pointer;
		pointer				_begin;
		pointer				_end;
		pointer				end_cap;
		T_allocator_type	t_alloc;

		vector_base();
		vector_base(const allocator_type &alloc);
		vector_base(size_t count, const allocator_type &alloc);
		~vector_base();

		pointer					allocate(size_t count);
		void					deallocate(pointer ptr, size_t count);
		void					create_storage(size_t count);
		T_allocator_type		&get_T_allocator();
		const T_allocator_type	&get_T_allocator() const;
		allocator_type			get_allocator() const;
	};


	template < class T, class Allocator = std::allocator<T> >
	class vector : protected vector_base<T, Allocator> {
		typedef vector_base<T, Allocator>								Base;
		typedef typename Base::T_allocator_type							T_allocator_type;
	public:
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef T&														reference;
		typedef const T&												const_reference;
		typedef T*														pointer;
		typedef const T*												const_pointer;
		typedef ft::random_access_iterator<pointer, vector>				iterator;
		typedef ft::random_access_iterator<const_pointer, vector>		const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

// constructor
		vector();
		explicit vector(const Allocator &alloc);
		explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator());
		vector(const vector &other);
		template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());

// destructor
		~vector();

// other member functions
		vector			&operator=(const vector &other);
		allocator_type	get_allocator() const;
		void			assign(size_type count, const T &value);
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
		iterator	insert(iterator pos, const value_type& value);
		void		insert(iterator pos, size_type count, const value_type& value);
		template <class InputIt>
		void		insert(iterator pos, InputIt first, InputIt last);
		iterator	erase(iterator pos);
		iterator	erase(iterator first, iterator last);
		void		push_back(const T &value);
		void		pop_back();
		void		resize(size_type count, T value = T());
		void		swap(vector &other);

	protected:
		using Base::allocate;
		using Base::deallocate;
		using Base::t_alloc;
		using Base::get_T_allocator;
// auxiliary
		size_type			validate_init_length(size_type count);
		void				validate_range(size_type count) const;
		size_type			validate_length(size_type count, const char *msg) const;
		template <class Integral>
		void				init_dispatch(Integral count, Integral value, ft::true_type);
		template <class InputIt>
		void				init_dispatch(InputIt first, InputIt last, ft::false_type);
		template <class InputIt>
		void				init_from_iterator(InputIt first, InputIt last, ft::input_iterator_tag);
		template <class ForwardIt>
		void				init_from_iterator(ForwardIt first, ForwardIt last, ft::forward_iterator_tag);
		void				assign_values(size_type count, const T &value);
		template <class Integral>
		void				assign_dispatch(Integral count, Integral value, ft::true_type);
		template <class InputIt>
		void				assign_dispatch(InputIt first, InputIt last, ft::false_type);
		template <class InputIt>
		void				assign_from_iterator(InputIt first, InputIt last, ft::input_iterator_tag);
		template <class ForwardIt>
		void				assign_from_iterator(ForwardIt first, ForwardIt last, ft::forward_iterator_tag);
		template <class ForwardIt>
		pointer				allocate_and_copy(size_type count, ForwardIt first, ForwardIt last);
		void				erase_from_pos(pointer pos);
		void				insert_value_no_realloc(iterator pos, const value_type &value);
		void				insert_value_realloc(iterator pos, const value_type &value);
		void				insert_values(iterator pos, size_type count, const value_type &value);
		void				insert_values_no_realloc(iterator pos, size_type count, const value_type &value);
		void				insert_values_realloc(iterator pos, size_type count, const value_type &value);
		template <class Integral>
		void				insert_dispatch(iterator pos, Integral count, Integral value, ft::true_type);
		template <class InputIt>
		void				insert_dispatch(iterator pos, InputIt first, InputIt last, ft::false_type);
		template <class InputIt>
		void				insert_from_iterator(iterator pos, InputIt first, InputIt last, ft::input_iterator_tag);
		template <class ForwardIt>
		void				insert_from_iterator(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag);
		template <class ForwardIt>
		void				insert_from_iterator_no_realloc(iterator pos, ForwardIt first, ForwardIt last, const size_type diff);
		template <class ForwardIt>
		void				insert_from_iterator_realloc(iterator pos, ForwardIt first, ForwardIt last, const size_type diff);
	};

///////////////////////////////////////////////////////////////////////
// vector_base
///////////////////////////////////////////////////////////////////////


// constructor

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base()
	: _begin(NULL), _end(NULL), end_cap(NULL), t_alloc() { }


	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(const allocator_type &alloc)
	: _begin(NULL), _end(NULL), end_cap(NULL), t_alloc(alloc) { }


	template <class T, class Allocator>
	inline vector_base<T, Allocator>::vector_base(size_t count, const allocator_type &alloc)
	: t_alloc(alloc) {
		create_storage(count);
	}


// destructor

	template <class T, class Allocator>
	inline vector_base<T, Allocator>::~vector_base() {
		deallocate(_begin, end_cap - _begin);
	}


// other member functions

	template <class T, class Allocator>
	inline typename vector_base<T, Allocator>::pointer	vector_base<T, Allocator>::allocate(size_t count) {
		if (count != 0)
			return (this->t_alloc.allocate(count));
		return (pointer());
	}


	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::deallocate(pointer ptr, size_t count) {
		if (ptr)
			this->t_alloc.deallocate(ptr, count);
	}


	template <class T, class Allocator>
	inline void vector_base<T, Allocator>::create_storage(size_t count) {
		this->_begin = this->allocate(count);
		this->_end = this->_begin;
		this->end_cap = this->_begin + count;
	}


	template <class T, class Allocator>
	inline typename vector_base<T, Allocator>::T_allocator_type	&vector_base<T, Allocator>::get_T_allocator() {
		return (this->t_alloc);
	}


	template <class T, class Allocator>
	inline const typename vector_base<T, Allocator>::T_allocator_type	&vector_base<T, Allocator>::get_T_allocator() const {
		return (this->t_alloc);
	}


	template <class T, class Allocator>
	inline typename vector_base<T, Allocator>::allocator_type	vector_base<T, Allocator>::get_allocator() const {
		return (allocator_type(t_alloc));
	}


///////////////////////////////////////////////////////////////////////
// vector
///////////////////////////////////////////////////////////////////////

// constructor

	template <class T, class Allocator>
	inline vector<T, Allocator>::vector() { }


	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(const Allocator &alloc) : Base(alloc) { }


	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(size_type count, const T &value, const Allocator &alloc) : Base(validate_init_length(count), alloc) {
		this->_end = ft::uninitialized_fill_n_alloc(this->_begin, count, value, this->t_alloc);
	}


	template <class T, class Allocator>
	inline vector<T, Allocator>::vector(const vector &other) : Base(other.size(), other.get_T_allocator()) {
		this->_end = ft::uninitialized_copy_alloc(other._begin, other._end, this->_begin, this->t_alloc);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator &alloc) : Base(alloc) {
		init_dispatch(first, last, typename ft::is_integral<InputIt>::type());
	}


// destructor

	template <class T, class Allocator>
	inline vector<T, Allocator>::~vector() {
		ft::destroy_range(this->_begin, this->_end, this->t_alloc);
	}


// element access

	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reference	vector<T, Allocator>::at(size_type pos){
		validate_range(pos);
		return ((*this)[pos]);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type pos) const{
		validate_range(pos);
		return ((*this)[pos]);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reference	vector<T, Allocator>::operator[](size_type pos){
		return (*(this->_begin + pos));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reference	vector<T, Allocator>::operator[](size_type pos) const{
		return (*(this->_begin + pos));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reference	vector<T, Allocator>::front(){
		return (*(this->_begin));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reference	vector<T, Allocator>::front() const{
		return (*(this->_begin));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reference	vector<T, Allocator>::back(){
		return (*(this->_end - 1));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reference	vector<T, Allocator>::back() const{
		return (*(this->_end - 1));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::pointer	vector<T, Allocator>::data(){
		return (this->_begin);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_pointer	vector<T, Allocator>::data() const{
		return (this->_begin);
	}


// iterator

	template <class T, class Allocator>
	inline typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
		return (iterator(this->_begin));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
		return (const_iterator(this->_begin));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
		return (iterator(this->_end));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
		return (const_iterator(this->_end));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() {
		return (reverse_iterator(end()));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const {
		return (const_reverse_iterator(end()));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() {
		return (reverse_iterator(begin()));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const {
		return (const_reverse_iterator(begin()));
	}


// capacity

	template <class T, class Allocator>
	inline bool vector<T, Allocator>::empty() const {
		return (this->_begin == this->_end);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const {
		return (size_type(this->_end - this->_begin));
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const {
		// return (ft::min<size_type>(std::numeric_limits<difference_type>::max() / sizeof(T), this->t_alloc.max_size()));
		return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), this->t_alloc.max_size()));
	}


	template <class T, class Allocator>
	inline void vector<T, Allocator>::reserve(size_type new_cap) {
		if (new_cap > this->max_size())
			throw std::length_error("vector::reserve");
  	    if (this->capacity() < new_cap) {
			const size_type	old_size = size();
			pointer	reserved = allocate_and_copy(new_cap, this->_begin, this->_end);
			ft::destroy_range(this->_begin, this->_end, this->t_alloc);
			deallocate(this->_begin, this->end_cap - this->_begin);
			this->_begin = reserved;
			this->_end = reserved + old_size;
			this->end_cap = this->_begin + new_cap;
		}
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
		return (size_type(this->end_cap - this->_begin));
	}


// modifier

	template <class T, class Allocator>
	inline void	vector<T, Allocator>::clear() {
		ft::destroy_range(this->_begin, this->_end, this->t_alloc);
		this->_end = this->_begin;
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::iterator	vector<T, Allocator>::insert(iterator pos, const value_type &value) {
		difference_type	diff = pos - begin();
		if (this->_end != this->end_cap)
			insert_value_no_realloc(pos, value);
		else
			insert_value_realloc(pos, value);
		return (iterator(this->_begin + diff));	//	this->_begin has been changed before return statement
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::insert(iterator pos, size_type count, const value_type &value) {
		insert_values(pos, count, value);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void	vector<T, Allocator>::insert(iterator pos, InputIt first, InputIt last) {
		insert_dispatch(pos, first, last, typename ft::is_integral<InputIt>::type());
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::iterator	vector<T, Allocator>::erase(iterator pos) {
		if (pos + 1 != end())	//	if pos is out of bounds, segmentation fault is caused.
			ft::copy(pos + 1, end(), pos);
		this->t_alloc.destroy(--this->_end);
		return (pos);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::iterator	vector<T, Allocator>::erase(iterator first, iterator last) {
		if (first != last) {
			if (last.base() != this->_end)
				ft::copy(last, end(), first);
			erase_from_pos(first.base() + (end() - last));
		}
		return (first);
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::push_back(const T &value) {
		if (this->_end != this->end_cap)	//	end < end_cap
			this->t_alloc.construct((this->_end)++, value);
		else
			insert_value_realloc(end(), value);
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::pop_back() {
		this->t_alloc.destroy(--this->_end);
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::resize(size_type count, T value) {
		if (count < size())
			erase_from_pos(this->_begin + count);
		else if (count > size())
			insert_values(end(), count - size(), value);	//	if capacity is less than count, reallocation occurs here
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::swap(vector &other) {
		pointer	begin_temp = this->_begin;
		pointer	end_temp = this->_end;
		pointer	end_cap_temp = this->end_cap;

		this->_begin = other._begin;
		this->_end = other._end;
		this->end_cap = other.end_cap;
		other._begin = begin_temp;
		other._end = end_temp;
		other.end_cap = end_cap_temp;
		//	std::allocator<T> is stateless. interchangeable.
	}


// other member functions

	template <class T, class Allocator>
	inline vector<T, Allocator>	&vector<T, Allocator>::operator=(const vector &other) {
		if (this != &other) {	// operator & is not overloaded.
			const size_type other_len = other.size();
			if (other_len > capacity()) {
				pointer temp = allocate_and_copy(other_len, other._begin, other._end);
				ft::destroy_range(this->_begin, this->_end, this->t_alloc);
				deallocate(this->_begin, this->end_cap - this->_begin);
				this->_begin = temp;
				this->end_cap = this->_begin + other_len;
			}
			else if (other_len <= size()) {
				ft::destroy_range(ft::copy(other._begin, other._end, this->_begin), this->_end, this->t_alloc);
			}
			else {
				ft::copy(other._begin, other._begin + size(), this->_begin);
				ft::uninitialized_copy_alloc(other._begin + size(),	other._end,	this->_end, this->t_alloc);
			}
			this->_end = this->_begin + other_len;
		}
		return (*this);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::allocator_type	vector<T, Allocator>::get_allocator() const {
		return (allocator_type());
	}


	template <class T, class Allocator>
	inline void	vector<T, Allocator>::assign(size_type count, const T &value) {
		assign_values(count, value);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void	vector<T, Allocator>::assign(InputIt first, InputIt last) {
		assign_dispatch(first, last, typename ft::is_integral<InputIt>::type());
	}


// non-member functions

	template <class T, class Allocator>
	inline bool	operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}


	template <class T, class Allocator>
	inline bool	operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (!(lhs == rhs));
	}


	template <class T, class Allocator>
	inline bool	operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}


	template <class T, class Allocator>
	inline bool	operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (!(rhs < lhs));
	}


	template <class T, class Allocator>
	inline bool	operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (rhs < lhs);
	}


	template <class T, class Allocator>
	inline bool	operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return (!(lhs < rhs));
	}


	template <class T, class Allocator>
	inline void	swap(ft::vector<T, Allocator> &lhs, ft::vector<T, Allocator> &rhs) {
		lhs.swap(rhs);
	}


// others

	template <class T, class Allocator>
	inline void	vector<T, Allocator>::validate_range(size_type count) const {
		std::ostringstream	ss;

		if (count >= this->size()) {
			ss << "vector::validate_range: count (which is " << count << ") >= this->size() (which is " << this->size() << ")";
			throw std::out_of_range(ss.str());
		}
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::size_type vector<T, Allocator>::validate_length(size_type count, const char *msg) const {
		if (max_size() - size() < count)
			throw std::length_error(msg);
		const size_t	new_size = size() + ft::max(size(), count);	// twice as its current size()
		if (new_size < size() || new_size > max_size())	// new_size < size() is checking overflow
			return (max_size());
		return (new_size);
	}


	template <class T, class Allocator>
	inline typename vector<T, Allocator>::size_type vector<T, Allocator>::validate_init_length(size_type count) {
		if (count > max_size())
			throw std::length_error("cannot create ft::vector larger than max_size()");
		return (count);
	}


	template <class T, class Allocator>
	template <class Integral>
	inline void vector<T, Allocator>::init_dispatch(Integral count, Integral value, ft::true_type) {
		this->_begin = this->allocate(validate_init_length(count));
		this->end_cap = this->_begin + count;
		this->_end = ft::uninitialized_fill_n_alloc(this->_begin, count, value, this->t_alloc);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::init_dispatch(InputIt first, InputIt last, ft::false_type) {
		init_from_iterator(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::init_from_iterator(InputIt first, InputIt last, ft::input_iterator_tag) {
		try {
			for (; first != last; ++first)
				push_back(*first);
		} catch(...) {
			clear();
			throw;
		}
	}


	// A reverse_iterator across other types can be copied if the underlying iterator can be converted to the type of current.
	// https://stackoverflow.com/questions/6449266/can-input-iterators-be-used-where-forward-iterators-are-expected
	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::init_from_iterator(ForwardIt first, ForwardIt last, ft::forward_iterator_tag)	{
		const size_type	diff = ft::distance(first, last);
		this->_begin = this->allocate(validate_init_length(diff));
		this->end_cap = this->_begin + diff;
		this->_end = ft::uninitialized_copy_alloc(first, last, this->_begin, this->t_alloc);
	}

	
	template <class T, class Allocator>
	template <class Integral>
	inline void vector<T, Allocator>::assign_dispatch(Integral count, Integral value, ft::true_type) {
		assign_values(count, value);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::assign_dispatch(InputIt first, InputIt last, ft::false_type) {
		assign_from_iterator(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
	}


	template <class T, class Allocator>
	inline void vector<T, Allocator>::assign_values(size_type count, const T &value)
	{
		if (count > capacity()) {
			vector<T, Allocator> temp(count, value, this->t_alloc);
			this->swap(temp);
		}
		else if (count > size()) {
			ft::fill(this->_begin, this->_end, value);
			const size_type diff = count - size();
			this->_end = ft::uninitialized_fill_n_alloc(this->_end, diff, value, this->t_alloc);
		}
		else
			erase_from_pos(ft::fill_n(this->_begin, count, value));
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::assign_from_iterator(InputIt first, InputIt last, ft::input_iterator_tag) {
		pointer	cur = this->_begin;

		for (; first != last && cur != this->_end; (void)++cur, (void)++first)
			*cur = *first;
		if (first == last)
			erase_from_pos(cur);
		else
			insert_from_iterator(end(), first, last, typename ft::iterator_traits<InputIt>::type());
	}


	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::assign_from_iterator(ForwardIt first, ForwardIt last, ft::forward_iterator_tag) {
		const size_type	len = ft::distance(first, last);

		if (len > capacity()) {
			validate_init_length(len);
			pointer	temp = allocate_and_copy(len, first, last);
			ft::destroy_range(this->_begin, this->_end, this->t_alloc);
			deallocate(this->_begin, this->end_cap - this->_begin);
			this->_begin = temp;
			this->_end = this->_begin + len;
			this->end_cap = this->_end;
		}
		else if (size() >= len)
			erase_from_pos(ft::copy(first, last, this->_begin));
		else {
			ForwardIt temp_it = first;
			ft::advance(temp_it, size());
			ft::copy(first, temp_it, this->_begin);
			this->_end = ft::uninitialized_copy_alloc(temp_it, last, this->_end, this->t_alloc);
		}
	}


	template <class T, class Allocator>
	template <class ForwardIt>
	inline typename vector<T, Allocator>::pointer vector<T, Allocator>::allocate_and_copy(size_type count, ForwardIt first, ForwardIt last)
	{
		pointer result = this->allocate(count);

		try {
			ft::uninitialized_copy_alloc(first, last, result, this->t_alloc);	// std::uninitialized_copy with allocator
			return (result);
		} catch (...) {
			deallocate(result, count);
			throw;
		}
	}


	template <class T, class Allocator>
	void	vector<T, Allocator>::erase_from_pos(pointer pos) {
		ft::destroy_range(pos, this->_end, this->t_alloc);
		this->_end = pos;
	}


	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_value_no_realloc(iterator pos, const value_type &value) {
		T	copy;

		if (pos.base() == this->_end) {
			this->t_alloc.construct(this->_end, value);
			++this->_end;
		}
		else {
			this->t_alloc.construct(this->_end, *(this->_end - 1));
			++this->_end;
			ft::copy_backward(pos.base(), this->_end - 2, this->_end - 1);	//	&(at(pos - this->_begin))
			copy = value;
			*pos = copy;
		}
	}


	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_value_realloc(iterator pos, const value_type &value) {
		const size_type	len = validate_length(size_type(1), "vector::insert");
		const size_type	elems_before = pos.base() - this->_begin;
		pointer			new_begin = this->allocate(len);
		pointer			new_end;
		try {
			this->t_alloc.construct(new_begin + elems_before, value);
			new_end = pointer();
			new_end = ft::uninitialized_copy_alloc(this->_begin, pos.base(), new_begin, this->t_alloc);
			++new_end;
			new_end = ft::uninitialized_copy_alloc(pos.base(), this->_end, new_end, this->t_alloc);
		}
		catch (...) {
			if (!new_end)
				this->t_alloc.destroy(new_begin + elems_before);	// first ft::uninitialized_copy_alloc is failed
			else
				ft::destroy_range(new_begin, new_end, this->t_alloc);
			deallocate(new_begin, len);
			throw;
		}
		ft::destroy_range(this->_begin, this->_end, this->t_alloc);
		deallocate(this->_begin, this->end_cap - this->_begin);
		this->_begin = new_begin;
		this->_end = new_end;
		this->end_cap = new_begin + len;
	}


	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_values(iterator pos, size_type count, const value_type &value) {
		if (count == 0)
			return;
		if (size_type(this->end_cap - this->_end) >= count)	//	free, allocated memory blocks are more than or equal to "count"
			insert_values_no_realloc(pos, count, value);
		else
			insert_values_realloc(pos, count, value);
	}
	
	
	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_values_no_realloc(iterator pos, size_type count, const value_type &value) {
		value_type		copy = value;
		pointer			old_end = this->_end;
		const size_type	elems_after = this->_end - pos.base();

		if (elems_after > count) {
			this->_end = ft::uninitialized_copy_alloc(old_end - count, old_end, old_end, this->t_alloc);	//	memory blocks after end need "construct"
			ft::copy_backward(pos.base(), old_end - count, old_end);	//	"construct" is unnecessary
			ft::fill(pos.base(), pos.base() + count, copy);
		}
		else {
			this->_end = ft::uninitialized_fill_n_alloc(old_end, count - elems_after, copy, this->t_alloc);	//	fill "copy" after end
			this->_end = ft::uninitialized_copy_alloc(pos.base(), old_end, this->_end, this->t_alloc);	//	fill original values after new end
			ft::fill(pos.base(), old_end, copy);
		}
	}
	
	
	template <class T, class Allocator>
	inline void vector<T, Allocator>::insert_values_realloc(iterator pos, size_type count, const value_type &value) {
		const size_type	len = validate_length(count, "vector::insert_values");
		value_type		copy = value;
		pointer			new_begin = this->allocate(len);
		pointer			new_end = new_begin;
		try {
			new_end = ft::uninitialized_copy_alloc(this->_begin, pos.base(), new_begin, this->t_alloc);
			new_end = ft::uninitialized_fill_n_alloc(new_end, count, copy, this->t_alloc);
			new_end = ft::uninitialized_copy_alloc(pos.base(), this->_end, new_end, this->t_alloc);
		} catch (...) {
			ft::destroy_range(new_begin, new_end, this->t_alloc);
			deallocate(new_begin, len);
			throw;
		}
		destroy_range(this->_begin, this->_end, this->t_alloc);	//	if exception is thrown before this statement, original vector elements will be destroyed and their memory blocks will be deallocated if their life cycle end. RAII
		deallocate(this->_begin, size_type(this->end_cap - this->_begin));
		this->_begin = new_begin;
		this->_end = new_end;
		this->end_cap = new_begin + len;
	}


	template <class T, class Allocator>
	template <class Integral>
	inline void vector<T, Allocator>::insert_dispatch(iterator pos, Integral count, Integral value, ft::true_type) {
		insert_values(pos, count, value);
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::insert_dispatch(iterator pos, InputIt first, InputIt last, ft::false_type) {
		insert_from_iterator(pos, first, last, typename ft::iterator_traits<InputIt>::iterator_category());
	}


	template <class T, class Allocator>
	template <class InputIt>
	inline void vector<T, Allocator>::insert_from_iterator(iterator pos, InputIt first, InputIt last, ft::input_iterator_tag) {
		if (pos.base() == this->_end) {
			for (; first != last; ++first)
				insert(this->_end, *first);	//	call insert(const_iterator pos, const value_type &value)
		}
		else if (first != last) {
			vector temp(first, last, this->t_alloc);
			insert(pos, temp.begin(), temp.end());	//	at the end, call insert_from_iterator(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag)
		}
	}


	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::insert_from_iterator(iterator pos, ForwardIt first, ForwardIt last, ft::forward_iterator_tag) {
		if (first == last)
			return;
		const size_type diff = ft::distance(first, last);
		if (size_type(this->end_cap - this->_end) >= diff)
			insert_from_iterator_no_realloc(pos, first, last, diff);
		else
			insert_from_iterator_realloc(pos, first, last, diff);
	}
	
	
	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::insert_from_iterator_no_realloc(iterator pos, ForwardIt first, ForwardIt last, const size_type diff) {
		const size_type elems_after = this->_end - pos.base();
		
		if (elems_after > diff) {
			ft::uninitialized_copy_alloc(this->_end - diff, this->_end, this->_end, this->t_alloc);
			ft::copy_backward(pos.base(), this->_end - diff, this->_end);
			ft::copy(first, last, pos);
		}
		else {
			ForwardIt temp_it = first;
			ft::advance(temp_it, elems_after);
			ft::uninitialized_copy_alloc(temp_it, last, this->_end, this->t_alloc);
			ft::uninitialized_copy_alloc(pos.base(), this->_end, this->_end + diff - elems_after, this->t_alloc);
			ft::copy(first, temp_it, pos);
		}
		this->_end += diff;
	}
	
	
	template <class T, class Allocator>
	template <class ForwardIt>
	inline void vector<T, Allocator>::insert_from_iterator_realloc(iterator pos, ForwardIt first, ForwardIt last, const size_type diff) {
		const size_type len = validate_length(diff, "vector::insert");
		pointer 		new_begin = this->allocate(len);
		pointer 		new_end = new_begin;
		try {
			new_end = ft::uninitialized_copy_alloc(this->_begin, pos.base(), new_begin, this->t_alloc);
			new_end	= ft::uninitialized_copy_alloc(first, last, new_end, this->t_alloc);
			new_end = ft::uninitialized_copy_alloc(pos.base(), this->_end, new_end, this->t_alloc);
		} catch(...) {
			ft::destroy_range(new_begin, new_end, this->t_alloc);
			deallocate(new_begin, len);
			throw;
		}
		ft::destroy_range(this->_begin, this->_end, this->t_alloc);
		deallocate(this->_begin, this->end_cap - this->_begin);
		this->_begin = new_begin;
		this->_end = new_end;
		this->end_cap = new_begin + len;
	}
}
#endif