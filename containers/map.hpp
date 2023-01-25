#ifndef MAP_HPP
# define MAP_HPP
# include <functional>
# include <stddef.h>
# include <exception>
# include "pair.hpp"
# include "functional.hpp"
# include "tree.hpp"

namespace ft {

	template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator< ft::pair<const Key, T> > >
	class map {
	public:
		typedef	Key																								key_type;
		typedef T																								mapped_type;
		typedef ft::pair<const Key, T>																			value_type;
		typedef	std::size_t																						size_type;
		typedef std::ptrdiff_t																					difference_type;
		typedef Compare																							key_compare;
		typedef Allocator																						allocator_type;
		typedef value_type&																						reference;
		typedef const value_type&																				const_reference;
		typedef typename allocator_type::pointer																pointer;
		typedef typename allocator_type::const_pointer															const_pointer;

	private:
		typedef typename allocator_type::template rebind<value_type>::other										value_allocator_type;
		typedef ft::rb_tree<key_type, value_type, ft::use_first<value_type>, key_compare, value_allocator_type>	base_type;

	public:
		typedef typename base_type::iterator																	iterator;
		typedef typename base_type::const_iterator																const_iterator;
		typedef typename base_type::reverse_iterator															reverse_iterator;
		typedef typename base_type::const_reverse_iterator														const_reverse_iterator;

		class value_compare : binary_function<value_type, value_type, bool> {
		friend map<Key, T, Compare, Allocator>;
		protected:
			Compare	comp;
			value_compare(Compare c);
		public:
			bool	operator()(const value_type &lhs, const value_type &rhs) const;
		};

	private:
		base_type	tree;

	public:
		map();
		explicit
		map(const Compare &comp, const Allocator &alloc = Allocator());
		template <typename InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
		map(const map &other);
		~map();
		map											&operator=(const map &other);
		allocator_type								get_allocator() const;
		size_type									count(const Key &key) const;
		iterator									find(const Key &key);
		const_iterator								find(const Key &key) const;
		iterator									lower_bound(const Key &key);
		const_iterator								lower_bound(const Key &key) const;
		iterator									upper_bound(const Key &key);
		const_iterator								upper_bound(const Key &key) const;
		ft::pair<iterator, iterator>				equal_range(const Key &key);
		ft::pair<const_iterator, const_iterator>	equal_range(const Key &key) const;
		key_compare									key_comp() const;
		value_compare								value_comp() const;
		T											&at(const Key &key);
		const T										&at(const Key &key) const;
		T											&operator[](const Key &key);
		bool										empty() const;
		size_type									size() const;
		size_type									max_size() const;
		void										clear();
		ft::pair<iterator, bool>					insert(const value_type &value);
		iterator									insert(iterator pos, const value_type &value);
		template <class InputIt>
		void 										insert(InputIt first, InputIt last);
		void 										erase(iterator position);
		size_type 									erase(const key_type& k);
		void 										erase(iterator first, iterator last);
		void										swap(map &other);
		iterator									begin();
		const_iterator								begin() const;
		iterator									end();
		const_iterator								end() const;
		reverse_iterator							rbegin();
		const_reverse_iterator						rbegin() const;
		reverse_iterator							rend();
		const_reverse_iterator						rend() const;
	};

///////////////////////////////////////////////////////////////////////
// map::value_compare
///////////////////////////////////////////////////////////////////////
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>::value_compare::value_compare(Compare c) : comp(c) { }	//	just comp? not value_compare::comp or something?

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	map<Key, T, Compare, Allocator>::value_compare::operator()(const value_type &lhs, const value_type &rhs) const {
		return (comp(lhs.first, rhs.first));
	}

///////////////////////////////////////////////////////////////////////
// map
///////////////////////////////////////////////////////////////////////
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>::map()
	: tree() { }

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>::map(const Compare &comp, const Allocator &alloc)
	: tree(comp, alloc) { }

