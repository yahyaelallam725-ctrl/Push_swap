/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 23:18:03 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:07:45 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_stack **head)
{
	t_stack	*node;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	node = (*head)->next;
	if ((*head)->data < node -> data)
		return ;
	ft_swap(head, 'a');
}
