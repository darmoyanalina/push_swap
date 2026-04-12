/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:48:22 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/12 17:00:51 by adarmoya         ###   ########.fr       */
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
	return (ca + cb);
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

void	rotate_to_max(t_stack **b, int size, t_count *count)
{
	int	pos;

	pos = find_max_pos(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b, count);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b, count);
	}
}

void	place_in_b(t_stack **b, int pos_b, t_count *count)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos_b == -1)
	{
		rotate_to_max(b, size, count);
		return ;
	}
	if (pos_b <= size / 2)
		while (pos_b-- > 0)
			rb(b, count);
	else
	{
		pos_b = size - pos_b;
		while (pos_b-- > 0)
			rrb(b, count);
	}
}

void	insert_to_b(t_stack **st2, t_stack **st1, t_count *count)
{
	t_stack	*tmp;
	int		best[4];

	tmp = *st1;
	best[0] = INT_MAX;
	best[1] = 0;
	best[2] = 0;
	best[3] = 0;
	while (tmp)
	{
		update_best(st1, st2, tmp, best);
		tmp = tmp->next;
		best[3]++;
	}
	bring_to_top(st1, best[1], count);
	place_in_b(st2, best[2], count);
	pb(st1, st2, count);
}
