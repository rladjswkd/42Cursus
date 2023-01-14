#include "tree.hpp"

ft::rb_tree_node_base &ft::rb_tree_node_base::operator=(rb_tree_node_base &other) {
	this->left = other.left;
	this->right = other.right;
	this->upper = other.upper;
	return (*this);
}