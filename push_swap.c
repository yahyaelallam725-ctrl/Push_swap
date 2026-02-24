/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/07 11:21:00 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 04:31:25 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static void	all_sorting(t_stack **head_a, t_stack **head_b)
{
	int	size;

	if (is_sorted(*head_a))
	{
		ft_lstfree(*head_a);
		return ;
	}
	size = ft_lstsize(*head_a);
	assign_index(*head_a);
	if (size == 2)
		sort_two(head_a);
	else if (size == 3)
		sort_three(head_a);
	else if (size == 4)
		sort_four(head_a, head_b);
	else if (size == 5)
		sort_five(head_a, head_b);
	else
	{
		chunks_push_b(head_a, head_b, size);
		chunks_push_a(head_a, head_b);
	}
	ft_lstfree(*head_a);
	if (*head_b)
		ft_lstfree(*head_b);
}

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (ac < 2)
		return (0);
	stack_init(ac, av, &head_a);
	all_sorting(&head_a, &head_b);
	return (0);
}
