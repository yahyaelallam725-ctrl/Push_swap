/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/23 20:49:55 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:16:01 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

int	find_pos(t_stack *head, int data_index)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head -> index == data_index)
			return (pos);
		head = head -> next;
		pos++;
	}
	return (-1);
}
