/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:28:40 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:55:42 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(t_stack **head, char stack)
{
	t_stack	*node_1;
	t_stack	*node_2;
	t_stack	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	node_1 = *head;
	*head = (*head)->next;
	node_2 = *head;
	tmp = node_2 -> next;
	node_2 -> next = node_1;
	node_1 -> next = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
}
