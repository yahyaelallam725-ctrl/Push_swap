/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   range_index.c                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/23 21:01:08 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:41:34 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

int	range_index(t_stack *head, int min_index, int max_index)
{
	while (head)
	{
		if (head -> index >= min_index && head -> index <= max_index)
			return (1);
		head = head -> next;
	}
	return (0);
}
