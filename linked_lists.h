# ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
 
t_stack	*ft_lstnew(int content);
t_stack  *ft_lstlast(t_stack *head);
void	ft_lstadd_front(t_stack **head, t_stack *new_node);
void    ft_lstprint(t_stack *head);
void    ft_lstfree(t_stack *head);
void    ft_lstadd_back(t_stack **head, t_stack *new_node);
int ft_lstsize(t_stack *head);



#endif