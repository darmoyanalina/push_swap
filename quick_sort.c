/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:37:39 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/08 21:04:29 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stacks *stacks, int start, int end, t_count *count)
{
	int	pivot;
	int	i;
	int	rotate_count;

	pivot = (start + end) / 2;
	i = (end - start) + 1;
	rotate_count = 0;
	while (i--)
	{
		if ((*(stacks->a))->rank <= pivot)
			pb(stacks->a, stacks->b, count);
		else
		{
			rotate_count++;
			ra(stacks->a, count);
		}
	}
	while (rotate_count--)
		rra(stacks->a, count);
	return (pivot);
}

void	quick_sort(t_stacks *stacks, int start, int end, t_count *count)
{
	int	pivot;

	if (!disorder(*(stacks->a)) || end <= start)
		return ;
	pivot = sort(stacks, start, end, count);
	quick_sort(stacks, pivot + 1, end, count);
	while (*(stacks->b) && (*(stacks->b))->rank >= start)
		pa(stacks->a, stacks->b, count);
	quick_sort(stacks, start, pivot, count);
}
