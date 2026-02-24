/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:20:57 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:28:47 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*saved_head;

	if (*head == NULL)
	{
		*head = new_node;
		new_node -> next = NULL;
		return ;
	}
	saved_head = *head;
	while (saved_head -> next != NULL)
		saved_head = saved_head -> next;
	saved_head -> next = new_node;
	new_node -> next = NULL;
}
