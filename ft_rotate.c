/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:28:09 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:52:47 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate(t_stack **head, char stack)
{
	t_stack	*node_1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	node_1 = ft_pop_top(head);
	ft_lstadd_back(head, node_1);
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}
