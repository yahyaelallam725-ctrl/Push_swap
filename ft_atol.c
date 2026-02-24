/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/10/31 12:01:56 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:04:53 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	c;
	long	sign;
	int		i;

	i = 0;
	c = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr [i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = c * 10 + nptr[i] - '0';
		i++;
	}
	return (c * sign);
}
