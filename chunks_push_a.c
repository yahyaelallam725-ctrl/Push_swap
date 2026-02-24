/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   chunks_push_a.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/24 02:01:25 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:47:51 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static int	find_max_index(t_stack *head)
{
	int	max;

	max = INT_MIN;
	while (head)
	{
		if (head -> index > max)
			max = head -> index;
		head = head -> next;
	}
	return (max);
}

static int	find_pos_by_index(t_stack *head, int max_index)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head -> index == max_index)
			return (pos);
		head = head -> next;
		pos++;
	}
	return (pos);
}

void	chunks_push_a(t_stack **head_a, t_stack **head_b)
{
	int	max_index;
	int	max_pos;
	int	size;
	int	i;

	while (*head_b)
	{
		max_index = find_max_index(*head_b);
		max_pos = find_pos_by_index(*head_b, max_index);
		size = ft_lstsize(*head_b);
		i = 0;
		if (max_pos <= size / 2)
		{
			while (i++ < max_pos)
				ft_rotate(head_b, 'b');
		}
		else
		{
			i = 0;
			while (i++ < size - max_pos)
				ft_rev_rotate(head_b, 'b');
		}
		ft_push_a(head_b, head_a);
	}
}