	template <typename Key, typename T, typename Compare, typename Allocator>
	template <typename InputIt>
	inline map<Key, T, Compare, Allocator>::map(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc)
	: tree(comp, alloc) {
		tree.insert(first, last);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>::map(const map &other)
	: tree(other.tree) { }

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>::~map() { }

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline map<Key, T, Compare, Allocator>	&map<Key, T, Compare, Allocator>::operator=(const map &other) {
		tree = other.tree;
		return (*this);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::allocator_type	map<Key, T, Compare, Allocator>::get_allocator() const {
		return (allocator_type(tree.get_allocator()));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::count(const Key &key) const {
		return (size_type(tree.find(key) != tree.end()));
	}
	
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::find(const Key &key) {
		return (tree.find(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::find(const Key &key) const {
		return (tree.find(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::lower_bound(const Key &key) {
		return (tree.lower_bound(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const {
		return (tree.lower_bound(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::upper_bound(const Key &key) {
		return (tree.upper_bound(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const {
		return (tree.upper_bound(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline ft::pair<typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator> map<Key, T, Compare, Allocator>::equal_range(const Key &key) {
		return (tree.equal_range(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator> map<Key, T, Compare, Allocator>::equal_range(const Key &key) const {
		return (tree.equal_range(key));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::key_compare	map<Key, T, Compare, Allocator>::key_comp() const {
		return (tree.key_comp());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::value_compare	map<Key, T, Compare, Allocator>::value_comp() const {
		return (value_comp(tree.key_comp()));
	}
	
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline T &map<Key, T, Compare, Allocator>::at(const Key &key) {
		iterator	it = lower_bound(key);
		if (it == end() || key_comp()(key, (*it).first))
			throw (std::out_of_range("map::at"));
		return ((*it).second);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline const T &map<Key, T, Compare, Allocator>::at(const Key &key) const {
		const iterator	it = lower_bound(key);
		if (it == end() || key_comp()(key, (*it).first))
			throw (std::out_of_range("map::at"));
		return ((*it).second);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline T &map<Key, T, Compare, Allocator>::operator[](const Key &key) {
		iterator	it = lower_bound(key);
		if (it == end() || key_comp()(key, (*it).first))
			it = insert(it, value_type(key, mapped_type()));
		return ((*it).second);
	}
	
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	map<Key, T, Compare, Allocator>::empty() const {
		return (tree.empty());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::size_type	map<Key, T, Compare, Allocator>::size() const {
		return (tree.size());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::size_type	map<Key, T, Compare, Allocator>::max_size() const {
		return (tree.max_size());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void	map<Key, T, Compare, Allocator>::clear() {
		tree.clear();
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>	map<Key, T, Compare, Allocator>::insert(const value_type &value) {
		return (tree.insert(value));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::insert(iterator pos, const value_type &value) {
		return (tree.insert(pos, value));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	template <class InputIt>
	inline void	map<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last) {
		tree.insert(first, last);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void	map<Key, T, Compare, Allocator>::erase(iterator position) {
		tree.erase(position);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::size_type	map<Key, T, Compare, Allocator>::erase(const key_type& k) {
		return (tree.erase(k));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void	map<Key, T, Compare, Allocator>::erase(iterator first, iterator last) {
		tree.erase(first, last);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void	map<Key, T, Compare, Allocator>::swap(map &other) {
		tree.swap(other.tree);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::begin() {
		return (tree.begin());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::begin() const {
		return (tree.begin());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::end() {
		return (tree.end());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::end() const {
		return (tree.end());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::reverse_iterator	map<Key, T, Compare, Allocator>::rbegin() {
		return (tree.rbegin());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_reverse_iterator	map<Key, T, Compare, Allocator>::rbegin() const {
		return (tree.rbegin());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::reverse_iterator	map<Key, T, Compare, Allocator>::rend() {
		return (tree.rend());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline typename map<Key, T, Compare, Allocator>::const_reverse_iterator	map<Key, T, Compare, Allocator>::rend() const {
		return (tree.rend());
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (lhs.tree == rhs.tree);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (lhs.tree < rhs.tree);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (rhs < lhs);
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		return (!(lhs < rhs));
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void swap(map<Key, T, Compare, Allocator> &lhs, map<Key, T, Compare, Allocator> &rhs) {
		lhs.swap(rhs);		
	}
}
#endif