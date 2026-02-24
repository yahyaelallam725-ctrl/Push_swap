/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   chunks_push_b.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/24 00:25:31 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:19:13 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate_to_top_a(t_stack **head_a, int target_pos, int size)
{
	int	i;

	i = 0;
	if (target_pos <= size / 2)
	{
		while (i++ < target_pos)
			ft_rotate(head_a, 'a');
	}
	else
	{
		while (i++ < size - target_pos)
			ft_rev_rotate(head_a, 'a');
	}
}

static void	process_chunk(t_stack **head_a, t_stack **head_b,
		int min_index, int max_index)
{
	int	target_pos;
	int	size;
	int	chunk_size;

	chunk_size = max_index - min_index + 1;
	while (range_index(*head_a, min_index, max_index))
	{
		size = ft_lstsize(*head_a);
		target_pos = closest_pos(*head_a, min_index, max_index, size);
		rotate_to_top_a(head_a, target_pos, size);
		ft_push_b(head_a, head_b);
		if ((*head_b)->index < min_index + chunk_size / 2)
			ft_rotate(head_b, 'b');
	}
}

void	chunks_push_b(t_stack **head_a, t_stack **head_b, int size)
{
	int	chunk_size;
	int	current_chunk;
	int	min_index;
	int	max_index;
	int	chunks_count;

	if (size <= 100)
		chunks_count = 5;
	else
		chunks_count = 11;
	chunk_size = size / chunks_count;
	current_chunk = 0;
	while (current_chunk < chunks_count)
	{
		min_index = current_chunk * chunk_size;
		if (current_chunk == chunks_count - 1)
			max_index = size - 1;
		else
			max_index = min_index + chunk_size - 1;
		process_chunk(head_a, head_b, min_index, max_index);
		current_chunk++;
	}
}
