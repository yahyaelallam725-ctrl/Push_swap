#include "linked_lists.h"

void    ft_lstadd_back(t_stack **head, t_stack *new_node)
{
    //adding a node to the end of the list
    t_stack *saved_head;

    if (*head == NULL)
    {
        *head = new_node;
        new_node -> next = NULL;
        return ;
    }
    saved_head = *head;
    while (saved_head -> next != NULL)
    {
        saved_head = saved_head -> next; 
    }
    saved_head -> next = new_node;
    new_node -> next = NULL;
}