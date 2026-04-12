/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:16:51 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/12 13:36:45 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_stack **st, t_count *count)
{
	if (!st || (*st)->next == NULL)
		return ;
	else if (ft_lstsize(*st) == 2)
	{
		if ((*st)->rank > (*st)->next->rank)
			sa(st, count);
	}
	else if (ft_lstsize(*st) == 3)
	{
		while (disorder(*st) != 0)
		{
			if ((*st)->rank > ft_lstlast(*st)->rank)
				ra(st, count);
			else if ((*st)->rank > (*st)->next->rank)
				sa(st, count);
			else if ((*st)->next->rank > ft_lstlast(*st)->rank)
				rra(st, count);
		}
	}
}

void	sort_four_five(t_stack **st1, t_stack **st2, t_count *count)
{
	if (ft_lstsize(*st1) == 5)
		pb(st1, st2, count);
	pb(st1, st2, count);
	sort_tiny(st1, count);
	while (*st2)
		insert_to_a(st1, st2, count);
}

int	find_target(t_stack **st, int n)
{
	t_stack		*temp;
	int			count;
	int			value;
	int			pos;

	temp = *st;
	count = 0;
	value = INT_MIN;
	pos = -1;
	while (temp)
	{
		if (temp->rank < n && temp->rank > value)
		{
			value = temp->rank;
			pos = count;
		}
		temp = temp->next;
		count++;
	}
	return (pos);
}

static int	cost_for_rank(t_stack **a, t_stack **b, int rank, int pos_a_idx)
{
	int	size_a;
	int	size_b;
	int	ca;
	int	cb;
	int	pos_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	pos_b = find_target(b, rank);
	if (pos_a_idx <= size_a / 2)
		ca = pos_a_idx;
	else
		ca = size_a - pos_a_idx;
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

static void	bring_to_top(t_stack **a, int pos, t_count *count)
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

static void	place_in_b(t_stack **b, int pos_b, t_count *count)
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
	int		cost;
	int		idx;

	temp = *st1;
	best_cost = INT_MAX;
	best_pos_a = 0;
	best_pos_b = 0;
	idx = 0;
	while (temp)
	{
		cost = cost_for_rank(st1, st2, temp->rank, idx);
		if (cost < best_cost)
		{
			best_cost = cost;
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

void	insertion_sort(t_stack **st1, t_stack **st2, t_count *count)
{
	if (ft_lstsize(*st1) <= 3)
		sort_tiny(st1, count);
	else if (ft_lstsize(*st1) <= 5)
		sort_four_five(st1, st2, count);
	else
	{
		pb(st1, st2, count);
		pb(st1, st2, count);
		if (*st2 && (*st2)->next && (*st2)->rank < (*st2)->next->rank)
			sb(st2, count);
		while (*st1)
			insert_to_b(st2, st1, count);
		while (*st2 && (*st2)->rank != ft_lstsize(*st2) - 1)
			rb(st2, count);
		while (*st2)
			pa(st1, st2, count);
	}
}
