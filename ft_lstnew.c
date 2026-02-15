#include "linked_lists.h"

t_stack	*ft_lstnew(int content)
{
	//takes a data as an input and returns a pointer to the new made node
	t_stack *new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> data = content;
	new_node -> next = NULL;
	return (new_node);
}