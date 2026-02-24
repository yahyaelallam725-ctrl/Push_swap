/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelallam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 04:38:11 by yelallam          #+#    #+#             */
/*   Updated: 2026/02/24 04:38:20 by yelallam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *head);
t_stack	*ft_pop_top(t_stack **head);
t_stack	*stack_init(int argc, char **argv, t_stack **head);
int		ft_lstsize(t_stack *head);
int		ft_isnum(char *str);
int		ft_check_dup(t_stack *head, int data);
int		is_sorted(t_stack *head);
int		find_pos(t_stack *head, int data_index);
int		range_index(t_stack *head, int min_index, int max_index);
int		closest_pos(t_stack *head, int min_index, int max_index, int head_size);
long	ft_atol(const char *nptr);
void	ft_lstadd_front(t_stack **head, t_stack *new_node);
void	ft_lstadd_back(t_stack **head, t_stack *new_node);
void	ft_lstprint(t_stack *head);
void	ft_lstfree(t_stack *head);
void	ft_swap(t_stack **head, char stack);
void	ft_rotate(t_stack **head, char stack);
void	ft_rev_rotate(t_stack **head, char stack);
void	ft_push_a(t_stack **head_b, t_stack **head_a);
void	ft_push_b(t_stack **head_a, t_stack **head_b);
void	ft_free_args(char **splitted_args);
void	sort_two(t_stack **head);
void	sort_three(t_stack **head);
void	sort_four(t_stack **head_a, t_stack **head_b);
void	sort_five(t_stack **head_a, t_stack **head_b);
void	assign_index(t_stack *head);
void	chunks_push_b(t_stack **head_a, t_stack **head_b, int size);
void	chunks_push_a(t_stack **head_a, t_stack **head_b);
char	**ft_split(char const *s, char c);

#endif
