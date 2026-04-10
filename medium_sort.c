/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:22:44 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 20:08:53 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int max_index)
{
	if (max_index <= 20)
		return (max_index / 2);
	else if (max_index <= 100)
		return (16);
	else if (max_index <= 500)
		return (38);
	else
		return (max_index / 13);
}

void	back_to_a(t_stack **a, t_stack **b, t_count *count)
{
	int	size;

	size = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b)->rank == size)
		{
			pa(a, b, count);
			size--;
		}
		else if (find_target(b, size) < size / 2)
		{
			while ((*b)->rank != size)
				rb(b, count);
		}
		else
		{
			while ((*b)->rank != size)
				rrb(b, count);
		}
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_count *count)
{
	int	chunk_size;
	int	i;
	int	j;
	int	size;
	int	pos;

	chunk_size = get_chunk_size(ft_lstsize(*a));
	if ((size = ft_lstsize(*a)) <= 5)
	{
		insertion_sort(a, b, count);
		return ;
	}
	i = 0;
	j = 0;
	pos = 0;
	while (i < size / chunk_size + 1 && (*a))
	{
		j = 0;
		while (j < size && (*a))
		{
			if ((*a)->rank >= (chunk_size * i) && (*a)->rank < (chunk_size * (i + 1)))
			{
				pb(a, b, count);
				if ((*b)->rank < (chunk_size * (i + 1)) / 2)
					rb(b, count);
			}
			else
				ra(a, count);
			j++;
		}
		i++;
	}
	back_to_a(a, b, count);
}
