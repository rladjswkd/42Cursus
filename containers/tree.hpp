#ifndef TREE_HPP
# define TREE_HPP
# include <memory>
# include <stddef.h>
# include "pair.hpp"
# include "iterator.hpp"
# include "algorithm.hpp"

namespace ft {

	enum	color_type {red = false, black = true};

	template <typename Value>
	struct rb_tree_node {
		color_type		node_color;
		rb_tree_node	*node_upper;
		rb_tree_node	*node_left;
		rb_tree_node	*node_right;
		Value			node_value;
	};

	template <typename Value>
	struct rb_tree_root_left_right_most : public rb_tree_node<Value> {
		rb_tree_node<Value>	*root;
		rb_tree_node<Value>	*leftmost;
		rb_tree_node<Value>	*rightmost;
	};
	
	template < typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Value> >
	class rb_tree {
	private:

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
	
	private:
		rb_tree_root_left_right_most<Value>			tri;
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() {
		return (iterator());	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() const {
		return (const_iterator());	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() {
		return (iterator());	// it should be done in O(1)	//	next to rightmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() const {
		return (const_iterator());	// it should be done in O(1)	//	next to rightmost value in this container
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
}
#endif