/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:26:43 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:49:58 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push_a(t_stack **head_b, t_stack **head_a)
{
	t_stack	*node_b;

	if (*head_b == NULL)
		return ;
	node_b = ft_pop_top(head_b);
	ft_lstadd_front(head_a, node_b);
	write(1, "pa\n", 3);
}
