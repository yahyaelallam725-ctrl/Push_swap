#include "linked_lists.h"

void    ft_lstfree(t_stack *head)
{
    //a function that traverses the list while freeing each node in the list
    t_stack  *tmp;
    
    if (head == NULL)
        return ;
    while (head != NULL)
    {
        tmp = head -> next;
        free(head);
        head = tmp;
    }
}