/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:48:22 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/12 13:50:47 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_for_rank(t_stack **a, t_stack **b, int rank, int idx)
{
	int	size_a;
	int	size_b;
	int	ca;
	int	cb;
	int	pos_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	pos_b = find_target(b, rank);
	if (idx <= size_a / 2)
		ca = idx;
	else
		ca = size_a - idx;
	if (pos_b == -1)
		cb = 0;
	else if (pos_b <= size_b / 2)
		cb = pos_b;
	else
		cb = size_b - pos_b;
	if (ca > cb)
		return (ca);
	return (cb);
}

void	bring_to_top(t_stack **a, int pos, t_count *count)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a, count);
	}
	else
	{
		i = size - pos;
		while (i-- > 0)
			rra(a, count);
	}
}

void	place_in_b(t_stack **b, int pos_b, t_count *count)
{
	int	size;
	int	i;

	if (pos_b == -1)
		return ;
	size = ft_lstsize(*b);
	if (pos_b <= size / 2)
	{
		i = 0;
		while (i++ < pos_b)
			rb(b, count);
	}
	else
	{
		i = size - pos_b;
		while (i-- > 0)
			rrb(b, count);
	}
}

void	insert_to_b(t_stack **st2, t_stack **st1, t_count *count)
{
	t_stack	*temp;
	int		best_cost;
	int		best_pos_a;
	int		best_pos_b;
	int		idx;

	temp = *st1;
	best_cost = INT_MAX;
	best_pos_a = 0;
	best_pos_b = 0;
	idx = 0;
	while (temp)
	{
		if (cost_for_rank(st1, st2, temp->rank, idx) < best_cost)
		{
			best_cost = cost_for_rank(st1, st2, temp->rank, idx);
			best_pos_a = idx;
			best_pos_b = find_target(st2, temp->rank);
		}
		temp = temp->next;
		idx++;
	}
	bring_to_top(st1, best_pos_a, count);
	place_in_b(st2, best_pos_b, count);
	pb(st1, st2, count);
}
