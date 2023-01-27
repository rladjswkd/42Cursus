#ifndef TREE_HPP
# define TREE_HPP
# include <memory>
# include <stddef.h>
# include <limits>
# include "pair.hpp"
# include "iterator.hpp"
# include "algorithm.hpp"
# include "memory.hpp"

namespace ft {

	enum	color_type {RED, BLACK};

	struct rb_tree_node_base {
		color_type			color;
		rb_tree_node_base	*upper;
		rb_tree_node_base	*left;
		rb_tree_node_base	*right;
	};

	//	these functions are not for the every rb_tree_node_base type objects.
	//	for example, find_leftmost, find_rightmost make sense only for the sentinel node
	//	so define them in tree.cpp.
	rb_tree_node_base	*find_leftmost(const rb_tree_node_base *node);
	rb_tree_node_base	*find_rightmost(const rb_tree_node_base *node);
	rb_tree_node_base	*do_increase(const rb_tree_node_base *node);
	rb_tree_node_base	*do_decrease(const rb_tree_node_base *node);
	void				recolor(rb_tree_node_base *node, rb_tree_node_base *temp, rb_tree_node_base *double_upper);
	void				rotate_left(rb_tree_node_base *node, rb_tree_node_base *&root);
	void				rotate_right(rb_tree_node_base *node, rb_tree_node_base *&root);
	void				insert_rebalance(rb_tree_node_base *node, rb_tree_node_base *upper, rb_tree_node_base *sentinel, bool left_flag);
	rb_tree_node_base	*rebalance_for_erase(rb_tree_node_base *target, rb_tree_node_base &sentinel);

	template <typename Value>
	struct rb_tree_node : public rb_tree_node_base {
		Value			value;
	};


	template <typename T>
	struct bidirectional_iterator {
		typedef T 							value_type;
		typedef T*		 					pointer;
		typedef T&							reference;
		typedef rb_tree_node_base			node_base_type;
		typedef	rb_tree_node<value_type>	node_type;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t					difference_type;
		typedef size_t						size_type;

		node_base_type	*it;

		bidirectional_iterator();
		explicit bidirectional_iterator(const node_base_type* node_base);
		~bidirectional_iterator();

		bidirectional_iterator&	operator=(const bidirectional_iterator &other);
		reference				operator*() const;
		pointer					operator->() const;
		bidirectional_iterator&	operator++();
		bidirectional_iterator	operator++(int);
		bidirectional_iterator&	operator--();
		bidirectional_iterator	operator--(int);
	};

	template <typename T>
	struct const_bidirectional_iterator {
		typedef T 							value_type;
		typedef const T* 					pointer;
		typedef const T&					reference;
		typedef rb_tree_node_base			node_base_type;
		typedef	rb_tree_node<value_type>	node_type;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t					difference_type;
		typedef size_t						size_type;

		typedef bidirectional_iterator<T>	iterator;

		const node_base_type	*it;

		const_bidirectional_iterator();
		explicit const_bidirectional_iterator(const node_base_type* node_base);
		const_bidirectional_iterator(const iterator &other);
		~const_bidirectional_iterator();

		const_bidirectional_iterator&	operator=(const const_bidirectional_iterator &other);
		reference						operator*() const;
		pointer							operator->() const;
		const_bidirectional_iterator&	operator++();
		const_bidirectional_iterator	operator++(int);
		const_bidirectional_iterator&	operator--();
		const_bidirectional_iterator	operator--(int);
	};
	

	template < typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Value> >
	class rb_tree {
		
	public:
		typedef Allocator													allocator_type;
		typedef	Key															key_type;
		typedef	Value														value_type;
		typedef Compare														key_compare;
		typedef size_t														size_type;
		typedef ptrdiff_t													difference_type;
		typedef bidirectional_iterator<value_type>							iterator;
		typedef const_bidirectional_iterator<value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef rb_tree_node_base											node_base_type;
		typedef rb_tree_node<Value>											node_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;

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

