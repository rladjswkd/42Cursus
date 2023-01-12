#ifndef TREE_HPP
# define TREE_HPP
# include <memory>
# include <stddef.h>
# include "pair.hpp"
# include "iterator.hpp"
# include "algorithm.hpp"
# include "memory.hpp"
namespace ft {

	enum	color_type {red, black};

	struct rb_tree_node_base {
		color_type			color;
		rb_tree_node_base	*upper;
		rb_tree_node_base	*left;
		rb_tree_node_base	*right;
	};
	
	template <typename Value>
	struct rb_tree_node : public rb_tree_node_base {
		Value			value;
	};
	
	template < typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Value> >
	class rb_tree {
		
	public:
		typedef Allocator								allocator_type;
		typedef	Key										key_type;
		typedef	Value									value_type;
		typedef Compare									key_compare;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef bidirectional_iterator					iterator;
		typedef const_bidirectional_iterator			const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef rb_tree_node_base						node_base_type;
		typedef rb_tree_node<Value>						node_type;

	protected:
		rb_tree_node_base	sentinel;	//	this tracks root, leftmost, rightmost
		size_type			node_count;
		Compare				comp;
		KeyOfValue			get_key;
		allocator_type		allocator;

	public:
		rb_tree();
		explicit
		rb_tree(const Compare &comp, const Allocator &alloc);
		rb_tree(const rb_tree &other);
		~rb_tree();

		rb_tree										&operator=(const rb_tree &other) const;
		allocator_type								get_allocator()	const;

		iterator									find(const Key &key);
		const_iterator								find(const Key &key) const;
		iterator									lower_bound(const Key &key);
		const_iterator								lower_bound(const Key &key) const;
		iterator									upper_bound(const Key &key);
		const_iterator								upper_bound(const Key &key) const;
		ft::pair<iterator, iterator>				equal_range(const Key &key);
		ft::pair<const_iterator, const_iterator>	equal_range(const Key &key) const;
		key_compare									key_comp() const;
		bool										empty() const;
		size_type									size() const;
		size_type									max_size() const;
		void										clear();
		iterator									begin();
		const_iterator								begin() const;
		iterator									end();
		const_iterator								end() const;
		reverse_iterator							rbegin();
		const_reverse_iterator						rbegin() const;
		reverse_iterator							rend();
		const_reverse_iterator						rend() const;
		ft::pair<iterator, bool>					insert(const value_type &value);
		iterator									insert(iterator pos, const value_type &value);
		template <class InputIt>
		void 										insert(InputIt first, InputIt last);
		void 										erase(iterator position);
		size_type 									erase(const key_type& k);
		void 										erase(iterator first, iterator last);
		void										swap(rb_tree &other);
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::allocator_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::get_allocator() const {
		return (allocator);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::find(const Key &key)
	{
		node_type	*cur = sentinel.upper;
		node_type	*bound = &sentinel;
		while (cur) {
			if (!comp(get_key(cur->value), key)) {
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}	//	after this while statement, bound is equal to &sentinel or smallest node among nodes whose values are bigger than or equal to key
		if (comp(key, get_key(bound->value)))
			return (iterator(&sentinel));
		return (iterator(bound));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::find(const Key &key) const {
		node_type	*cur = sentinel.upper;
		node_type	*bound = &sentinel;
		while (cur) {
			if (!comp(get_key(cur->value), key)) {
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
		if (comp(key, get_key(bound->value)))
			return (const_iterator(&sentinel));
		return (const_iterator(bound));	
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::key_compare rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::key_comp() const {
		return (key_compare());
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::empty() const {
		return (node_count == 0);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size() const {
		return (node_count);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() {
		return (iterator(sentinel.left));	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() const {
		return (const_iterator(sentinel.left));	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() {
		return (iterator(&sentinel));	// it should be done in O(1)	//	next to rightmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() const {
		return (const_iterator(&sentinel));	// it should be done in O(1)	//	next to rightmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rbegin() {
		return (reverse_iterator(begin()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rbegin() const {
		return (const_reverse_iterator(begin()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rend() {
		return (reverse_iterator(end()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rend() const {
		return (const_reverse_iterator(end()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator==(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator!=(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (!(lhs == rhs));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator<(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator<=(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (!(rhs < lhs));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator>(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (rhs < lhs);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator>=(const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &lhs, const rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rhs) {
		return (!(lhs < rhs));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::lower_bound(const Key &key)
	{
		node_type	*cur = sentinel.upper;	//	root
		node_type	*bound = &sentinel;
		while (cur) {
			if (!comp(get_key(cur->value), key)) {	//	key must be before cur
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
		return (iterator(bound));
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::lower_bound(const Key & key) const {
		node_type	*cur = sentinel.upper;
		node_type	*bound = &sentinel;
		while (cur) {
			if (!comp(get_key(cur->value), key)) {
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
		return (const_iterator(bound));	
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::upper_bound(const Key &key) {
		node_type	*cur = sentinel.upper;
		node_type	*bound = &sentinel;
		while (cur) {
			if (comp(key, get_key(cur->value))) {
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
		return (iterator(bound));	
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::upper_bound(const Key &key) const {
		node_type	*cur = sentinel.upper;
		node_type	*bound = &sentinel;
		while (cur) {
			if (comp(key, get_key(cur->value))) {
				bound = cur;
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
		return (const_iterator(bound));	
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator, typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::equal_range(const Key &key) {
		const iterator lbound = lower_bound(key);
		if((lbound == &sentinel) || compare(key, get_key(*lbound)))
			return (ft::pair<iterator, iterator>(lbound, lbound));
		iterator rbound = lbound;
		return ft::pair<iterator, iterator>(lbound, ++rbound);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator, typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::equal_range(const Key &key) const {
		const const_iterator lbound = lower_bound(key);
		if((lbound == &sentinel) || compare(key, get_key(*lbound)))
			return (ft::pair<const_iterator, const_iterator>(lbound, lbound));
		const_iterator rbound = lbound;
		return ft::pair<const_iterator, const_iterator>(lbound, ++rbound);
	}
}
#endif