/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/23 04:09:38 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:13:13 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack *head)
{
	while (head && head -> next)
	{
		if (head -> data < head -> next -> data)
			head = head -> next;
		else if (head -> data > head -> next -> data)
			return (0);
	}
	return (1);
}
