#include "tree.hpp"
namespace ft{

	rb_tree_node_base *ft::leftmost_base(const rb_tree_node_base *node) {
		while (node->left)
			node = node->left;
		return (const_cast<rb_tree_node_base *>(node));
	}

	rb_tree_node_base *ft::rightmost_base(const rb_tree_node_base *node) {
		while (node->right)
			node = node->right;
		return (const_cast<rb_tree_node_base *>(node));
	}

	rb_tree_node_base *ft::increase_base(const rb_tree_node_base *node) {
		if(node->right)  {
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else {
			rb_tree_node_base*	temp = node->upper;
			while (node == temp->right) {
				node = temp;
				temp = temp->upper;
			}
			if(node->right != temp)
				node = temp;
		}
		return (const_cast<rb_tree_node_base*>(node));
	}

	rb_tree_node_base *ft::decrease_base(const rb_tree_node_base *node) {
		if ((node->upper->upper == node) && (node->color == red))
			return node->right;
		else if (node->left) {
			rb_tree_node_base* temp = node->left;
			while(temp->right)
				temp = temp->right;
			return (temp);
		}
		rb_tree_node_base* temp = node->upper;
		while (node == temp->left) {
			node     = temp;
			temp = temp->upper;
		}
		return (const_cast<rb_tree_node_base *>(temp));
	}
}
