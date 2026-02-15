#include "linked_lists.h"

void    ft_lstprint(t_stack  *head)
{
    //prints the elements of the linked list..
    if (head == NULL)
        return ;
    while(head != NULL)
    {
        printf("%d\n", head -> data);
        head = head -> next;
    }
}

/*int main()
{
    t_stack *head = NULL;
    
    ft_lstadd_back(&head, ft_lstnew(3));
    ft_lstadd_back(&head, ft_lstnew(2));
    ft_lstadd_back(&head, ft_lstnew(1));
    ft_lstprint(head);
    printf ("%d\n", ft_lstsize(head));  // Should print: 1, 2, 3
    ft_lstfree(head);   // Clean up all nodes 
}*/