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
}
