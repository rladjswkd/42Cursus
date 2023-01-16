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

	rb_tree_node_base	*leftmost_base(const rb_tree_node_base *node);
	rb_tree_node_base	*rightmost_base(const rb_tree_node_base *node);	
	rb_tree_node_base	*increase_base(const rb_tree_node_base *node);
	rb_tree_node_base	*decrease_base(const rb_tree_node_base *node);

	template <typename Value>
	struct rb_tree_node : public rb_tree_node_base {
		Value			value;
	};

	template <typename T, typename Pointer, typename Reference>
	struct bidirectional_iterator {
		typedef T 							value_type;
		typedef Pointer 					pointer;
		typedef Reference					reference;
		typedef rb_tree_node_base			node_base_type;
		typedef	rb_tree_node<value_type>	node_type;
		typedef bidirectional_iterator_tag	iterator_category;
		
		node_base_type	*it;

		bidirectional_iterator();
		explicit bidirectional_iterator(const node_base_type* node_base);
		bidirectional_iterator(const bidirectional_iterator &other);
		~bidirectional_iterator();

		bidirectional_iterator&	operator=(const bidirectional_iterator &other);
		reference				operator*() const;
		pointer					operator->() const;
		bidirectional_iterator&	operator++();
		bidirectional_iterator	operator++(int);
		bidirectional_iterator&	operator--();
		bidirectional_iterator	operator--(int);
	};
	
	
	template < typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Value> >
	class rb_tree {
		
	public:
		typedef Allocator																	allocator_type;
		typedef	Key																			key_type;
		typedef	Value																		value_type;
		typedef Compare																		key_compare;
		typedef size_t																		size_type;
		typedef ptrdiff_t																	difference_type;
		typedef bidirectional_iterator<value_type, value_type*, value_type&>				iterator;
		typedef bidirectional_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef ft::reverse_iterator<iterator>												reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;
		typedef rb_tree_node_base															node_base_type;
		typedef rb_tree_node<Value>															node_type;
		typedef typename allocator_type::template rebind<node_type>::other					node_allocator_type;

	private:
		rb_tree_node_base	sentinel;	//	this tracks root, leftmost, rightmost
		size_type			node_count;
		Compare				comp;
		KeyOfValue			get_key;
		allocator_type		allocator;
		node_allocator_type	node_allocator;

	public:
		rb_tree();
		explicit rb_tree(const Compare &comp, const Allocator &alloc);
		rb_tree(const rb_tree &other);
		~rb_tree();

		rb_tree										&operator=(const rb_tree &other) const; // deep copy
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
		void										remove_all(node_type *cur);
		void										reset_sentinel_and_count();
		void										take_data_from(rb_tree &other);
		template <typename T>
		void										swap_data(T &lhs, T &rhs);
		node_type									*copy_subtree(const node_type *copy_target, node_base_type *upper);
		node_type									*create_node(const node_type *copy_target, node_base_type *upper);
		node_type									*create_node(const value_type &value);
		node_type									*allocate_node();
		void										construct_value(node_type &node, const value_type &value);
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree()
	: sentinel(), node_count(), comp(), allocator(), get_key(), node_allocator() {
		sentinel.color = red;
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree(const Compare &comp, const Allocator &alloc)
	: sentinel(), node_count(), comp(comp), allocator(alloc), get_key(), node_allocator() {
		sentinel.color = red;
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree(const rb_tree &other)
	: sentinel(), node_count(), comp(other.comp), allocator(other.allocator), get_key(), node_allocator(other.node_allocator) {
		if (other.sentinel.upper) {
			sentinel.upper = copy_subtree(static_cast<const node_type*>(other.sentinel.upper), &sentinel);
			sentinel.left = leftmost_base(sentinel.upper);
			sentinel.right = rightmost_base(sentinel.upper);
			sentinel.color = other.sentinel.color;
			node_count = other.node_count;
		} else {
			sentilen.color = red;
			reset_sentinel_and_count();
		}
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::~rb_tree() {
		remove_all(sentinel.upper);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::operator=(const rb_tree &other) const {
		if (this != &other) {
			clear();
			comp = other.comp;
			if (other.sentinel.upper) {	// conversion to node_type* is needed because we should copy it's value.
				sentinel.upper = copy_subtree(static_cast<const node_type*>(other.sentinel.upper), &sentinel);
				sentinel.left = leftmost_base(sentinel.upper);
				sentinel.right = rightmost_base(sentinel.upper);
				node_count = other.node_count;
			}
		}
		return (*this);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::allocator_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::get_allocator() const {
		return (allocator);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::find(const Key &key) {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::find(const Key &key) const {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::key_compare rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::key_comp() const {
		return (key_compare());
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::empty() const {
		return (node_count == 0);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size() const {
		return (node_count);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::clear() {
		remove_all(sentinel.upper);
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() {
		return (iterator(sentinel.left));	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() const {
		return (const_iterator(sentinel.left));	// it should be done in O(1)	//	leftmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() {
		return (iterator(&sentinel));	// it should be done in O(1)	//	next to rightmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() const {
		return (const_iterator(&sentinel));	// it should be done in O(1)	//	next to rightmost value in this container
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rbegin() {
		return (reverse_iterator(begin()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rbegin() const {
		return (const_reverse_iterator(begin()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rend() {
		return (reverse_iterator(end()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_reverse_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rend() const {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::lower_bound(const Key &key) {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::lower_bound(const Key & key) const {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::upper_bound(const Key &key) {
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::upper_bound(const Key &key) const {
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

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::swap(rb_tree &other) {
		if (sentinel.upper && other.sentinel.upper) {
			swap_data(sentinel.upper, other.sentinel.upper);
			swap_data(sentinel.left, other.sentinel.left);
			swap_data(sentinel.right, other.sentinel.right);
			swap_data(node_count, other.node_count);
			sentinel.upper->upper = &sentinel;	//	before this statement, lhs.upper->upper is &rhs
			other.sentinel.upper->upper = &(other.sentinel);	//	same
		}
		else if (sentinel.upper)
			other.take_data_from(*this);
		else
			take_data_from(other);
		swap_data(comp, other.comp);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::remove_all(node_type *cur) {
		node_type	*right;
		while (cur) {
			remove_all(cur->left);
			right = cur->right;
			allocator.destroy(&(cur->value));
			allocator.deallocate(&(cur->value), 1);
			cur = right;
		}
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::reset_sentinel_and_count() {
		sentinel.upper = 0;
		sentinel.left = &sentinel;	//	for iterator functions
		sentinel.right = &sentinel;
		node_count = 0;
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::take_data_from(rb_tree &other) {
		sentinel.color = other.sentinel.color;
		sentinel.upper = other.sentinel.upper;
		sentinel.left = other.sentinel.left;
		sentinel.right = other.sentinel.right;
		// just to represent that there's no upper node for sentinel.upper (root)
		// null is only used for root when there is no nodes in the tree (size() == 0) 
		sentinel.upper->upper = &sentinel;
		node_count = other.node_count;
		other.reset_sentinel_and_count();
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	template <typename T>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::swap_data(T &lhs, T &rhs) {
		T	temp = rhs;
		rhs = lhs;
		lhs = temp;
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::copy_subtree(const node_type *copy_target, node_base_type *upper) {
		node_type	*cur = create_node(copy_target, upper);
		try {
			if(copy_target->right)
				cur->right = copy_subtree(static_cast<const node_type*>(copy_target->right), cur);

			copy_target = static_cast<node_type *>(copy_target->left);
			upper = cur;
			node_type* cur_left;
			while (copy_target) {
				cur_left = create_node(copy_target, upper);
				upper->left = cur_left;
				if(copy_target->right)
					cur_left->right = copy_subtree(static_cast<const node_type*>(copy_target->right), cur_left);
			}
		} catch(...) {
			remove_all(cur);
			throw;
		}
		return (cur);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::create_node(const node_type *copy_target, node_base_type *upper) {
		node_type	*created = create_node(copy_target->value);
		created->right = 0;
		created->left = 0;
		created->upper = upper;
		created->color = copy_target->color;
		return (created);
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::create_node(const value_type &value) {
		node_type	*created = allocate_node();
		construct_value(created, value);
		return (created);
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::allocate_node() {
		return (node_allocator.allocate(sizeof(node_type)));
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::construct_value(node_type &node, const value_type &value) {
		try {
			allocator.construct(&(node->value), value);
		} catch (...) {
			allocator.deallocate(node, 1);
			throw ;
		}
	}
	
	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference>::bidirectional_iterator()
	: it() { }

	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference>::bidirectional_iterator(const node_base_type *node_base)
	: it(node_base) { }

	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference>::bidirectional_iterator(const bidirectional_iterator &other)
	: it(other.it) { }

	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference>::~bidirectional_iterator()
	{ }
	
	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference> &bidirectional_iterator<T, Pointer, Reference>::operator=(const bidirectional_iterator &other) {
		it = other.it;
		return (*this);
	}

	template <typename T, typename Pointer, typename Reference>
	inline typename bidirectional_iterator<T, Pointer, Reference>::reference bidirectional_iterator<T, Pointer, Reference>::operator*() const {
		return (static_cast<node_type *>(it)->value);
	}
	
	template <typename T, typename Pointer, typename Reference>
	inline typename bidirectional_iterator<T, Pointer, Reference>::pointer bidirectional_iterator<T, Pointer, Reference>::operator->() const {
		return (&(static_cast<node_type *>(it)->value));
	}

	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference> &bidirectional_iterator<T, Pointer, Reference>::operator++() {
		it = increase_base(it);
		return (*this);
	}
	
	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference> bidirectional_iterator<T, Pointer, Reference>::operator++(int) {
		bidirectional_iterator	temp = *this;
		it = increase_base(it);
		return (temp);
	}
	
	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference> &bidirectional_iterator<T, Pointer, Reference>::operator--() {
		it = decrease_base(it);
		return (*this);
	}
	
	template <typename T, typename Pointer, typename Reference>
	inline bidirectional_iterator<T, Pointer, Reference> bidirectional_iterator<T, Pointer, Reference>::operator--(int) {
		bidirectional_iterator	temp = *this;
		it = decrease_base(it);
		return (temp);
	}
}
#endif