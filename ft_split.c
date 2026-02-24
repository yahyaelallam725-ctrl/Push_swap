/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelallam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/11/03 11:46:27 by yelallam		  #+#	#+#			 */
/*   Updated: 2025/11/09 04:03:15 by yelallam		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wc(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (count);
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, int start, int end)
{
	char	*arr;
	int		i;

	arr = malloc(end - start + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (start < end && s[start] != '\0')
	{
		arr[i] = s[start];
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

static char	**ft_memfree(char **strs, int l_arr)
{
	int	i;

	i = 0;
	while (i < l_arr)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**ft_fill_word(char const *s, char c, char **arr)
{
	char	**strs;

	int i, (start), (end);
	strs = arr;
	end = 0;
	i = 0;
	while (s[end])
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (start < end)
		{
			*arr = ft_word_dup(s, start, end);
			if (*arr == NULL)
				return (ft_memfree(strs, i));
			arr++;
			i++;
		}
	}
	*arr = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		l_arr;

	if (!s)
		return (NULL);
	l_arr = ft_wc(s, c);
	arr = malloc((l_arr + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_fill_word(s, c, arr));
}
