/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:22:44 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/11 18:27:51 by neohanya         ###   ########.fr       */
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
	while (*b)
		pa(a, b, count);
}

// int	cond_for_b(t_stack **b, int chunk_size, int i)
// {
// 	int	start;
// 	int	end;

// 	start = chunk_size * i;
// 	end = chunk_size * (i + 1);
// 	if ((*b)->rank < start + ((end - start) / 2))
// 		return (1);
// 	return (0);
// }

void	push_rotate(t_stacks *stacks, int chunk_size, int i, t_count *count)
{
	if (!(*(stacks->a)))
		return ;
	if ((*(stacks->a))->rank >= (chunk_size * i)
		&& (*(stacks->a))->rank < (chunk_size * (i + 1)))
		insert_to_b(stacks->b, stacks->a, count);
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
