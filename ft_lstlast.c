#include "linked_lists.h"

t_stack  *ft_lstlast(t_stack *head)
{
    //fetches and  returns the last node in the list.. 
    if (head == NULL)
        return (NULL);
    while (head -> next != NULL)
    {
        head = head -> next;
    }
    return (head);
}