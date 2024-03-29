template<typename _Tp, typename _Alloc>
struct _Vector_base {
	typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template rebind<_Tp>::other	_Tp_alloc_type;
	typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer				pointer;

	struct _Vector_impl_data {
		pointer _M_start;
		pointer _M_finish;
		pointer _M_end_of_storage;

		_Vector_impl_data() : _M_start(), _M_finish(), _M_end_of_storage() { }

		void	_M_copy_data(_Vector_impl_data const& __x) {
			_M_start = __x._M_start;
			_M_finish = __x._M_finish;
			_M_end_of_storage = __x._M_end_of_storage;
		}

		void	_M_swap_data(_Vector_impl_data& __x) {
			// Do not use std::swap(_M_start, __x._M_start), etc as it loses
			// information used by TBAA.
			_Vector_impl_data __tmp;
			__tmp._M_copy_data(*this);
			_M_copy_data(__x);
			__x._M_copy_data(__tmp);
		}
	};
	
	struct _Vector_impl	: public _Tp_alloc_type, public _Vector_impl_data {
		_Vector_impl() : _Tp_alloc_type() { }
		_Vector_impl(_Tp_alloc_type const& __a)	: _Tp_alloc_type(__a) { }
	};

public:
	
	typedef _Alloc allocator_type;

	_Tp_alloc_type& _M_get_Tp_allocator() {
		return this->_M_impl;
	}

	const _Tp_alloc_type&	_M_get_Tp_allocator() const {
		return this->_M_impl;
	}

	allocator_type get_allocator() const {
		return allocator_type(_M_get_Tp_allocator());
	}

	_Vector_base() { }

	_Vector_base(const allocator_type& __a) : _M_impl(__a) { }

	_Vector_base(size_t __n, const allocator_type& __a) : _M_impl(__a) {
		_M_create_storage(__n);
	}

	~_Vector_base() {
		_M_deallocate(_M_impl._M_start, _M_impl._M_end_of_storage - _M_impl._M_start);
	}

public:

	_Vector_impl _M_impl;

	pointer	_M_allocate(size_t __n) {
		typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
		return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
	}

	void	_M_deallocate(pointer __p, size_t __n) {
		typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
		if (__p)
			_Tr::deallocate(_M_impl, __p, __n);
	}

protected:
	
	void _M_create_storage(size_t __n) {
		this->_M_impl._M_start = this->_M_allocate(__n);
		this->_M_impl._M_finish = this->_M_impl._M_start;
		this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
	}
};