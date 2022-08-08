#ifndef STRUCTURE_LINKED_LIST_H
# define STRUCTURE_LINKED_LIST_H
typedef struct s_list
{
	void			*node;
	struct s_list	*next;
}				t_list;
#endif