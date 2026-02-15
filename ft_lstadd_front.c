#include "linked_lists.h"

void	ft_lstadd_front(t_stack **head, t_stack *new_node)
{
    //adds a node at the top of the list
    new_node -> next = *head;    // Connect new node to the old first node
    *head = new_node;           // updates head to point to  new_node
}