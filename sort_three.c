/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 23:30:28 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:10:08 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_it(int data_a, int data_b, int data_c, t_stack **head)
{
	if (data_a < data_b && data_b > data_c && data_c > data_a)
	{
		ft_rev_rotate(head, 'a');
		ft_swap(head, 'a');
	}
	else if (data_a > data_b && data_b < data_c && data_c > data_a)
		ft_swap(head, 'a');
	else if (data_a < data_b && data_b > data_c && data_c < data_a)
		ft_rev_rotate(head, 'a');
	else if (data_a > data_b && data_b < data_c && data_c < data_a)
		ft_rotate(head, 'a');
	else if (data_a > data_b && data_b > data_c && data_c < data_a)
	{
		ft_rotate(head, 'a');
		ft_swap(head, 'a');
	}
}

void	sort_three(t_stack **head)
{
	t_stack	*node;
	int		data_a;
	int		data_b;
	int		data_c;

	if (ft_lstsize(*head) < 3)
		return ;
	node = (*head)->next;
	data_a = (*head)->data;
	data_b = node -> data;
	data_c = (node -> next)->data;
	if (data_a < data_b && data_b < data_c)
		return ;
	sort_it(data_a, data_b, data_c, head);
}
