/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:21:58 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/08 14:31:49 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(t_stack *st)
{
	int		*contents;
	int		size;
	int		i;
	t_stack	*tmp;

	tmp = st;
	size = ft_lstsize(tmp);
	contents = malloc(size * sizeof(t_stack));
	i = 0;
	while (i < size)
	{
		contents[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (contents);
}

void	sort_array(int *contents, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = i;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (contents[i] > contents[j])
			{
				tmp = contents[i];
				contents[i] = contents[j];
				contents[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ranking(t_stack *st)
{
	int		*contents;
	int		size;
	int		i;
	int		rank;
	t_stack	*cur;

	size = ft_lstsize(st);
	contents = get_array(st);
	sort_array(contents, size);
	i = 0;
	rank = 0;
	cur = st;
	while (cur)
	{
		i = 0;
		rank = 0;
		while (i < size)
		{
			if (contents[i++] < cur->content)
				rank++;
		}
		cur->rank = rank;
		cur = cur->next;
	}
	free(contents);
}
