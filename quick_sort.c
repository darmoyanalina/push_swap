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

int	sort(t_stack **a, t_stack **b, int start, int end)
{
	int	pivot;
	int	i;
	int	rotate_count;

	pivot = (start + end) / 2;
	i = (end - start) + 1;
	rotate_count = 0;
	while (i--)
	{
		if ((*a)->rank <= pivot)
			pb(a, b);
		else
		{
			rotate_count++;
			ra(a);
		}
	}
	while (rotate_count--)
		rra(a);
	return (pivot);
}

void	quick_sort(t_stack **a, t_stack **b, int start, int end)
{
	int	pivot;

	if (!disorder(*a) || end <= start)
		return ;
	pivot = sort(a, b, start, end);
	quick_sort(a, b, pivot + 1, end);
	while (*b && (*b)->rank >= start)
		pa(a, b);
	quick_sort(a, b, start, pivot);
}
