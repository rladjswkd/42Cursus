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

	void insert_balance(rb_tree_node_base *node, rb_tree_node_base *upper, rb_tree_node_base *sentinel, bool left_flag) {
		rb_tree_node_base	*&root = sentinel->upper;

		node->upper = upper;
		node->right = NULL;
		node->left = NULL;
		node->color = red;

		if (left_flag) {
			upper->left = node;
			if (upper == sentinel) {									//	tree is empty before this insertion
				sentinel->upper = node;
				sentinel->right = node;
			}
			else if (upper == sentinel->left)
				sentinel->left = node;									//	update sentinel info
		}
		else {
			upper->right = node;
			if (upper == sentinel->right)
				sentinel->right = node;									//	update sentinel info
		}
		// if node is root, this tree is empty before this insertion
		// if node->upper->color is black, red property is not violated
		while ((node != root) && (node->upper->color == red)) {
			rb_tree_node_base	*double_upper = node->upper->upper;
			if (node->upper == double_upper->left) {					//	if node->upper is node->upper->upper's left
				rb_tree_node_base	*temp = double_upper->right;		//	sibling of node->upper
				if (temp && (temp->color == red)) {
					recolor(node, temp, double_upper);
					node = double_upper;
				}
				else {													//	temp is black node or null
					if (node == node->upper->right) {
						node = node->upper;
						rotate_left(node, root);
					}
					node->upper->color = black;
					double_upper->color = red;
					rotate_right(double_upper, root);
				}
			}
			else {														//	if node->upper is node->upper->upper's right
				rb_tree_node_base	*temp = double_upper->left;			//	sibling of node->upper
				if (temp && (temp->color == red)) {
					recolor(node, temp, double_upper);
					node = double_upper;
				}
				else {													//	temp is black node or null
					if (node == node->upper->left) {
						node = node->upper;
						rotate_right(node, root);						//	after this, node will be node->right
					}
					node->upper->color = black;
					double_upper->color = red;
					rotate_left(double_upper, root);
				}
			}
		}
		root->color = black;
	}

	void recolor(rb_tree_node_base *node, rb_tree_node_base *temp, rb_tree_node_base *double_upper) {
		node->upper->color = black;
		temp->color = black;
		double_upper->color = red;
	}

	void rotate_left(rb_tree_node_base *node, rb_tree_node_base *&root)
	{
		rb_tree_node_base* const rotated_upper = node->right;
		node->right = rotated_upper->left;
		if (rotated_upper->left)
			rotated_upper->left->upper = node;
		rotated_upper->upper = node->upper;
		if (node == root)
			root = rotated_upper;
		else if (node == node->upper->left)
			node->upper->left = rotated_upper;
		else
			node->upper->right = rotated_upper;
		rotated_upper->left = node;
		node->upper = rotated_upper;
	}

	void rotate_right(rb_tree_node_base *node, rb_tree_node_base *&root) {
		rb_tree_node_base* const rotated_upper = node->left;
		node->left = rotated_upper->right;
		if (rotated_upper->right)
			rotated_upper->right->upper = node;
		rotated_upper->upper = node->upper;
		if (node == root)
			root = rotated_upper;
		else if (node == node->upper->right)
			node->upper->right = rotated_upper;
		else
			node->upper->left = rotated_upper;
		rotated_upper->right = node;
		node->upper = rotated_upper;
	}
}
