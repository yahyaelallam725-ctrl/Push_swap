/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:28:20 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:53:45 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rev_rotate(t_stack **head, char stack)
{
	t_stack	*last_node;
	t_stack	*copy;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_node = ft_lstlast(*head);
	copy = *head;
	while (copy -> next -> next != NULL)
		copy = copy -> next;
	copy -> next = NULL;
	ft_lstadd_front(head, last_node);
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}
