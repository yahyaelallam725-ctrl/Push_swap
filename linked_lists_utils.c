/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:29:32 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:57:30 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> data = content;
	new_node -> next = NULL;
	return (new_node);
}

int	ft_lstsize(t_stack *head)
{
	int	count;

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

t_stack	*ft_lstlast(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head -> next != NULL)
	{
		head = head -> next;
	}
	return (head);
}

void	ft_lstfree(t_stack *head)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	while (head != NULL)
	{
		tmp = head -> next;
		free(head);
		head = tmp;
	}
}
