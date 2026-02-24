/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/23 20:00:00 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:15:33 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	assign_index(t_stack *head)
{
	t_stack	*node;
	t_stack	*compare;
	int		count;

	node = head;
	while (node)
	{
		compare = head;
		count = 0;
		while (compare)
		{
			if (compare -> data < node -> data)
				count++;
			compare = compare -> next;
		}
		node -> index = count;
		node = node -> next;
	}
}
