/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/21 17:46:23 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:05:29 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ft_free_args(char **splitted_args)
{
	int	i;

	i = 0;
	while (splitted_args[i])
	{
		free(splitted_args[i]);
		i++;
	}
	free(splitted_args);
}
