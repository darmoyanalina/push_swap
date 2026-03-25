/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:18:36 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/25 18:19:14 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] && s[j] != c)
		{
			count++;
			j++;
		}
		while (s[j] != c && s[j])
			j++;
		while (s[j] == c && s[j])
			j++;
	}
	return (count);
}

static void	init(char const *str, char c, char **array, int size)
{
	int	j;
	int	i;
	int	s;

	j = 0;
	i = 0;
	s = 0;
	while (j < size)
	{
		s = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			array[j][s++] = str[i++];
		array[j++][s] = '\0';
	}
	array[size] = NULL;
}

static void	free_space(char **array, int k, int *a)
{
	int	i;

	i = 0;
	while (i < k)
		free(array[i++]);
	free(array);
	free(a);
}

static int	*count_length(const char *s, char c, int size)
{
	int	i;
	int	j;
	int	k;
	int	*a;

	i = 0;
	j = 0;
	k = 0;
	a = malloc(size * sizeof(int));
	if (!a)
		return (NULL);
	while (k < size)
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		a[k++] = j;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	int		j;
	int		*a;
	char	**array;

	size = count_words(s, c);
	j = 0;
	a = count_length(s, c, size);
	array = malloc((size + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (j < size)
	{
		array[j] = malloc(a[j] + 1);
		if (!array[j])
		{
			free_space(array, j++, a);
			return (NULL);
		}
		j++;
	}
	init(s, c, array, size);
	free(a);
	return (array);
}
