#include "linked_lists.h"

int ft_lstsize(t_stack *head)
{
    //traverses and counts the number of nodes in the list..
    int count;

    if (head == NULL)
        return (0);
    count = 0;
    while (head != NULL)
    {
        head = head -> next;
        count++;
    }
    return (count);
}