#include "tree.hpp"

namespace ft {
	rb_tree_node_base *find_leftmost(const rb_tree_node_base *node) {
		while (node->left)
			node = node->left;
		return (const_cast<rb_tree_node_base*>(node));
	}

	rb_tree_node_base *find_rightmost(const rb_tree_node_base *node) {
		while (node->right)
			node = node->right;
		return (const_cast<rb_tree_node_base*>(node));
	}

	rb_tree_node_base *do_increase(rb_tree_node_base *node) {
		if (node->right)  {
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
		return (node);
	}


	const rb_tree_node_base	*do_increase(const rb_tree_node_base *node) {
		return (do_increase(const_cast<rb_tree_node_base*>(node)));
	}


	rb_tree_node_base *do_decrease(rb_tree_node_base *node) {
		if ((node->upper->upper == node) && (node->color == RED))	//	node is &sentinel, so rightmost is returned.
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
		return (const_cast<rb_tree_node_base*>(temp));
	}


	const rb_tree_node_base *do_decrease(const rb_tree_node_base *node) {
		return (do_decrease(const_cast<rb_tree_node_base*>(node)));
	}


	void recolor(rb_tree_node_base *node, rb_tree_node_base *temp, rb_tree_node_base *double_upper) {
		node->upper->color = BLACK;
		temp->color = BLACK;
		double_upper->color = RED;
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

	void insert_rebalance(rb_tree_node_base *node, rb_tree_node_base *upper, rb_tree_node_base *sentinel, bool left_flag) {
		rb_tree_node_base	*&root = sentinel->upper;

		node->upper = upper;
		node->right = NULL;
		node->left = NULL;
		node->color = RED;

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
		// if node->upper->color is BLACK, RED property is not violated
		while ((node != root) && (node->upper->color == RED)) {
			rb_tree_node_base	*double_upper = node->upper->upper;
			if (node->upper == double_upper->left) {					//	if node->upper is node->upper->upper's left
				rb_tree_node_base	*temp = double_upper->right;		//	sibling of node->upper
				if (temp && (temp->color == RED)) {
					recolor(node, temp, double_upper);
					node = double_upper;
				}
				else {													//	temp is BLACK node or null
					if (node == node->upper->right) {
						node = node->upper;
						rotate_left(node, root);
					}
					node->upper->color = BLACK;
					double_upper->color = RED;
					rotate_right(double_upper, root);
				}
			}
			else {														//	if node->upper is node->upper->upper's right
				rb_tree_node_base	*temp = double_upper->left;			//	sibling of node->upper
				if (temp && (temp->color == RED)) {
					recolor(node, temp, double_upper);
					node = double_upper;
				}
				else {													//	temp is BLACK node or null
					if (node == node->upper->left) {
						node = node->upper;
						rotate_right(node, root);						//	after this, node will be node->right
					}
					node->upper->color = BLACK;
					double_upper->color = RED;
					rotate_left(double_upper, root);
				}
			}
		}
		root->color = BLACK;
	}

	rb_tree_node_base *rebalance_for_erase(rb_tree_node_base *target, rb_tree_node_base &sentinel) {
		rb_tree_node_base	*&root = sentinel.upper;
		rb_tree_node_base	*&leftmost = sentinel.left;
		rb_tree_node_base	*&rightmost = sentinel.right;
		rb_tree_node_base	*v = target;
		rb_tree_node_base	*u = 0;
		rb_tree_node_base	*u_upper = 0;

		if (v->left == 0)											//	target has no lower nodes (then v->right is null) or has right lower node.
			u = v->right;
		else if (v->right == 0)										//	target has only left lower node
			u = v->left;
		else {														//	target has two lower nodes.
			v = v->right;
			while (v->left != 0)									//	after this while, v will be the node "right after" target (successor)
				v = v->left;
			u = v->right;											//	v->left is null after the while statement, so assign v->right to u. v->right might be either a exisiting node or null (if v has no lower nodes)
		}
	// disconnecting target from tree. if you draw tree's structure, it becomes easy to understand
		if (v != target) {											//	this means target has two lower nodes.
			target->left->upper = v;								//	relink target's left lower node to v
			v->left = target->left;
			if (v != target->right) {
				u_upper = v->upper;
				if (u)
					u->upper = v->upper;
				v->upper->left = u;
				v->right = target->right;
				target->right->upper = v;
			}
			else													//	if v == target->right and the v is the only lower node of target
				u_upper = v;
			if (root == target)										//	target can be root or left or right lower node of a node
				root = v;
			else if (target->upper->left == target)					//	target can be root or left or right lower node of a node
				target->upper->left = v;
			else													//	target can be root or left or right lower node of a node
				target->upper->right = v;
			v->upper = target->upper;
																	//	now target is disconnected from this tree
			//	swap color of target and v for black height
			color_type	temp_v = v->color;
			v->color = target->color;
			target->color = temp_v;

			v = target;												//	now v points to the node to be actually deleted
		}
		else {														//	if v == target and u will be the replacement node for target
			u_upper = v->upper;
			if (u)
				u->upper = v->upper;
			if (target == root)
				root = u;
			else if (target->upper->left == target)
				target->upper->left = u;
			else
				target->upper->right = u;
																	//	now target is disconnected from this tree
			if (target == leftmost) {								//	reset leftmost. target->left must be null
				if (target->right && u)
					leftmost = find_leftmost(u);
				else
					leftmost = target->upper;
			}
			if (target == rightmost) {								//	reset rightmost. target->right must be null
				if (target->left && u)
					rightmost = find_rightmost(u);
				else
					rightmost = target->upper;
			}
		}
	//	rebalancing
		if (v->color != RED) {
			while (u != root && (u == 0 || u->color != RED)) {		//	u == 0 means that u is null node and its color is black
				if (u == u_upper->left) {							//	this branching is for getting proper sibling node of u
					rb_tree_node_base	*s = u_upper->right;		//	s is right lower node of its upper node. "RIGHT"
					if (s->color == RED) {
						s->color = BLACK;
						u_upper->color = RED;
						rotate_left(u_upper, root);
						s = u_upper->right;							//	assign new sibling node in restructured tree into s
					}												//	s is BLACK from here
					//	s is black and its siblings are black
					if ((s->left == 0 || s->left->color == BLACK) && (s->right == 0 || s->right->color == BLACK)) {
						s->color = RED;								//	recolor s from BLACK to RED
						u = u_upper;								//	call recursively this function for u's upper node
						u_upper = u_upper->upper;					
					}
					else {											//	one of the s' lower nodes is RED
						if (s->right == 0 || s->right->color == BLACK) {	//	the red node is s' left lower node "LEFT"
							s->left->color = BLACK;
							s->color = RED;
							rotate_right(s, root);
							s = u_upper->right;
						}
						s->color = u_upper->color;					//	"RIGHT LEFT" and "RIGHT RIGHT"
						u_upper->color = BLACK;
						if (s->right)
							s->right->color = BLACK;
						rotate_left(u_upper, root);
						break;
					}
				}
				else {												//	same process for u == u_upper->right
					rb_tree_node_base	*s = u_upper->left;
					if (s->color == RED) {
						s->color = BLACK;
						u_upper->color = RED;
						rotate_right(u_upper, root);
						s = u_upper->left;
					}
					if ((s->right == 0 || s->right->color == BLACK) && (s->left == 0 || s->left->color == BLACK)) {
						s->color = RED;
						u = u_upper;
						u_upper = u_upper->upper;
					}
					else {
						if (s->left == 0 || s->left->color == BLACK) {
							s->right->color = BLACK;
							s->color = RED;
							rotate_left(s, root);
							s = u_upper->left;
						}
						s->color = u_upper->color;
						u_upper->color = BLACK;
						if (s->left)
							s->left->color = BLACK;
						rotate_right(u_upper, root);
						break;
					}
				}
			}
			if (u)													//	lastly, make current u to be BLACK
				u->color = BLACK;
		}
		return (v);													//	return node to be actually deleted
	}
}
