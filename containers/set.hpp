#ifndef SET_HPP
# define SET_HPP
# include <stddef.h>
# include <exception>
# include "pair.hpp"
# include "functional.hpp"
# include "tree.hpp"

namespace ft {
	template <typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key> >
	class set {
	public:
		typedef	Key																								key_type;
		typedef Key																								value_type;
		typedef Compare																							key_compare;
		typedef Compare																							value_compare;
		typedef Allocator																						allocator_type;
	
	private:
		typedef typename allocator_type::template rebind<Key>::other											key_allocator_type;
		typedef ft::rb_tree<key_type, value_type, ft::use_self<value_type>, key_compare, key_allocator_type>	base_type;
	
	public:
		typedef	std::size_t																						size_type;
		typedef std::ptrdiff_t																					difference_type;
		typedef value_type&																						reference;
		typedef const value_type&																				const_reference;
		typedef typename allocator_type::pointer																pointer;
		typedef typename allocator_type::const_pointer															const_pointer;
		typedef typename base_type::const_iterator																iterator;
		typedef typename base_type::const_iterator																const_iterator;
		typedef typename base_type::const_reverse_iterator														reverse_iterator;
		typedef typename base_type::const_reverse_iterator														const_reverse_iterator;
	
	private:
		base_type	tree;

	public:
		set();
		explicit
		set(const Compare &comp, const Allocator &alloc = Allocator());
		template <typename InputIt>
		set(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
		set(const set &other);
		~set();
		set											&operator=(const set &other);
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
		void										swap(set &other);
		iterator									begin();
		const_iterator								begin() const;
		iterator									end();
		const_iterator								end() const;
		reverse_iterator							rbegin();
		const_reverse_iterator						rbegin() const;
		reverse_iterator							rend();
		const_reverse_iterator						rend() const;

		template <typename _Key, typename _Compare, typename _Allocator>
		friend bool									operator==(const set<_Key, _Compare, _Allocator> &lhs, const set<_Key, _Compare, _Allocator> &rhs);
		template <typename _Key, typename _Compare, typename _Allocator>
		friend bool									operator<(const set<_Key, _Compare, _Allocator> &lhs, const set<_Key, _Compare, _Allocator> &rhs);
	};

	template <typename Key, typename Compare, typename Allocator>
	inline set<Key, Compare, Allocator>::set()
	: tree() { }

	template <typename Key, typename Compare, typename Allocator>
	inline set<Key, Compare, Allocator>::set(const Compare &comp, const Allocator &alloc)
	: tree(comp, alloc) { }

	template <typename Key, typename Compare, typename Allocator>
	template <typename InputIt>
	inline set<Key, Compare, Allocator>::set(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc)
	: tree(comp, alloc) {
		tree.insert(first, last);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline set<Key, Compare, Allocator>::set(const set &other)
	: tree(other.tree){ }

	template <typename Key, typename Compare, typename Allocator>
	inline set<Key, Compare, Allocator>::~set() { }

	template <typename Key, typename Compare, typename Allocator>
	inline set<Key, Compare, Allocator>	&set<Key, Compare, Allocator>::operator=(const set &other) {
		tree = other.tree;
		return (*this);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::allocator_type	set<Key, Compare, Allocator>::get_allocator() const {
		return (allocator_type(tree.get_allocator()));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::size_type set<Key, Compare, Allocator>::count(const Key &key) const {
		return (size_type(tree.find(key) != tree.end()));
	}
	
	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator set<Key, Compare, Allocator>::find(const Key &key) {
		return (tree.find(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_iterator set<Key, Compare, Allocator>::find(const Key &key) const {
		return (tree.find(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator	set<Key, Compare, Allocator>::lower_bound(const Key &key) {
		return (tree.lower_bound(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_iterator	set<Key, Compare, Allocator>::lower_bound(const Key &key) const {
		return (tree.lower_bound(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator set<Key, Compare, Allocator>::upper_bound(const Key &key) {
		return (tree.upper_bound(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_iterator set<Key, Compare, Allocator>::upper_bound(const Key &key) const {
		return (tree.upper_bound(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline ft::pair<typename set<Key, Compare, Allocator>::iterator, typename set<Key, Compare, Allocator>::iterator> set<Key, Compare, Allocator>::equal_range(const Key &key) {
		return (tree.equal_range(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline ft::pair<typename set<Key, Compare, Allocator>::const_iterator, typename set<Key, Compare, Allocator>::const_iterator> set<Key, Compare, Allocator>::equal_range(const Key &key) const {
		return (tree.equal_range(key));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::key_compare	set<Key, Compare, Allocator>::key_comp() const {
		return (tree.key_comp());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::value_compare	set<Key, Compare, Allocator>::value_comp() const {
		return (tree.key_comp());
	}
	
	template <typename Key, typename Compare, typename Allocator>
	inline bool	set<Key, Compare, Allocator>::empty() const {
		return (tree.empty());
	}

	template <typename Key, typename Compare, typename Allocator> 
	inline typename set<Key, Compare, Allocator>::size_type	set<Key, Compare, Allocator>::size() const {
		return (tree.size());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::size_type	set<Key, Compare, Allocator>::max_size() const {
		return (tree.max_size());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline void	set<Key, Compare, Allocator>::clear() {
		tree.clear();
	}

	template <typename Key, typename Compare, typename Allocator>
	inline ft::pair<typename set<Key, Compare, Allocator>::iterator, bool>	set<Key, Compare, Allocator>::insert(const value_type &value) {
		return (tree.insert(value));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator	set<Key, Compare, Allocator>::insert(iterator pos, const value_type &value) {
		return (tree.insert(pos, value));
	}

	template <typename Key, typename Compare, typename Allocator>
	template <class InputIt>
	inline void	set<Key, Compare, Allocator>::insert(InputIt first, InputIt last) {
		tree.insert(first, last);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline void	set<Key, Compare, Allocator>::erase(iterator position) {
		tree.erase(position);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::size_type	set<Key, Compare, Allocator>::erase(const key_type& k) {
		return (tree.erase(k));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline void	set<Key, Compare, Allocator>::erase(iterator first, iterator last) {
		tree.erase(first, last);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline void	set<Key, Compare, Allocator>::swap(set &other) {
		tree.swap(other.tree);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator	set<Key, Compare, Allocator>::begin() {
		return (tree.begin());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_iterator	set<Key, Compare, Allocator>::begin() const {
		return (tree.begin());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::iterator	set<Key, Compare, Allocator>::end() {
		return (tree.end());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_iterator	set<Key, Compare, Allocator>::end() const {
		return (tree.end());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::reverse_iterator	set<Key, Compare, Allocator>::rbegin() {
		return (tree.rbegin());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_reverse_iterator	set<Key, Compare, Allocator>::rbegin() const {
		return (tree.rbegin());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::reverse_iterator	set<Key, Compare, Allocator>::rend() {
		return (tree.rend());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline typename set<Key, Compare, Allocator>::const_reverse_iterator	set<Key, Compare, Allocator>::rend() const {
		return (tree.rend());
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator==(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (lhs.tree == rhs.tree);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator!=(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator<(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (lhs.tree < rhs.tree);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator<=(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator>(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (rhs < lhs);
	}

	template <typename Key, typename Compare, typename Allocator>
	inline bool	operator>=(const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs) {
		return (!(lhs < rhs));
	}

	template <typename Key, typename Compare, typename Allocator>
	inline void swap(set<Key, Compare, Allocator> &lhs, set<Key, Compare, Allocator> &rhs) {
		lhs.swap(rhs);		
	}
}
#endif