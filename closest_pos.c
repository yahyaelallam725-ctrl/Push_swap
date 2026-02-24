/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   closest_pos.c                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/24 00:25:42 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:43:22 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

int	closest_pos(t_stack *head, int min_index, int max_index, int head_size)
{
	int	pos;
	int	cost;
	int	best_pos;
	int	best_cost;

	pos = 0;
	best_pos = -1;
	best_cost = INT_MAX;
	while (head)
	{
		if (head -> index >= min_index && head -> index <= max_index)
		{
			cost = pos;
			if (head_size - pos < cost)
				cost = head_size - pos;
			if (cost < best_cost)
			{
				best_cost = cost;
				best_pos = pos;
			}
		}
		head = head -> next;
		pos++;
	}
	return (best_pos);
}