		rb_tree										&operator=(const rb_tree &other); // deep copy
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
		iterator									insert(const_iterator pos, const value_type &value);
		template <class InputIt>
		void 										insert(InputIt first, InputIt last);
		void 										erase(iterator hint);
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
		ft::pair<iterator, bool>					insert_value(const value_type &value);
		ft::pair<node_base_type*, node_base_type*>	get_unique_position(const key_type &key);
		iterator									insert_value_impl(bool left, node_base_type *upper, const key_type &key, const value_type &value);
		iterator									insert_hint(const_iterator hint, const value_type &value);
		ft::pair<node_base_type*, node_base_type*>	get_unique_position_hint(const_iterator hint, const key_type &key);
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree()
	: sentinel(), node_count(), comp(), allocator(), get_key(), node_allocator() {
		sentinel.color = RED;
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree(const Compare &comp, const Allocator &alloc)
	: sentinel(), node_count(), comp(comp), allocator(alloc), get_key(), node_allocator() {
		sentinel.color = RED;
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::rb_tree(const rb_tree &other)
	: sentinel(), node_count(), comp(other.comp), allocator(other.allocator), get_key(), node_allocator(other.node_allocator) {
		if (other.sentinel.upper) {
			sentinel.upper = copy_subtree(static_cast<const node_type*>(other.sentinel.upper), &sentinel);
			sentinel.left = find_leftmost(sentinel.upper);
			sentinel.right = find_rightmost(sentinel.upper);
			sentinel.color = other.sentinel.color;
			node_count = other.node_count;
		} else {
			sentinel.color = RED;
			reset_sentinel_and_count();
		}
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::~rb_tree() {
		remove_all(static_cast<node_type*>(sentinel.upper));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator> &rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::operator=(const rb_tree &other) {
		if (this != &other) {
			clear();
			comp = other.comp;
			if (other.sentinel.upper) {	// conversion to node_type* is needed because we should copy it's value.
				sentinel.upper = copy_subtree(static_cast<const node_type*>(other.sentinel.upper), &sentinel);
				sentinel.left = find_leftmost(sentinel.upper);
				sentinel.right = find_rightmost(sentinel.upper);
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
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::max_size() const {
		// return (ft::min<size_type>(std::numeric_limits<difference_type>::max() / sizeof(node_type), this->node_allocator.max_size()));
		return (ft::min<size_type>(std::numeric_limits<difference_type>::max(), node_allocator.max_size()));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::clear() {
		remove_all(static_cast<node_type*>(sentinel.upper));
		reset_sentinel_and_count();
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() {
		return (iterator(sentinel.left));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::begin() const {
		return (const_iterator(sentinel.left));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() {
		return (iterator(&sentinel));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::end() const {
		return (const_iterator(&sentinel));
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
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator, bool> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert(const value_type &value) {
		return (insert_value(value));		
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert(const_iterator pos, const value_type &value) {
		return (insert_hint(pos, value));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::erase(iterator hint) {
		node_type	*node = static_cast<node_type*>(rebalance_for_erase(hint.it, sentinel));
		allocator.destroy(&(node->value));
		node_allocator.deallocate(node, 1);
		--node_count;
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::size_type rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::erase(const key_type &k) {
		ft::pair<iterator, iterator>	p = equal_range(k);
		const size_type					old_size = size();
		erase(p.first, p.second);
		return (old_size - size());
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::erase(iterator first, iterator last) {
		if (first == begin() && last == end())
			clear();
		else
			while (first != last)
				erase(first++);
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
		node_type	*cur = static_cast<node_type*>(sentinel.upper);
		node_type	*bound = static_cast<node_type*>(&sentinel);
		while (cur) {
			if (!comp(get_key(cur->value), key)) {	//	key must be before cur
				bound = cur;
				cur = static_cast<node_type*>(cur->left);
			}
			else
				cur = static_cast<node_type*>(cur->right);
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
				cur = static_cast<node_type*>(cur->left);
			}
			else
				cur = static_cast<node_type*>(cur->right);
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
		if ((lbound.it == &sentinel) || comp(key, get_key(static_cast<node_type*>(lbound.it)->value)))
			return (ft::pair<iterator, iterator>(lbound, lbound));
		iterator rbound = lbound;
		return ft::pair<iterator, iterator>(lbound, ++rbound);
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator, typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::const_iterator> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::equal_range(const Key &key) const {
		const const_iterator lbound = lower_bound(key);
		if((lbound == &sentinel) || comp(key, get_key(*lbound)))
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
			sentinel.upper->upper = &sentinel;					//	before this statement, lhs.upper->upper is &rhs
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
			remove_all(static_cast<node_type*>(cur->left));
			right = static_cast<node_type*>(cur->right);
			allocator.destroy(&(cur->value));
			node_allocator.deallocate(cur, 1);
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
	template <class InputIt>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert(InputIt first, InputIt last) {
		for (; first != last; ++first)
			insert_hint(end(), *first);
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
				copy_target = static_cast<node_type*>(copy_target->left);
				upper = cur_left;
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
		construct_value(*created, value);
		return (created);
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::allocate_node() {
		return (node_allocator.allocate(sizeof(node_type)));
	}
	
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::construct_value(node_type &node, const value_type &value) {
		try {
			allocator.construct(&(node.value), value);
		} catch (...) {
			node_allocator.deallocate(&node, 1);
			throw ;
		}
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator, bool> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert_value(const value_type &value) {
		key_type									key = get_key(value);
		ft::pair<node_base_type*, node_base_type*>	res = get_unique_position(key);
		if (res.second) 																		//	if we found insertion position
			return (ft::pair<iterator, bool>(insert_value_impl((res.first != 0), res.second, key, value), true));
		return (ft::pair<iterator, bool>(iterator(res.first), false));
	}
 
//	pair's first is a pointer for the value which have the same key. And in that case, pair's second will be null
//	pair's second is a pointer for the hint to insert the key.
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_base_type *, typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_base_type *> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::get_unique_position(const key_type &key) {
		node_type		*cur = static_cast<node_type*>(sentinel.upper);
		node_base_type	*lower_bound = &sentinel;										//	we need to find lower_bound beecause we have to check equality too.
		bool 			is_before = true;
		while (cur) {																	//	basically, we insert new node to "left" because cur will be null (if return value's left is non-null, new node should be inserted into left, otherwise, right.)
			lower_bound = cur;
			is_before = comp(key, get_key(cur->value));
			if (is_before)
				cur = static_cast<node_type*>(cur->left);								//	if this while ends with this line, key "goes before" cur->value's key
			else
				cur = static_cast<node_type*>(cur->right);								//	if this while ends with this line, key "goes after" cur->value's key or "equivalent to" it
		}
		node_base_type	*temp_lower_bound = lower_bound;
		if (is_before) {																//	here, key "goes before" lower_bound(previous cur)
			if (lower_bound == sentinel.left)											//	if lower_bound is leftmost, lower_bound is the hint we are looking for
				return (ft::pair<node_base_type*, node_base_type*>(cur, lower_bound));	//	new node should be inserted into left of lower_bound 
			else																		//	decrease lower_bound by one so make key "to go after or equivalent to" lower_bound(previous cur)
				temp_lower_bound = ft::do_decrease(temp_lower_bound);
		}
		if (comp(get_key(static_cast<node_type*>(temp_lower_bound)->value), key))		//	at this point, key "goes after or equivalent to" lower_bound. so if this is true, key "goes after" lower_bound.
			return (ft::pair<node_base_type*, node_base_type*>(cur, lower_bound));		//	new node should be inserted into right of lower_bound
		return (ft::pair<node_base_type*, node_base_type*>(temp_lower_bound, 0));			//	lower_bound is the position where the same key is.
	}

	// EASTL implementation.
	// upper is used to save original lbound
	// template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	// inline rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_base_type *rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::get_unique_position(const key_type &key, bool &insert_flag) {
	// 	node_type		*current = static_cast<node_type*>(sentinel.upper);
	// 	node_base_type	*lbound = &sentinel;
	// 	node_type		*upper;
	// 	bool			before = true;
	// 	while (current) {
	// 		lbound = current;
	// 		before = comp(key, get_key(current->value));
	// 		if (before)
	// 			current = static_cast<node_type*>(current->left);
	// 		else
	// 			current = static_cast<node_type*>(current->right);
	// 	}
	// 	upper = lbound;	//	to return lbound, hint we found to insert, save its' value to upper and return it when proper
	// 	if (before) {
	// 		if (lbound == sentinel.left) {
	// 			insert_flag = true;
	// 			return (lbound);
	// 		}
	// 		else
	// 			lbound = do_decrease(lbound);
	// 	}
	// 	if(comp(get_key(static_cast<node_type*>(lbound)->value), key)) {
	// 		insert_flag = true;
	// 		return (upper);	//	the value we found (original lbound). there is no problem if we return lbound, not upper.
	// 	}
	// 	insert_flag = false;
	// 	return (lbound);
	// }

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert_value_impl(bool left, node_base_type *upper, const key_type &key, const value_type &value) {
		bool		left_flag = left 
						|| (upper == &sentinel)
						|| comp(key, get_key(static_cast<node_type*>(upper)->value));
		node_type	*node = create_node(value);
		insert_rebalance(node, upper, &sentinel, left_flag);
		node_count++;
		return (iterator(node));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::iterator rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::insert_hint(const_iterator hint, const value_type &value) {
		key_type									key = get_key(value);
		ft::pair<node_base_type*, node_base_type*>	res = get_unique_position_hint(hint, key);
		if (res.second)
			return (insert_value_impl((res.first != 0), res.second, key, value));
		return (iterator(res.first));
	}

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline ft::pair<typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_base_type *, typename rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::node_base_type *> rb_tree<Key, Value, KeyOfValue, Compare, Allocator>::get_unique_position_hint(const_iterator hint, const key_type &key) {
		iterator pos(hint.it);
		if (pos.it == &sentinel) {																		//	pos is end()
			if (node_count > 0 && comp(get_key(static_cast<node_type*>(sentinel.right)->value), key))	//	tree is not empty && key is "after" rightmost
				return (ft::pair<node_base_type*, node_base_type*>(0, sentinel.right));
			else
				return (get_unique_position(key));														//	it is not appropriate to insert new node into position after hint. so we have to find new position
		}
		else if (comp(key, get_key(static_cast<node_type*>(pos.it)->value))) {							//	if key is "before" hint
			iterator before = pos;
			if (pos.it == sentinel.left)																//	if key is "before" hint && hint is leftmost
				return (ft::pair<node_base_type*, node_base_type*>(sentinel.left, sentinel.left));		//	first sentinel.left means key should be inserted into "left" of sentinel.left
			else if (comp(get_key(static_cast<node_type*>((--before).it)->value), key)) {
				if (before.it->right == 0)																//	if key is "before" hint && key is "after" node "right before" hint && the node's right is null
					return (ft::pair<node_base_type*, node_base_type*>(0, before.it));
				else																					//	if key is "before" hint && key is "after" node "right before" hint && the node's right is not null
					return (ft::pair<node_base_type*, node_base_type*>(pos.it, pos.it));
			}
			else																						//	key is even before the node which is before hint
				return (get_unique_position(key));
		}
		else if (comp(get_key(static_cast<node_type*>(pos.it)->value), key)) {							//	if key is "after" hint and same process applies
			iterator after = pos;
			if (pos.it == sentinel.right)
				return (ft::pair<node_base_type*, node_base_type*>(0, sentinel.right));
			else if (comp(key, get_key(static_cast<node_type*>((++after).it)->value))) {
				if (pos.it->right == 0)
					return (ft::pair<node_base_type*, node_base_type*>(0, pos.it));
				else
					return (ft::pair<node_base_type*, node_base_type*>(after.it, after.it));
			}
			else
				return (get_unique_position(key));
		}
		else																							//	node that has same key does already exist
			return (ft::pair<node_base_type*, node_base_type*>(pos.it, 0));
	}

	template <typename T>
	inline bidirectional_iterator<T>::bidirectional_iterator()
	: it() { }

	template <typename T>
	inline bidirectional_iterator<T>::bidirectional_iterator(const node_base_type *node_base)
	: it(const_cast<node_base_type*>(node_base)) { }

	template <typename T>
	inline bidirectional_iterator<T>::~bidirectional_iterator()
	{ }
	
	template <typename T>
	inline bidirectional_iterator<T> &bidirectional_iterator<T>::operator=(const bidirectional_iterator &other) {
		it = other.it;
		return (*this);
	}

	template <typename T>
	inline typename bidirectional_iterator<T>::reference bidirectional_iterator<T>::operator*() const {
		return (static_cast<node_type *>(it)->value);
	}
	
	template <typename T>
	inline typename bidirectional_iterator<T>::pointer bidirectional_iterator<T>::operator->() const {
		return (&(static_cast<node_type *>(it)->value));
	}

	template <typename T>
	inline bidirectional_iterator<T> &bidirectional_iterator<T>::operator++() {
		it = ft::do_increase(it);
		return (*this);
	}
	
	template <typename T>
	inline bidirectional_iterator<T> bidirectional_iterator<T>::operator++(int) {
		bidirectional_iterator	temp = *this;
		it = ft::do_increase(it);
		return (temp);
	}
	
	template <typename T>
	inline bidirectional_iterator<T> &bidirectional_iterator<T>::operator--() {
		it = ft::do_decrease(it);
		return (*this);
	}
	
	template <typename T>
	inline bidirectional_iterator<T> bidirectional_iterator<T>::operator--(int) {
		bidirectional_iterator	temp = *this;
		it = ft::do_decrease(it);
		return (temp);
	}

	template <typename T>
	inline bool	operator==(const bidirectional_iterator<T> &lhs, const bidirectional_iterator<T> &rhs) {
		return (lhs.it == rhs.it);
	}

	template <typename T>
	inline bool	operator!=(const bidirectional_iterator<T> &lhs, const bidirectional_iterator<T> &rhs) {
		return (lhs.it != rhs.it);
	}

	template <typename T>
	inline const_bidirectional_iterator<T>::const_bidirectional_iterator()
	: it() { }

	template <typename T>
	inline const_bidirectional_iterator<T>::const_bidirectional_iterator(const node_base_type *node_base)
	: it(const_cast<node_base_type*>(node_base)) { }

	//	this is for conversion from bidirectional_iterator to const_bidirectional_iterator.
	//	we use this when, for example, insert_hint's first argument is non-const iterator
	template <typename T>
	inline const_bidirectional_iterator<T>::const_bidirectional_iterator(const iterator &other)
	: it(other.it) { }

	template <typename T>
	inline const_bidirectional_iterator<T>::~const_bidirectional_iterator()
	{ }
	
	template <typename T>
	inline const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator=(const const_bidirectional_iterator &other) {
		it = other.it;
		return (*this);
	}

	template <typename T>
	inline typename const_bidirectional_iterator<T>::reference const_bidirectional_iterator<T>::operator*() const {
		return (static_cast<const node_type *>(it)->value);
	}
	
	template <typename T>
	inline typename const_bidirectional_iterator<T>::pointer const_bidirectional_iterator<T>::operator->() const {
		return (&(static_cast<const node_type*>(it)->value));
	}

	template <typename T>
	inline const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator++() {
		it = ft::do_increase(it);
		return (*this);
	}
	
	template <typename T>
	inline const_bidirectional_iterator<T> const_bidirectional_iterator<T>::operator++(int) {
		const_bidirectional_iterator	temp = *this;
		it = ft::do_increase(it);
		return (temp);
	}
	
	template <typename T>
	inline const_bidirectional_iterator<T> &const_bidirectional_iterator<T>::operator--() {
		it = ft::do_decrease(it);
		return (*this);
	}
	
	template <typename T>
	inline const_bidirectional_iterator<T> const_bidirectional_iterator<T>::operator--(int) {
		const_bidirectional_iterator	temp = *this;
		it = ft::do_decrease(it);
		return (temp);
	}

	template <typename T>
	inline bool	operator==(const const_bidirectional_iterator<T> &lhs, const const_bidirectional_iterator<T> &rhs) {
		return (lhs.it == rhs.it);
	}

	template <typename T>
	inline bool	operator!=(const const_bidirectional_iterator<T> &lhs, const const_bidirectional_iterator<T> &rhs) {
		return (lhs.it != rhs.it);
	}
}
#endif