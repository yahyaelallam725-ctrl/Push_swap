/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pop_top.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/17 13:26:55 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 10:51:51 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_pop_top(t_stack **head)
{
	t_stack	*copy;

	if (*head == NULL)
		return (NULL);
	copy = *head;
	*head = (*head)->next;
	copy -> next = NULL;
	return (copy);
}
