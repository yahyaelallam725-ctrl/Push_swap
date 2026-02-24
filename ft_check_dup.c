/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 17:46:37 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:06:18 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

int	ft_check_dup(t_stack *head, int data)
{
	while (head)
	{
		if (head -> data == data)
			return (1);
		head = head -> next;
	}
	return (0);
}
