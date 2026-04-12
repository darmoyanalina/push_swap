/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:22:44 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/12 11:39:41 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int max_index)
{
	if (max_index <= 20)
		return (max_index / 2);
	else if (max_index <= 100)
		return (11);
	else if (max_index <= 500)
		return (34);
	else
		return (max_index / 14);
}

void	back_to_a(t_stack **a, t_stack **b, t_count *count)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		pos = find_max_pos(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, count);
		}
		else
		{
			while (pos++ < size)
				rrb(b, count);
		}
		pa(a, b, count);
	}
}

void	push_rotate(t_stacks *stacks, int chunk_size, int i, t_count *count)
{
	int	rank;

	if (!(*(stacks->a)))
		return ;
	rank = (*(stacks->a))->rank;
	if (rank >= chunk_size * i && rank < chunk_size * (i + 1))
		insert_to_b_hybrid(stacks, chunk_size, i, count);
	else
		ra(stacks->a, count);
}

void	medium_sort(t_stacks *stacks, t_count *count)
{
	int	chunk_size;
	int	i;
	int	j;
	int	size;

	chunk_size = get_chunk_size(ft_lstsize(*(stacks->a)));
	size = ft_lstsize(*(stacks->a));
	if (size <= 5)
	{
		insertion_sort(stacks->a, stacks->b, count);
		return ;
	}
	i = 0;
	j = 0;
	while (i < size / chunk_size + 1 && (*(stacks->a)))
	{
		j = 0;
		while (j < size && (*(stacks->a)))
		{
			push_rotate(stacks, chunk_size, i, count);
			j++;
		}
		i++;
	}
	back_to_a(stacks->a, stacks->b, count);
}
