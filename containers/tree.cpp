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
//	in else statement, node is leaf node.
//	while statement iterates till one of the cases below.
//		1. node == temp->left
//		2. node is root and temp is &sentinel (&sentinel is root->upper, so is (&sentinel)->upper->upper because (&sentinel)->upper is root)
//			or if there is only one node, node is &sentinel and temp is root
//	in case 1., if statement's condition is always true. so temp is returned.
//	in case 2., if there are more than one nodes, if statement is true. else, if statement is false. so in both cases, &sentinel is returned.
		else {
			rb_tree_node_base	*temp = node->upper;
			while (node == temp->right) {
				node = temp;
				temp = temp->upper;
			}
			if (node->right != temp)
				node = temp;
		}
		return (const_cast<rb_tree_node_base*>(node));
	}

	rb_tree_node_base *ft::decrease_base(const rb_tree_node_base *node) {
		if ((node->upper->upper == node) && (node->color == red))	//	node is &sentinel, so rightmost is returned.
			return (node->right);
		else if (node->left) {	//	or node has left lower node, rightmost node from that subtree is returned.
			rb_tree_node_base	*temp = node->left;
			while(temp->right)
				temp = temp->right;
			return (temp);
		}
		rb_tree_node_base	*temp = node->upper;
		while (node == temp->left) {	//	1. find first node that has current "node" as one of it's right subtree components or 2. &sentinel (temp) (case 2 is undefined behavior)
			node = temp;
			temp = temp->upper;
		}
		return (const_cast<rb_tree_node_base *>(temp));
	}

	void rotate_left(rb_tree_node_base *node, rb_tree_node_base *&root) {
		rb_tree_node_base* const rotated_upper = node->right;
		node->right = rotated_upper->left;
		if(rotated_upper->left)
			rotated_upper->left->upper = node;
		rotated_upper->upper = node->upper;
		if(node == root)
			root = rotated_upper;
		else if(node == node->upper->left)
			node->upper->left = rotated_upper;
		else
			node->upper->right = rotated_upper;
		rotated_upper->left = node;
		node->upper = rotated_upper;
	}
	
	void rotate_right(rb_tree_node_base *node, rb_tree_node_base *&root) {
		rb_tree_node_base* const rotated_upper = node->left;
		node->left = rotated_upper->right;
		if(rotated_upper->right)
			rotated_upper->right->upper = node;
		rotated_upper->upper = node->upper;
		if(node == root)
			root = rotated_upper;
		else if(node == node->upper->right)
			node->upper->right = rotated_upper;
		else
			node->upper->left = rotated_upper;
		rotated_upper->right = node;
		node->upper = rotated_upper;
	}
}
