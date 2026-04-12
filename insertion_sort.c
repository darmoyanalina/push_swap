/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:16:51 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/12 13:47:21 by neohanya         ###   ########.fr       */
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
	t_stack	*temp;
	int		count;
	int		value;
	int		pos;

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
