/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/20 17:52:18 by yelallam		  #+#	#+#			 */
/*   Updated: 2026/02/24 11:01:51 by yelallam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

static int	parsing(char *splitted_arg, t_stack **head)
{
	long	num;

	if (!ft_isnum(splitted_arg))
		return (0);
	num = ft_atol(splitted_arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (ft_check_dup(*head, (int)num))
		return (0);
	ft_lstadd_back(head, ft_lstnew((int)num));
	return (1);
}

static void	cleanup(t_stack **head, char **splitted_args)
{
	if (head && *head)
		ft_lstfree(*head);
	if (splitted_args)
		ft_free_args(splitted_args);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*stack_init(int argc, char **argv, t_stack **head)
{
	char	**splitted_args;
	int		i;
	int		j;

	if (argc < 2)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			cleanup(head, NULL);
		splitted_args = ft_split(argv[i], ' ');
		if (!splitted_args || !splitted_args[0])
			cleanup(head, splitted_args);
		j = 0;
		while (splitted_args[j])
		{
			if (parsing(splitted_args[j], head) == 0)
				cleanup(head, splitted_args);
			j++;
		}
		ft_free_args(splitted_args);
		i++;
	}
	return (*head);
}
