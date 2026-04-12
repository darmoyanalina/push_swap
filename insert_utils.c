/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:03:16 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/12 17:00:17 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_to_a(t_stack **st1, t_stack **st2, t_count *count)
{
	int	pos;
	int	save;

	if (!(*st1) || (*st2)->rank < (*st1)->rank)
	{
		pa(st1, st2, count);
		return ;
	}
	pos = find_target(st1, (*st2)->rank);
	if (pos == -1)
	{
		pa(st1, st2, count);
		ra(st1, count);
		return ;
	}
	save = pos;
	while (pos-- > 0)
		ra(st1, count);
	pa(st1, st2, count);
	while (save-- > 0)
		rra(st1, count);
}

void	update_best(t_stack **a, t_stack **b, t_stack *tmp, int *best)
{
	int	cost;

	cost = cost_for_rank(a, b, tmp->rank, best[3]);
	if (cost < best[0])
	{
		best[0] = cost;
		best[1] = best[3];
		best[2] = find_target(b, tmp->rank);
	}
}

void	insert_to_b_hybrid(t_stacks *stacks, int chunk, int i, t_count *count)
{
	int	rank;

	rank = (*(stacks->a))->rank;
	pb(stacks->a, stacks->b, count);
	if (rank < chunk * i + chunk / 2)
		rb(stacks->b, count);
	else if ((*(stacks->b))->next
		&& (*(stacks->b))->rank < (*(stacks->b))->next->rank)
		sb(stacks->b, count);
}

int	find_max_pos(t_stack *b)
{
	int		max;
	int		pos;
	int		i;

	max = b->rank;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->rank > max)
		{
			max = b->rank;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}
