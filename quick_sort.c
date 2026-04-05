/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:37:39 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/05 20:51:11 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_val(t_stack *st, int size)
{
	int		sum;
	int		i;
	t_stack	*piv;

	piv = st;
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += piv->rank;
		piv = piv->next;
		i++;
	}
	return (sum / i);
}

void	sort_b(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	pivot;
	int	rotate_count;
	int	push_count;

	i = 0;
	pivot = pivot_val(*b, size);
	rotate_count = 0;
	push_count = 0;
	if (size <= 3)
	{
		sort_tiny_quick_rev(a, b, size);
		while (size--)
			pa(a, b);
		return ;
	}
	while (i < size)
	{
		if ((*b)->rank > pivot)
		{
			pa(a, b);
			push_count++;
		}
		else
		{
			rb(b);
			rotate_count++;
		}
		i++;
	}
	write(1, "bbbb\n", 5);
	printf("%d %d\n", push_count, size);
	while (rotate_count--)
		rrb(b);
	sort_b(a, b, size - push_count);
	sort_a(a, b, push_count);
}

void	sort_a(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	pivot;
	int	rotate_count;
	int	push_count;

	i = 0;
	printf("size = %d\n", size);
	pivot = pivot_val(*a, size);
	rotate_count = 0;
	push_count = 0;
	if (size <= 3)
	{
		sort_tiny_quick(a, b, size);
		return ;
	}
	while (i < size)
	{
		if ((*a)->rank <= pivot)
		{
			pb(a, b);
			push_count++;
		}
		else
		{
			ra(a);
			rotate_count++;
		}
		i++;
	}
	write(1, "aaaa\n", 5);
	printf("i = %d  %d %d %d\n", i, rotate_count, push_count, size);
	while (rotate_count--)
	{
		write (1, "loop\n", 5);
		rra(a);
	}
	sort_a(a, b, size - push_count);
	sort_b(a, b, push_count);
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (!disorder(*a) || !(*a)->next)
		return ;
	sort_a(a, b, size);
}
