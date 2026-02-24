/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:26:33 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:49:14 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node_a;

	if (*head_a == NULL)
		return ;
	node_a = ft_pop_top(head_a);
	ft_lstadd_front(head_b, node_a);
	write(1, "pb\n", 3);
}
