/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/24 02:43:25 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 04:51:00 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static int	find_min(t_stack *stack, int size)
{
	int	min;
	int	count;

	min = stack -> data;
	count = 0;
	while (count < size)
	{
		if (stack -> data < min)
			min = stack -> data;
		stack = stack -> next;
		count++;
	}
	return (min);
}

static void	do_rotation(t_stack **head, int min, int signal)
{
	if (signal == 1)
	{
		while ((*head)->data != min)
			ft_rev_rotate(head, 'a');
	}
	else if (signal == 0)
	{
		while ((*head)->data != min)
			ft_rotate(head, 'a');
	}
}

static void	rotate_to_top(t_stack **head, int min, int size)
{
	t_stack	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (count < size)
	{
		if (tmp -> data == min)
		{
			if (count == 0)
				break ;
			else if (count > size / 2)
			{
				do_rotation(head, min, 1);
				break ;
			}
			else
			{
				do_rotation(head, min, 0);
				break ;
			}
		}
		tmp = tmp -> next;
		count++;
	}
}

static void	smallest_nums(t_stack **head_a, t_stack **head_b)
{
	int	min;

	min = find_min(*head_a, 4);
	rotate_to_top(head_a, min, 4);
	ft_push_b(head_a, head_b);
}

void	sort_four(t_stack **head_a, t_stack **head_b)
{
	if (ft_lstsize(*head_a) < 4)
		return ;
	smallest_nums(head_a, head_b);
	sort_three(head_a);
	ft_push_a(head_b, head_a);
}
